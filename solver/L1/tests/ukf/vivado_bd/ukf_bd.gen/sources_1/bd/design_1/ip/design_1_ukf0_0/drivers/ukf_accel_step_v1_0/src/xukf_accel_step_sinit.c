// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xukf_accel_step.h"

extern XUkf_accel_step_Config XUkf_accel_step_ConfigTable[];

#ifdef SDT
XUkf_accel_step_Config *XUkf_accel_step_LookupConfig(UINTPTR BaseAddress) {
	XUkf_accel_step_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XUkf_accel_step_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XUkf_accel_step_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XUkf_accel_step_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XUkf_accel_step_Initialize(XUkf_accel_step *InstancePtr, UINTPTR BaseAddress) {
	XUkf_accel_step_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XUkf_accel_step_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XUkf_accel_step_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XUkf_accel_step_Config *XUkf_accel_step_LookupConfig(u16 DeviceId) {
	XUkf_accel_step_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XUKF_ACCEL_STEP_NUM_INSTANCES; Index++) {
		if (XUkf_accel_step_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XUkf_accel_step_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XUkf_accel_step_Initialize(XUkf_accel_step *InstancePtr, u16 DeviceId) {
	XUkf_accel_step_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XUkf_accel_step_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XUkf_accel_step_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

