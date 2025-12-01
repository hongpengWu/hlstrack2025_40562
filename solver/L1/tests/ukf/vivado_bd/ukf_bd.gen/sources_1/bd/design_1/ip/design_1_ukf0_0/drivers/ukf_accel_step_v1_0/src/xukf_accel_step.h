// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XUKF_ACCEL_STEP_H
#define XUKF_ACCEL_STEP_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xukf_accel_step_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Control_BaseAddress;
} XUkf_accel_step_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XUkf_accel_step;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XUkf_accel_step_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XUkf_accel_step_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XUkf_accel_step_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XUkf_accel_step_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XUkf_accel_step_Initialize(XUkf_accel_step *InstancePtr, UINTPTR BaseAddress);
XUkf_accel_step_Config* XUkf_accel_step_LookupConfig(UINTPTR BaseAddress);
#else
int XUkf_accel_step_Initialize(XUkf_accel_step *InstancePtr, u16 DeviceId);
XUkf_accel_step_Config* XUkf_accel_step_LookupConfig(u16 DeviceId);
#endif
int XUkf_accel_step_CfgInitialize(XUkf_accel_step *InstancePtr, XUkf_accel_step_Config *ConfigPtr);
#else
int XUkf_accel_step_Initialize(XUkf_accel_step *InstancePtr, const char* InstanceName);
int XUkf_accel_step_Release(XUkf_accel_step *InstancePtr);
#endif

void XUkf_accel_step_Start(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_IsDone(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_IsIdle(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_IsReady(XUkf_accel_step *InstancePtr);
void XUkf_accel_step_EnableAutoRestart(XUkf_accel_step *InstancePtr);
void XUkf_accel_step_DisableAutoRestart(XUkf_accel_step *InstancePtr);

void XUkf_accel_step_Set_q(XUkf_accel_step *InstancePtr, u32 Data);
u32 XUkf_accel_step_Get_q(XUkf_accel_step *InstancePtr);
void XUkf_accel_step_Set_r(XUkf_accel_step *InstancePtr, u32 Data);
u32 XUkf_accel_step_Get_r(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_z_BaseAddress(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_z_HighAddress(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_z_TotalBytes(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_z_BitWidth(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_z_Depth(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Write_z_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length);
u32 XUkf_accel_step_Read_z_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length);
u32 XUkf_accel_step_Write_z_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length);
u32 XUkf_accel_step_Read_z_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length);
u32 XUkf_accel_step_Get_x_in_BaseAddress(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_x_in_HighAddress(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_x_in_TotalBytes(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_x_in_BitWidth(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_x_in_Depth(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Write_x_in_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length);
u32 XUkf_accel_step_Read_x_in_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length);
u32 XUkf_accel_step_Write_x_in_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length);
u32 XUkf_accel_step_Read_x_in_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length);
u32 XUkf_accel_step_Get_S_in_BaseAddress(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_S_in_HighAddress(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_S_in_TotalBytes(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_S_in_BitWidth(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_S_in_Depth(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Write_S_in_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length);
u32 XUkf_accel_step_Read_S_in_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length);
u32 XUkf_accel_step_Write_S_in_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length);
u32 XUkf_accel_step_Read_S_in_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length);
u32 XUkf_accel_step_Get_x_out_BaseAddress(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_x_out_HighAddress(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_x_out_TotalBytes(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_x_out_BitWidth(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_x_out_Depth(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Write_x_out_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length);
u32 XUkf_accel_step_Read_x_out_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length);
u32 XUkf_accel_step_Write_x_out_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length);
u32 XUkf_accel_step_Read_x_out_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length);
u32 XUkf_accel_step_Get_S_out_BaseAddress(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_S_out_HighAddress(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_S_out_TotalBytes(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_S_out_BitWidth(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Get_S_out_Depth(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_Write_S_out_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length);
u32 XUkf_accel_step_Read_S_out_Words(XUkf_accel_step *InstancePtr, int offset, word_type *data, int length);
u32 XUkf_accel_step_Write_S_out_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length);
u32 XUkf_accel_step_Read_S_out_Bytes(XUkf_accel_step *InstancePtr, int offset, char *data, int length);

void XUkf_accel_step_InterruptGlobalEnable(XUkf_accel_step *InstancePtr);
void XUkf_accel_step_InterruptGlobalDisable(XUkf_accel_step *InstancePtr);
void XUkf_accel_step_InterruptEnable(XUkf_accel_step *InstancePtr, u32 Mask);
void XUkf_accel_step_InterruptDisable(XUkf_accel_step *InstancePtr, u32 Mask);
void XUkf_accel_step_InterruptClear(XUkf_accel_step *InstancePtr, u32 Mask);
u32 XUkf_accel_step_InterruptGetEnabled(XUkf_accel_step *InstancePtr);
u32 XUkf_accel_step_InterruptGetStatus(XUkf_accel_step *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
