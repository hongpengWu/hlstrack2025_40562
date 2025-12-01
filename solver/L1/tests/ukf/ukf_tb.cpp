#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "ukf.hpp"
extern "C" void ukf_accel(int N_steps, float q, float r, const float dx0[3], const float meas_noise[256][2],
                           const float proc_noise[256][3], float x_out[3]);
extern "C" void ukf_accel_step(const float z[2], float q, float r, float x_in[3], float S_in[3][3], float x_out[3],
                                float S_out[3][3]);

int main() {
    const char* inpath = "/home/whp/Desktop/Lucas/Vitis_Libraries-main/sr-ukf-master/inputs_ukf_common.txt";
    FILE* fp = fopen(inpath, "r");
    if (!fp) {
        fprintf(stderr, "ERROR: cannot open %s\n", inpath);
        return -1;
    }
    int n, m, N;
    if (fscanf(fp, "%d,%d,%d\n", &n, &m, &N) != 3) {
        fprintf(stderr, "ERROR: bad header\n");
        return -1;
    }
    float q, r;
    if (fscanf(fp, "%f,%f\n", &q, &r) != 2) {
        fprintf(stderr, "ERROR: bad noise line\n");
        return -1;
    }
    float dx0[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        float v;
        if (fscanf(fp, i < n - 1 ? "%f," : "%f\n", &v) != 1) {
            fprintf(stderr, "ERROR: bad dx0 line\n");
            return -1;
        }
        dx0[i] = v;
    }
    float meas_noise[256][2];
    float proc_noise[256][3];
    for (int k = 0; k < N; k++) {
        float z0, z1, pn0, pn1, pn2;
        if (fscanf(fp, "%f,%f,%f,%f,%f\n", &z0, &z1, &pn0, &pn1, &pn2) != 5) {
            fprintf(stderr, "ERROR: bad step line\n");
            return -1;
        }
        meas_noise[k][0] = z0;
        meas_noise[k][1] = z1;
        proc_noise[k][0] = pn0;
        proc_noise[k][1] = pn1;
        proc_noise[k][2] = pn2;
    }
    fclose(fp);
    float s[3] = {0.0f, 0.0f, 1.0f};
    float x[3] = {s[0] + dx0[0], s[1] + dx0[1], s[2] + dx0[2]};
    float S[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) S[i][j] = (i == j) ? 1.0f : 0.0f;
    }
    FILE* fpout = fopen("/home/whp/Desktop/Lucas/Vitis_Libraries-main/solver/L1/tests/ukf/result_ukf_hls.txt", "w");
    if (!fpout) {
        fprintf(stderr, "ERROR: cannot open result file for write\n");
        return -1;
    }
    fprintf(fpout, "%% Step, Actual[0], Actual[1], Actual[2], Estimate[0], Estimate[1], Estimate[2]\n");
    for (int k = 0; k < N; k++) {
        float zk[2];
        float hs[2];
        xf::solver::h_meas<3,2>(s, hs);
        zk[0] = hs[0] + meas_noise[k][0];
        zk[1] = hs[1] + meas_noise[k][1];
        float x_next[3];
        float S_next[3][3];
        xf::solver::ukf_step<3,2>(zk, q, r, x, S, x_next, S_next);
        fprintf(fpout, "%d, %.10f, %.10f, %.10f, %.10f, %.10f, %.10f\n", k+1, s[0], s[1], s[2], x_next[0], x_next[1], x_next[2]);
        for (int i = 0; i < 3; i++) x[i] = x_next[i];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) S[i][j] = S_next[i][j];
        }
        float fs[3];
        xf::solver::f_state<3>(s, fs);
        for (int i = 0; i < 3; i++) s[i] = fs[i] + proc_noise[k][i];
    }
    float hs_last[2];
    xf::solver::h_meas<3,2>(s, hs_last);
    float z_last[2];
    z_last[0] = hs_last[0] + meas_noise[N-1][0];
    z_last[1] = hs_last[1] + meas_noise[N-1][1];
    float x_out_step[3];
    float S_out_step[3][3];
    ukf_accel_step(z_last, q, r, x, S, x_out_step, S_out_step);
    fclose(fpout);

    const char* mpath = "/home/whp/Desktop/Lucas/Vitis_Libraries-main/sr-ukf-master/result_ukf_matlab.txt";
    const char* hpath = "/home/whp/Desktop/Lucas/Vitis_Libraries-main/solver/L1/tests/ukf/result_ukf_hls.txt";
    FILE* fm = fopen(mpath, "r");
    FILE* fh = fopen(hpath, "r");
    if (!fm || !fh) {
        fprintf(stderr, "ERRORCHECK: cannot open results\n");
        if (fm) fclose(fm);
        if (fh) fclose(fh);
        return -2;
    }
    char buf[512];
    int m_steps[4096];
    float m_est[4096][3];
    int h_steps[4096];
    float h_est[4096][3];
    int mc = 0, hc = 0;
    while (fgets(buf, sizeof(buf), fm)) {
        if (buf[0] == '%') continue;
        int st; float a0,a1,a2,e0,e1,e2;
        if (sscanf(buf, "%d, %f, %f, %f, %f, %f, %f", &st, &a0, &a1, &a2, &e0, &e1, &e2) == 7) {
            m_steps[mc] = st;
            m_est[mc][0] = e0; m_est[mc][1] = e1; m_est[mc][2] = e2;
            mc++;
        }
    }
    while (fgets(buf, sizeof(buf), fh)) {
        if (buf[0] == '%') continue;
        int st; float a0,a1,a2,e0,e1,e2;
        if (sscanf(buf, "%d, %f, %f, %f, %f, %f, %f", &st, &a0, &a1, &a2, &e0, &e1, &e2) == 7) {
            h_steps[hc] = st;
            h_est[hc][0] = e0; h_est[hc][1] = e1; h_est[hc][2] = e2;
            hc++;
        }
    }
    fclose(fm);
    fclose(fh);
    double sum_err_sq[3] = {0.0,0.0,0.0};
    double sum_mat_sq[3] = {0.0,0.0,0.0};
    double sum_err_abs[3] = {0.0,0.0,0.0};
    double max_err[3] = {0.0,0.0,0.0};
    int cnt = 0;
    for (int i = 0; i < mc; i++) {
        int st = m_steps[i];
        for (int j = 0; j < hc; j++) {
            if (h_steps[j] == st) {
                for (int d = 0; d < 3; d++) {
                    double e = (double)h_est[j][d] - (double)m_est[i][d];
                    sum_err_sq[d] += e*e;
                    sum_err_abs[d] += std::fabs(e);
                    if (std::fabs(e) > max_err[d]) max_err[d] = std::fabs(e);
                    double mm = (double)m_est[i][d];
                    sum_mat_sq[d] += mm*mm;
                }
                cnt++;
                break;
            }
        }
    }
    if (cnt == 0) {
        fprintf(stderr, "ERRORCHECK: no common steps\n");
        return -3;
    }
    double rmse[3], nrmse[3], mae[3];
    for (int d = 0; d < 3; d++) {
        rmse[d] = std::sqrt(sum_err_sq[d] / (double)cnt);
        double denom = std::sqrt((sum_mat_sq[d] / (double)cnt) + 1e-12);
        nrmse[d] = rmse[d] / denom;
        mae[d] = sum_err_abs[d] / (double)cnt;
    }
    double agg_rmse = std::sqrt((sum_err_sq[0]+sum_err_sq[1]+sum_err_sq[2]) / (3.0*(double)cnt));
    double agg_denom = std::sqrt(((sum_mat_sq[0]+sum_mat_sq[1]+sum_mat_sq[2]) / (3.0*(double)cnt)) + 1e-12);
    double agg_nrmse = agg_rmse / agg_denom;
    printf("ERRORCHECK: cnt=%d\n", cnt);
    printf("ERRORCHECK: RMSE: %.8f, %.8f, %.8f\n", rmse[0], rmse[1], rmse[2]);
    printf("ERRORCHECK: MAE: %.8f, %.8f, %.8f\n", mae[0], mae[1], mae[2]);
    printf("ERRORCHECK: MaxAbs: %.8f, %.8f, %.8f\n", max_err[0], max_err[1], max_err[2]);
    printf("ERRORCHECK: NRMSE: %.8f, %.8f, %.8f\n", nrmse[0], nrmse[1], nrmse[2]);
    printf("ERRORCHECK: AggNRMSE: %.8f\n", agg_nrmse);
    double thr = 0.30;
    if (agg_nrmse > thr) {
        fprintf(stderr, "ERRORCHECK: FAIL (AggNRMSE=%.6f > %.6f)\n", agg_nrmse, thr);
        return -4;
    }
    printf("ERRORCHECK: PASS\n");
    return 0;
}