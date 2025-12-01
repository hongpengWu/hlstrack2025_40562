#ifndef _XF_SOLVER_UKF_HPP_
#define _XF_SOLVER_UKF_HPP_

#include <cmath>
#include <cstring>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include "cholesky.hpp"

namespace xf {
namespace solver {

template <int N>
struct UkfWeights {
    float Wm[2 * N + 1];
    float Wc[2 * N + 1];
    float cscale;
    float Wc_sqrt[2 * N + 1];
};

template <int N>
void ukf_compute_weights(UkfWeights<N>& w) {
    float alpha = 0.3f;
    float ki = 1.0f;
    float beta = 2.0f;
    float lambda = alpha * alpha * (N + ki) - N;
    float c = N + lambda;
    w.Wm[0] = lambda / c;
    for (int i = 1; i < 2 * N + 1; i++) w.Wm[i] = 0.5f / c;
    for (int i = 0; i < 2 * N + 1; i++) w.Wc[i] = w.Wm[i];
    w.Wc[0] = w.Wc[0] + (1 - alpha * alpha + beta);
    w.cscale = std::sqrt(c);
    for (int k = 0; k < 2 * N + 1; k++) w.Wc_sqrt[k] = std::sqrt(std::fabs(w.Wc[k]));
}

template <int N>
inline void f_state(const float x[N], float y[N]) {
    y[0] = x[1];
    y[1] = x[2];
    y[2] = 0.05f * x[0] * (x[1] + x[2]);
}

template <int N, int M>
inline void h_meas(const float x[N], float z[M]) {
    for (int i = 0; i < M; i++) z[i] = x[i];
}

template <int N>
inline void mat_add_diag(float A[N][N], float d) {
    for (int i = 0; i < N; i++) A[i][i] += d;
}

template <int N, int K>
inline void outer_add_weighted(const float v[N], const float w, float P[N][N]) {
    for (int i = 0; i < N; i++) {
#pragma HLS UNROLL
        for (int j = 0; j < N; j++) {
#pragma HLS UNROLL
            P[i][j] += w * v[i] * v[j];
        }
    }
}

template <int N>
inline void mat_zero(float A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) A[i][j] = 0.0f;
    }
}

template <int N>
inline void mat_copy(const float A[N][N], float B[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) B[i][j] = A[i][j];
    }
}

template <int N>
inline void mat_mul(const float A[N][N], const float B[N][N], float C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float s = 0.0f;
            for (int k = 0; k < N; k++) s += A[i][k] * B[k][j];
            C[i][j] = s;
        }
    }
}

template <int N>
inline void mat_mul_nm(const float A[N][N], const float B[N][N], int n, int m, float C[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            float s = 0.0f;
            for (int k = 0; k < n; k++) s += A[i][k] * B[k][j];
            C[i][j] = s;
        }
    }
}

template <int M>
inline void mat_identity(float I[M][M]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) I[i][j] = (i == j) ? 1.0f : 0.0f;
    }
}

template <int M>
inline void mat_inverse_gauss(const float A[M][M], float invA[M][M]) {
    float aug[M][2 * M];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) aug[i][j] = A[i][j];
        for (int j = 0; j < M; j++) aug[i][M + j] = (i == j) ? 1.0f : 0.0f;
    }
    for (int col = 0; col < M; col++) {
        float piv = aug[col][col];
        float invp = 1.0f / piv;
        for (int j = 0; j < 2 * M; j++) aug[col][j] *= invp;
        for (int i = 0; i < M; i++) {
            if (i == col) continue;
            float factor = aug[i][col];
            for (int j = 0; j < 2 * M; j++) aug[i][j] -= factor * aug[col][j];
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) invA[i][j] = aug[i][M + j];
    }
}

template <int N, int M>
inline void mat_mul_nm2(const float A[N][M], const float B[M][M], float C[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            float s = 0.0f;
            for (int k = 0; k < M; k++) s += A[i][k] * B[k][j];
            C[i][j] = s;
        }
    }
}

