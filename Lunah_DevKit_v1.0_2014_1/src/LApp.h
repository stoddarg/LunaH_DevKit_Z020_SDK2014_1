/*
 * LApp.h
 *
 *  Created on: Jul 6, 2016
 *      Author: EJohnson
 */

#ifndef LAPP_H_
#define LAPP_H_

#include <stdio.h>
#include "platform.h"
#include "ps7_init.h"
#include <xil_io.h>
#include <xil_exception.h>
#include "xscugic.h"
#include "xaxidma.h"
#include "xparameters.h"
#include "platform_config.h"
#include "xgpiops.h"
#include "xuartps.h"
#include "xil_printf.h"
#include "sleep.h"
#include "LDetector.h"
#include "LModule.h"

/* Globals */
#define UART_DEVICEID      XPAR_XUARTPS_0_DEVICE_ID
#define SW_BREAK_GPIO		51

// Hardware Interface
XUartPs Uart_PS;					// Instance of the UART Device
XGpioPs Gpio;						// Instance of the GPIO Driver Interface
XGpioPs_Config *GPIOConfigPtr;		// GPIO configuration pointer
static XScuGic_Config *GicConfig; 	// GicConfig
XScuGic InterruptController;		// Interrupt controller

// UART Variables
static char SendBuffer[32];		// Buffer for Transmitting Data
static char RecvBuffer[32];		// Buffer for Receiving Data

// General Purpose Variables
int Status; 					// General purpose Status indicator
int sw;  						// switch to stop and return to main menu  0= default.  1 = return
u32 global_frame_counter = 0;	// Counts ... for ...

// Methods
int InitializeAXIDma(void); 		// Initialize AXI DMA Transfer
int InitializeInterruptSystem(u16 deviceID);
void InterruptHandler (void );
int SetUpInterruptSystem(XScuGic *XScuGicInstancePtr);
int ReadCommandPoll();				// Read Command Poll Function
void SetIntegrationTimes(u8 wfid);	// Set the Registers forIntegral Times
int PrintData();					// Print Data to the Terminal Window
void ClearBuffers();				// Clear Processeed Data Buffers
int DAQ();							// Clear Processeed Data Buffers
int ReadDataIn(int numfilesWritten);// Take data from DRAM, process it, save it to SD

#endif /* LAPP_H_ */
