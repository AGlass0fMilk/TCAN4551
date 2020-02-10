/*
 * TCAN4550.h
 * Description: This file contains TCAN4550 functions, and relies on the TCAN4x5x_SPI abstraction functions
 *
 *
 *
 * Copyright (c) 2019 Texas Instruments Incorporated.  All rights reserved.
 * Software License Agreement
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef TCAN4550_H_
#define TCAN4550_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "TCAN4x5x_SPI.h"
#include "TCAN4x5x_Reg.h"
#include "TCAN4x5x_Data_Structs.h"

#include <stdbool.h>

//! If TCAN4x5x_MCAN_CACHE_CONFIGURATION is defined, then the read and write to MRAM functions will cache certain values to reduce the number of SPI reads necessary to send or receive a packet
#define TCAN4x5x_MCAN_CACHE_CONFIGURATION

//! If TCAN4x5x_MCAN_VERIFY_CONFIGURATION_WRITES is defined, then each MCAN configuration write will be read and verified for correctness
#define TCAN4x5x_MCAN_VERIFY_CONFIGURATION_WRITES

//! If TCAN4x5x_DEVICE_VERIFY_CONFIGURATION_WRITES is defined, then each device configuration write will be read and verified for correctness
#define TCAN4x5x_DEVICE_VERIFY_CONFIGURATION_WRITES


// Defines for caching the configuration values to save on reads and writes
#ifdef TCAN4x5x_MCAN_CACHE_CONFIGURATION
#define TCAN4x5x_MCAN_CACHE_SIDFC           0
#define TCAN4x5x_MCAN_CACHE_XIDFC           1
#define TCAN4x5x_MCAN_CACHE_RXF0C           2
#define TCAN4x5x_MCAN_CACHE_RXF1C           3
#define TCAN4x5x_MCAN_CACHE_RXBC            4
#define TCAN4x5x_MCAN_CACHE_TXEFC           5
#define TCAN4x5x_MCAN_CACHE_TXBC            6
#define TCAN4x5x_MCAN_CACHE_RXESC           7
#define TCAN4x5x_MCAN_CACHE_TXESC           8
#endif

typedef enum { RXFIFO0, RXFIFO1 } TCAN4x5x_MCAN_FIFO_Enum;
typedef enum { TCAN4x5x_WDT_60MS, TCAN4x5x_WDT_600MS, TCAN4x5x_WDT_3S, TCAN4x5x_WDT_6S } TCAN4x5x_WDT_Timer_Enum;
typedef enum { TCAN4x5x_DEVICE_TEST_MODE_NORMAL, TCAN4x5x_DEVICE_TEST_MODE_PHY, TCAN4x5x_DEVICE_TEST_MODE_CONTROLLER } TCAN4x5x_Device_Test_Mode_Enum;
typedef enum { TCAN4x5x_DEVICE_MODE_NORMAL, TCAN4x5x_DEVICE_MODE_STANDBY, TCAN4x5x_DEVICE_MODE_SLEEP } TCAN4x5x_Device_Mode_Enum;

// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//                            MCAN Device Functions
// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
extern bool TCAN4x5x_MCAN_EnableProtectedRegisters(tcan_handle_t handle);
extern bool TCAN4x5x_MCAN_DisableProtectedRegisters(tcan_handle_t handle);
extern bool TCAN4x5x_MCAN_ConfigureCCCRRegister(tcan_handle_t handle, TCAN4x5x_MCAN_CCCR_Config *cccr);
extern void TCAN4x5x_MCAN_ReadCCCRRegister(tcan_handle_t handle, TCAN4x5x_MCAN_CCCR_Config *cccrConfig);
extern void TCAN4x5x_MCAN_ReadDataTimingFD_Simple(tcan_handle_t handle, TCAN4x5x_MCAN_Data_Timing_Simple *dataTiming);
extern void TCAN4x5x_MCAN_ReadDataTimingFD_Raw(tcan_handle_t handle, TCAN4x5x_MCAN_Data_Timing_Raw *dataTiming);
extern bool TCAN4x5x_MCAN_ConfigureDataTiming_Simple(tcan_handle_t handle, TCAN4x5x_MCAN_Data_Timing_Simple *dataTiming);
extern bool TCAN4x5x_MCAN_ConfigureDataTiming_Raw(tcan_handle_t handle, TCAN4x5x_MCAN_Data_Timing_Raw *dataTiming);
extern void TCAN4x5x_MCAN_ReadNominalTiming_Simple(tcan_handle_t handle, TCAN4x5x_MCAN_Nominal_Timing_Simple *nomTiming);
extern void TCAN4x5x_MCAN_ReadNominalTiming_Raw(tcan_handle_t handle, TCAN4x5x_MCAN_Nominal_Timing_Raw *nomTiming);
extern bool TCAN4x5x_MCAN_ConfigureNominalTiming_Simple(tcan_handle_t handle, TCAN4x5x_MCAN_Nominal_Timing_Simple *nomTiming);
extern bool TCAN4x5x_MCAN_ConfigureNominalTiming_Raw(tcan_handle_t handle, TCAN4x5x_MCAN_Nominal_Timing_Raw *nomTiming);
extern bool TCAN4x5x_MCAN_ConfigureGlobalFilter(tcan_handle_t handle, TCAN4x5x_MCAN_Global_Filter_Configuration *gfc);


extern bool TCAN4x5x_MRAM_Configure(tcan_handle_t handle, TCAN4x5x_MRAM_Config *MRAMConfig);
extern void TCAN4x5x_MRAM_Clear(tcan_handle_t handle);
extern void TCAN4x5x_MCAN_ReadInterrupts(tcan_handle_t handle, TCAN4x5x_MCAN_Interrupts *ir);
extern void TCAN4x5x_MCAN_ClearInterrupts(tcan_handle_t handle, TCAN4x5x_MCAN_Interrupts *ir);
extern void TCAN4x5x_MCAN_ClearInterruptsAll(tcan_handle_t handle);
extern void TCAN4x5x_MCAN_ReadInterruptEnable(tcan_handle_t handle, TCAN4x5x_MCAN_Interrupt_Enable *ie);
extern void TCAN4x5x_MCAN_ConfigureInterruptEnable(tcan_handle_t handle, TCAN4x5x_MCAN_Interrupt_Enable *ie);
extern uint8_t TCAN4x5x_MCAN_ReadNextFIFO(tcan_handle_t handle, TCAN4x5x_MCAN_FIFO_Enum FIFODefine, TCAN4x5x_MCAN_RX_Header *header, uint8_t dataPayload[]);
extern uint8_t TCAN4x5x_MCAN_ReadRXBuffer(tcan_handle_t handle, uint8_t bufIndex, TCAN4x5x_MCAN_RX_Header *header, uint8_t dataPayload[]);
extern uint32_t TCAN4x5x_MCAN_WriteTXBuffer(tcan_handle_t handle, uint8_t bufIndex, TCAN4x5x_MCAN_TX_Header *header, uint8_t dataPayload[]);
extern bool TCAN4x5x_MCAN_TransmitBufferContents(tcan_handle_t handle, uint8_t bufIndex);
extern bool TCAN4x5x_MCAN_WriteSIDFilter(tcan_handle_t handle, uint8_t filterIndex, TCAN4x5x_MCAN_SID_Filter *filter);
extern bool TCAN4x5x_MCAN_ReadSIDFilter(tcan_handle_t handle, uint8_t filterIndex, TCAN4x5x_MCAN_SID_Filter *filter);
extern bool TCAN4x5x_MCAN_WriteXIDFilter(tcan_handle_t handle, uint8_t fifoIndex, TCAN4x5x_MCAN_XID_Filter *filter);
extern uint8_t TCAN4x5x_MCAN_DLCtoBytes(uint8_t inputDLC);
extern uint8_t TCAN4x5x_MCAN_TXRXESC_DataByteValue(uint8_t inputESCValue);




// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
//                            Non-MCAN Device Functions
// ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
extern uint16_t TCAN4x5x_Device_ReadDeviceVersion(tcan_handle_t handle);
extern bool TCAN4x5x_Device_Configure(tcan_handle_t handle, TCAN4x5x_DEV_CONFIG *devCfg);
extern void TCAN4x5x_Device_ReadConfig(tcan_handle_t handle, TCAN4x5x_DEV_CONFIG *devCfg);
extern void TCAN4x5x_Device_ReadInterrupts(tcan_handle_t handle, TCAN4x5x_Device_Interrupts *ir);
extern void TCAN4x5x_Device_ClearInterrupts(tcan_handle_t handle, TCAN4x5x_Device_Interrupts *ir);
extern void TCAN4x5x_Device_ClearInterruptsAll(tcan_handle_t handle);
extern void TCAN4x5x_Device_ClearSPIERR(tcan_handle_t handle);
extern void TCAN4x5x_Device_ReadInterruptEnable(tcan_handle_t handle, TCAN4x5x_Device_Interrupt_Enable *ie);
extern bool TCAN4x5x_Device_ConfigureInterruptEnable(tcan_handle_t handle, TCAN4x5x_Device_Interrupt_Enable *ie);
extern bool TCAN4x5x_Device_SetMode(tcan_handle_t handle, TCAN4x5x_Device_Mode_Enum modeDefine);
extern TCAN4x5x_Device_Mode_Enum TCAN4x5x_Device_ReadMode(tcan_handle_t handle);
extern bool TCAN4x5x_Device_EnableTestMode(tcan_handle_t handle, TCAN4x5x_Device_Test_Mode_Enum modeDefine);
extern bool TCAN4x5x_Device_DisableTestMode(tcan_handle_t handle);
extern TCAN4x5x_Device_Test_Mode_Enum TCAN4x5x_Device_ReadTestMode(tcan_handle_t handle);


extern bool TCAN4x5x_WDT_Configure(tcan_handle_t handle, TCAN4x5x_WDT_Timer_Enum WDTtimeout);
extern TCAN4x5x_WDT_Timer_Enum TCAN4x5x_WDT_Read(tcan_handle_t handle);
extern bool TCAN4x5x_WDT_Enable(tcan_handle_t handle);
extern bool TCAN4x5x_WDT_Disable(tcan_handle_t handle);
extern void TCAN4x5x_WDT_Reset(tcan_handle_t handle);

#ifdef __cplusplus
}
#endif

#endif