template <int N>
inline void transpose(const float A[N][N], float AT[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) AT[j][i] = A[i][j];
    }
}

template <int N, int M>
inline void transpose_nm(const float A[N][M], float AT[M][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) AT[j][i] = A[i][j];
    }
}

template <int N>
inline void make_sigma_points(const float x[N], const float S[N][N], const UkfWeights<N>& w,
                              float X[N][2 * N + 1]) {
    float A[N][N];
#pragma HLS PIPELINE II=1
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            A[r][c] = w.cscale * S[c][r];
        }
    }
    for (int i = 0; i < N; i++) X[i][0] = x[i];
#pragma HLS ARRAY_PARTITION variable=X complete dim=2
    for (int k = 0; k < N; k++) {
#pragma HLS PIPELINE II=1
        for (int i = 0; i < N; i++) {
            X[i][1 + k] = x[i] + A[i][k];
            X[i][1 + N + k] = x[i] - A[i][k];
        }
    }
}

template <int N, int M>
inline void ukf_ut_process(const float X[N][2 * N + 1], const UkfWeights<N>& w, float q, float x1[N],
                           float S1[N][N], float X2[N][2 * N + 1], float X1[N][2 * N + 1]) {
    float Y[N][2 * N + 1];
#pragma HLS ARRAY_PARTITION variable=Y complete dim=2
#pragma HLS ARRAY_PARTITION variable=X2 complete dim=2
#pragma HLS ARRAY_PARTITION variable=X1 complete dim=2
#pragma HLS ARRAY_PARTITION variable=X complete dim=2
    for (int k = 0; k < 2 * N + 1; k++) {
#pragma HLS PIPELINE II=1
        float tmp[N];
        for (int i = 0; i < N; i++) tmp[i] = X[i][k];
        float ytmp[N];
        f_state<N>(tmp, ytmp);
        for (int i = 0; i < N; i++) Y[i][k] = ytmp[i];
    }
    for (int i = 0; i < N; i++) x1[i] = 0.0f;
    for (int k = 0; k < 2 * N + 1; k++) {
#pragma HLS PIPELINE II=1
        for (int i = 0; i < N; i++) x1[i] += w.Wm[k] * Y[i][k];
    }
    for (int k = 0; k < 2 * N + 1; k++) {
#pragma HLS PIPELINE II=1
        for (int i = 0; i < N; i++) X2[i][k] = Y[i][k] - x1[i];
    }
    for (int k = 0; k < 2 * N + 1; k++) {
#pragma HLS PIPELINE II=1
        for (int i = 0; i < N; i++) X1[i][k] = Y[i][k];
    }
    float P[N][N];
    mat_zero<N>(P);
    for (int k = 0; k < 2 * N + 1; k++) {
        float wk = w.Wc_sqrt[k];
        float v[N];
        for (int i = 0; i < N; i++) v[i] = wk * X2[i][k];
        outer_add_weighted<N, 2 * N + 1>(v, 1.0f, P);
    }
    mat_add_diag<N>(P, q * q);
    float Lmat[N][N];
    xf::solver::choleskyTop<true, N, xf::solver::choleskyTraits<true, N, float, float>, float, float>(P, Lmat);
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) S1[r][c] = Lmat[r][c];
    }
}

