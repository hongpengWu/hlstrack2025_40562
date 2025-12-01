#include "ukf.hpp"

extern "C" {
void ukf_accel(
    int N_steps,
    float q,
    float r,
    const float dx0[3],
    const float meas_noise[256][2],
    const float proc_noise[256][3],
    float x_out[3]) {
#pragma HLS INLINE off
    xf::solver::ukf_run<3, 2, 256>(N_steps, q, r, dx0, meas_noise, proc_noise, x_out);
}

void ukf_accel_step(
    const float z[2],
    float q,
    float r,
    float x_in[3],
    float S_in[3][3],
    float x_out[3],
    float S_out[3][3]) {
#pragma HLS INLINE off
#pragma HLS INTERFACE s_axilite port=z bundle=control
#pragma HLS INTERFACE s_axilite port=q bundle=control
#pragma HLS INTERFACE s_axilite port=r bundle=control
#pragma HLS INTERFACE s_axilite port=x_in bundle=control
#pragma HLS INTERFACE s_axilite port=S_in bundle=control
#pragma HLS INTERFACE s_axilite port=x_out bundle=control
#pragma HLS INTERFACE s_axilite port=S_out bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control
    xf::solver::ukf_step<3, 2>(z, q, r, x_in, S_in, x_out, S_out);
}
}