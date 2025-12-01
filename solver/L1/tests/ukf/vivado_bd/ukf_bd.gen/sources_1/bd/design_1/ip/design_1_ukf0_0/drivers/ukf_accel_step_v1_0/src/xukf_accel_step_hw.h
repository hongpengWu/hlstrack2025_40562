// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 7  - auto_restart (Read/Write)
//        bit 9  - interrupt (Read)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0 - enable ap_done interrupt (Read/Write)
//        bit 1 - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0 - ap_done (Read/TOW)
//        bit 1 - ap_ready (Read/TOW)
//        others - reserved
// 0x18 : Data signal of q
//        bit 31~0 - q[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of r
//        bit 31~0 - r[31:0] (Read/Write)
// 0x24 : reserved
// 0x10 ~
// 0x17 : Memory 'z' (2 * 32b)
//        Word n : bit [31:0] - z[n]
// 0x30 ~
// 0x3f : Memory 'x_in' (3 * 32b)
//        Word n : bit [31:0] - x_in[n]
// 0x40 ~
// 0x7f : Memory 'S_in' (9 * 32b)
//        Word n : bit [31:0] - S_in[n]
// 0x80 ~
// 0x8f : Memory 'x_out' (3 * 32b)
//        Word n : bit [31:0] - x_out[n]
// 0xc0 ~
// 0xff : Memory 'S_out' (9 * 32b)
//        Word n : bit [31:0] - S_out[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XUKF_ACCEL_STEP_CONTROL_ADDR_AP_CTRL    0x00
#define XUKF_ACCEL_STEP_CONTROL_ADDR_GIE        0x04
#define XUKF_ACCEL_STEP_CONTROL_ADDR_IER        0x08
#define XUKF_ACCEL_STEP_CONTROL_ADDR_ISR        0x0c
#define XUKF_ACCEL_STEP_CONTROL_ADDR_Q_DATA     0x18
#define XUKF_ACCEL_STEP_CONTROL_BITS_Q_DATA     32
#define XUKF_ACCEL_STEP_CONTROL_ADDR_R_DATA     0x20
#define XUKF_ACCEL_STEP_CONTROL_BITS_R_DATA     32
#define XUKF_ACCEL_STEP_CONTROL_ADDR_Z_BASE     0x10
#define XUKF_ACCEL_STEP_CONTROL_ADDR_Z_HIGH     0x17
#define XUKF_ACCEL_STEP_CONTROL_WIDTH_Z         32
#define XUKF_ACCEL_STEP_CONTROL_DEPTH_Z         2
#define XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_BASE  0x30
#define XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_HIGH  0x3f
#define XUKF_ACCEL_STEP_CONTROL_WIDTH_X_IN      32
#define XUKF_ACCEL_STEP_CONTROL_DEPTH_X_IN      3
#define XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_BASE  0x40
#define XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_HIGH  0x7f
#define XUKF_ACCEL_STEP_CONTROL_WIDTH_S_IN      32
#define XUKF_ACCEL_STEP_CONTROL_DEPTH_S_IN      9
#define XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_BASE 0x80
#define XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_HIGH 0x8f
#define XUKF_ACCEL_STEP_CONTROL_WIDTH_X_OUT     32
#define XUKF_ACCEL_STEP_CONTROL_DEPTH_X_OUT     3
#define XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_BASE 0xc0
#define XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_HIGH 0xff
#define XUKF_ACCEL_STEP_CONTROL_WIDTH_S_OUT     32
#define XUKF_ACCEL_STEP_CONTROL_DEPTH_S_OUT     9