template <int N, int M>
inline void ukf_ut_meas(const float X1[N][2 * N + 1], const UkfWeights<N>& w, float r, float z1[M],
                        float S2[M][M], float Z2[M][2 * N + 1]) {
    float Z[M][2 * N + 1];
#pragma HLS ARRAY_PARTITION variable=Z complete dim=2
#pragma HLS ARRAY_PARTITION variable=Z2 complete dim=2
    for (int k = 0; k < 2 * N + 1; k++) {
#pragma HLS PIPELINE II=1
        float tmp[N];
        for (int i = 0; i < N; i++) tmp[i] = X1[i][k];
        float ztmp[M];
        h_meas<N, M>(tmp, ztmp);
        for (int i = 0; i < M; i++) Z[i][k] = ztmp[i];
    }
    for (int i = 0; i < M; i++) z1[i] = 0.0f;
    for (int k = 0; k < 2 * N + 1; k++) {
#pragma HLS PIPELINE II=1
        for (int i = 0; i < M; i++) z1[i] += w.Wm[k] * Z[i][k];
    }
    for (int k = 0; k < 2 * N + 1; k++) {
#pragma HLS PIPELINE II=1
        for (int i = 0; i < M; i++) Z2[i][k] = Z[i][k] - z1[i];
    }
    float P[M][M];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) P[i][j] = 0.0f;
    }
    for (int k = 0; k < 2 * N + 1; k++) {
        float wk = w.Wc_sqrt[k];
        float v[M];
        for (int i = 0; i < M; i++) v[i] = wk * Z2[i][k];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) P[i][j] += v[i] * v[j];
        }
    }
    for (int i = 0; i < M; i++) P[i][i] += r * r;
    float Lmat[M][M];
    xf::solver::choleskyTop<true, M, xf::solver::choleskyTraits<true, M, float, float>, float, float>(P, Lmat);
    for (int r0 = 0; r0 < M; r0++) {
        for (int c0 = 0; c0 < M; c0++) S2[r0][c0] = Lmat[r0][c0];
    }
}

template <int N, int M>
inline void cross_cov(const float X2[N][2 * N + 1], const float Z2[M][2 * N + 1], const UkfWeights<N>& w,
                      float P12[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) P12[i][j] = 0.0f;
    }
#pragma HLS ARRAY_PARTITION variable=X2 complete dim=2
#pragma HLS ARRAY_PARTITION variable=Z2 complete dim=2
    for (int k = 0; k < 2 * N + 1; k++) {
#pragma HLS PIPELINE II=1
        float wk = w.Wc[k];
        for (int i = 0; i < N; i++) {
#pragma HLS UNROLL
            for (int j = 0; j < M; j++) P12[i][j] += wk * X2[i][k] * Z2[j][k];
        }
    }
}

template <int N>
inline void cholupdate_upper(float R[N][N], const float x_in[N], bool downdate) {
    float x[N];
    for (int i = 0; i < N; i++) x[i] = x_in[i];
    float sign = downdate ? -1.0f : 1.0f;
    for (int k = 0; k < N; k++) {
        float rkk = R[k][k];
        float rkksq = rkk * rkk + sign * x[k] * x[k];
        if (rkksq < 0) rkksq = 0;
        float r = std::sqrt(rkksq);
        float c = r / rkk;
        float s = x[k] / rkk;
        R[k][k] = r;
        for (int j = k + 1; j < N; j++) {
            float rkj = R[k][j];
            float t = (rkj + sign * s * x[j]) / c;
            x[j] = c * x[j] - s * rkj;
            R[k][j] = t;
        }
    }
}

