// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xukf_accel_step.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XUkf_accel_step_CfgInitialize(XUkf_accel_step *InstancePtr, XUkf_accel_step_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XUkf_accel_step_Start(XUkf_accel_step *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUkf_accel_step_ReadReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_AP_CTRL) & 0x80;
    XUkf_accel_step_WriteReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XUkf_accel_step_IsDone(XUkf_accel_step *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUkf_accel_step_ReadReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XUkf_accel_step_IsIdle(XUkf_accel_step *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUkf_accel_step_ReadReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XUkf_accel_step_IsReady(XUkf_accel_step *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUkf_accel_step_ReadReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XUkf_accel_step_EnableAutoRestart(XUkf_accel_step *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUkf_accel_step_WriteReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XUkf_accel_step_DisableAutoRestart(XUkf_accel_step *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUkf_accel_step_WriteReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_AP_CTRL, 0);
}

void XUkf_accel_step_Set_q(XUkf_accel_step *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUkf_accel_step_WriteReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_Q_DATA, Data);
}

u32 XUkf_accel_step_Get_q(XUkf_accel_step *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUkf_accel_step_ReadReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_Q_DATA);
    return Data;
}

void XUkf_accel_step_Set_r(XUkf_accel_step *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUkf_accel_step_WriteReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_R_DATA, Data);
}

u32 XUkf_accel_step_Get_r(XUkf_accel_step *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XUkf_accel_step_ReadReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_R_DATA);
    return Data;
}

u32 XUkf_accel_step_Get_z_BaseAddress(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_Z_BASE);
}

u32 XUkf_accel_step_Get_z_HighAddress(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_Z_HIGH);
}

u32 XUkf_accel_step_Get_z_TotalBytes(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XUKF_ACCEL_STEP_CONTROL_ADDR_Z_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_Z_BASE + 1);
}

u32 XUkf_accel_step_Get_z_BitWidth(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUKF_ACCEL_STEP_CONTROL_WIDTH_Z;
}

u32 XUkf_accel_step_Get_z_Depth(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUKF_ACCEL_STEP_CONTROL_DEPTH_Z;
}

u32 XUkf_accel_step_Write_z_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XUKF_ACCEL_STEP_CONTROL_ADDR_Z_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_Z_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_Z_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XUkf_accel_step_Read_z_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XUKF_ACCEL_STEP_CONTROL_ADDR_Z_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_Z_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_Z_BASE + (offset + i)*4);
    }
    return length;
}

u32 XUkf_accel_step_Write_z_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XUKF_ACCEL_STEP_CONTROL_ADDR_Z_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_Z_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_Z_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XUkf_accel_step_Read_z_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XUKF_ACCEL_STEP_CONTROL_ADDR_Z_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_Z_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_Z_BASE + offset + i);
    }
    return length;
}

u32 XUkf_accel_step_Get_x_in_BaseAddress(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_BASE);
}

u32 XUkf_accel_step_Get_x_in_HighAddress(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_HIGH);
}

u32 XUkf_accel_step_Get_x_in_TotalBytes(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_BASE + 1);
}

u32 XUkf_accel_step_Get_x_in_BitWidth(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUKF_ACCEL_STEP_CONTROL_WIDTH_X_IN;
}

u32 XUkf_accel_step_Get_x_in_Depth(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUKF_ACCEL_STEP_CONTROL_DEPTH_X_IN;
}

u32 XUkf_accel_step_Write_x_in_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XUkf_accel_step_Read_x_in_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_BASE + (offset + i)*4);
    }
    return length;
}

u32 XUkf_accel_step_Write_x_in_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XUkf_accel_step_Read_x_in_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_IN_BASE + offset + i);
    }
    return length;
}

u32 XUkf_accel_step_Get_S_in_BaseAddress(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_BASE);
}

u32 XUkf_accel_step_Get_S_in_HighAddress(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_HIGH);
}

u32 XUkf_accel_step_Get_S_in_TotalBytes(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_BASE + 1);
}

u32 XUkf_accel_step_Get_S_in_BitWidth(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUKF_ACCEL_STEP_CONTROL_WIDTH_S_IN;
}

u32 XUkf_accel_step_Get_S_in_Depth(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUKF_ACCEL_STEP_CONTROL_DEPTH_S_IN;
}

u32 XUkf_accel_step_Write_S_in_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XUkf_accel_step_Read_S_in_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_BASE + (offset + i)*4);
    }
    return length;
}

u32 XUkf_accel_step_Write_S_in_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XUkf_accel_step_Read_S_in_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_IN_BASE + offset + i);
    }
    return length;
}

u32 XUkf_accel_step_Get_x_out_BaseAddress(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_BASE);
}

u32 XUkf_accel_step_Get_x_out_HighAddress(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_HIGH);
}

u32 XUkf_accel_step_Get_x_out_TotalBytes(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_BASE + 1);
}

u32 XUkf_accel_step_Get_x_out_BitWidth(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUKF_ACCEL_STEP_CONTROL_WIDTH_X_OUT;
}

u32 XUkf_accel_step_Get_x_out_Depth(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUKF_ACCEL_STEP_CONTROL_DEPTH_X_OUT;
}

u32 XUkf_accel_step_Write_x_out_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XUkf_accel_step_Read_x_out_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_BASE + (offset + i)*4);
    }
    return length;
}

u32 XUkf_accel_step_Write_x_out_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XUkf_accel_step_Read_x_out_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_X_OUT_BASE + offset + i);
    }
    return length;
}

u32 XUkf_accel_step_Get_S_out_BaseAddress(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_BASE);
}

u32 XUkf_accel_step_Get_S_out_HighAddress(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_HIGH);
}

u32 XUkf_accel_step_Get_S_out_TotalBytes(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_BASE + 1);
}

u32 XUkf_accel_step_Get_S_out_BitWidth(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUKF_ACCEL_STEP_CONTROL_WIDTH_S_OUT;
}

u32 XUkf_accel_step_Get_S_out_Depth(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUKF_ACCEL_STEP_CONTROL_DEPTH_S_OUT;
}

u32 XUkf_accel_step_Write_S_out_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XUkf_accel_step_Read_S_out_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_BASE + (offset + i)*4);
    }
    return length;
}

u32 XUkf_accel_step_Write_S_out_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XUkf_accel_step_Read_S_out_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_HIGH - XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XUKF_ACCEL_STEP_CONTROL_ADDR_S_OUT_BASE + offset + i);
    }
    return length;
}

void XUkf_accel_step_InterruptGlobalEnable(XUkf_accel_step *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUkf_accel_step_WriteReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_GIE, 1);
}

void XUkf_accel_step_InterruptGlobalDisable(XUkf_accel_step *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUkf_accel_step_WriteReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_GIE, 0);
}

void XUkf_accel_step_InterruptEnable(XUkf_accel_step *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XUkf_accel_step_ReadReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_IER);
    XUkf_accel_step_WriteReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_IER, Register | Mask);
}

void XUkf_accel_step_InterruptDisable(XUkf_accel_step *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XUkf_accel_step_ReadReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_IER);
    XUkf_accel_step_WriteReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_IER, Register & (~Mask));
}

void XUkf_accel_step_InterruptClear(XUkf_accel_step *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XUkf_accel_step_WriteReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_ISR, Mask);
}

u32 XUkf_accel_step_InterruptGetEnabled(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUkf_accel_step_ReadReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_IER);
}

u32 XUkf_accel_step_InterruptGetStatus(XUkf_accel_step *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XUkf_accel_step_ReadReg(InstancePtr->Control_BaseAddress, XUKF_ACCEL_STEP_CONTROL_ADDR_ISR);
}