template <int N, int M>
inline void ukf_update(const float x1[N], const float z[M], const float z1[M], const float S1[N][N], const float S2[M][M],
                       const float P12[N][M], float x[N], float S[N][N]) {
    float K[N][M];
    float U[N][M];
#pragma HLS ARRAY_PARTITION variable=K complete dim=2
#pragma HLS ARRAY_PARTITION variable=U complete dim=2
#pragma HLS ARRAY_PARTITION variable=S2 complete dim=2
#pragma HLS ARRAY_PARTITION variable=P12 complete dim=2
    float inv_diag[M];
#pragma HLS ARRAY_PARTITION variable=inv_diag complete dim=1
    for (int j = 0; j < M; j++) inv_diag[j] = 1.0f / S2[j][j];
    for (int i = 0; i < N; i++) {
#pragma HLS PIPELINE II=1
        for (int j = 0; j < M; j++) {
            float s = 0.0f;
#pragma HLS UNROLL
            for (int k = 0; k < j; k++) s += S2[j][k] * U[i][k];
            U[i][j] = (P12[i][j] - s) * inv_diag[j];
        }
        for (int j = M - 1; j >= 0; j--) {
            float s2 = 0.0f;
#pragma HLS UNROLL
            for (int k = j + 1; k < M; k++) s2 += S2[k][j] * K[i][k];
            K[i][j] = (U[i][j] - s2) * inv_diag[j];
        }
    }
    float innov[M];
    for (int i = 0; i < M; i++) innov[i] = z[i] - z1[i];
    for (int i = 0; i < N; i++) {
        float s = 0.0f;
        for (int j = 0; j < M; j++) s += K[i][j] * innov[j];
        x[i] = x1[i] + s;
    }
    float R[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) R[i][j] = S1[j][i];
    }
    for (int col = 0; col < M; col++) {
        float ucol[N];
        for (int i = 0; i < N; i++) ucol[i] = 0.0f;
        for (int k = 0; k < M; k++) {
            for (int i = 0; i < N; i++) ucol[i] += K[i][k] * S2[col][k];
        }
        cholupdate_upper<N>(R, ucol, true);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) S[i][j] = R[j][i];
    }
}

template <int N, int M>
void ukf_step(const float z[M], float q, float r, float x_in[N], float S_in[N][N], float x_out[N], float S_out[N][N]) {
    UkfWeights<N> w;
    ukf_compute_weights<N>(w);
    float X[N][2 * N + 1];
#pragma HLS ARRAY_PARTITION variable=X complete dim=2
#pragma HLS DATAFLOW
    make_sigma_points<N>(x_in, S_in, w, X);
    float x1[N];
    float S1[N][N];
    float X2[N][2 * N + 1];
#pragma HLS ARRAY_PARTITION variable=X2 complete dim=2
    float X1p[N][2 * N + 1];
#pragma HLS ARRAY_PARTITION variable=X1p complete dim=2
    ukf_ut_process<N, M>(X, w, q, x1, S1, X2, X1p);
    float z1[M];
    float S2[M][M];
    float Z2[M][2 * N + 1];
#pragma HLS ARRAY_PARTITION variable=Z2 complete dim=2
    ukf_ut_meas<N, M>(X1p, w, r, z1, S2, Z2);
    float P12[N][M];
    cross_cov<N, M>(X2, Z2, w, P12);
    ukf_update<N, M>(x1, z, z1, S1, S2, P12, x_out, S_out);
}

template <int N, int M, int MAX_STEPS>
void ukf_run(int N_steps, float q, float r, const float dx0[N], const float meas_noise[MAX_STEPS][M],
             const float proc_noise[MAX_STEPS][N], float x_out[N]) {
    float s[N];
    s[0] = 0.0f;
    s[1] = 0.0f;
    s[2] = 1.0f;
    float x[N];
    for (int i = 0; i < N; i++) x[i] = s[i] + dx0[i];
    float S[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) S[i][j] = (i == j) ? 1.0f : 0.0f;
    }
    for (int k = 0; k < N_steps; k++) {
        float zk[M];
        float hs[M];
        h_meas<N, M>(s, hs);
        for (int i = 0; i < M; i++) zk[i] = hs[i] + meas_noise[k][i];
        float x_next[N];
        float S_next[N][N];
        ukf_step<N, M>(zk, q, r, x, S, x_next, S_next);
        for (int i = 0; i < N; i++) x[i] = x_next[i];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) S[i][j] = S_next[i][j];
        }
        float fs[N];
        f_state<N>(s, fs);
        for (int i = 0; i < N; i++) s[i] = fs[i] + proc_noise[k][i];
    }
    for (int i = 0; i < N; i++) x_out[i] = x[i];
}

} // namespace solver
} // namespace xf

#endif