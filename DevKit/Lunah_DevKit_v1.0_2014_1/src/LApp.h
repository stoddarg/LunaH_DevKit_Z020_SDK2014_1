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

///SD Card Includes
#include "xparameters.h"	// SDK generated parameters
#include "xsdps.h"			// SD device driver
#include "ff.h"
#include "xil_cache.h"

/* Globals */
#define LOG_FILE_BUFF_SIZE	120
#define UART_DEVICEID		XPAR_XUARTPS_0_DEVICE_ID
#define SW_BREAK_GPIO		51
#define IIC_DEVICE_ID		XPAR_XIICPS_0_DEVICE_ID
#define TEST_BUFFER_SIZE	2

// Hardware Interface
XUartPs Uart_PS;					// Instance of the UART Device
XGpioPs Gpio;						// Instance of the GPIO Driver Interface
XGpioPs_Config *GPIOConfigPtr;		// GPIO configuration pointer
static XScuGic_Config *GicConfig; 	// GicConfig
XScuGic InterruptController;		// Interrupt controller

/* FAT File System Variables */
FATFS fatfs;
FRESULT ffs_res;
FILINFO fno;
FILINFO fnoDIR;
int doMount = 0;
char cZeroBuffer[] = "0000000000 ";
char cLogFile[] = "LogFile.txt";	//Create a log file and file pointer
FIL logFile;
char filptr_buffer[11] = {};		// Holds 10 numbers and a null terminator
int filptr_clogFile = 0;
char cDirectoryLogFile[] = "DirectoryFile.txt";	//Directory File to hold all filenames
FIL directoryLogFile;
char filptr_cDIRFile_buffer[11] = {};
int filptr_cDIRFile = 0;

char cWriteToLogFile[LOG_FILE_BUFF_SIZE] = "";			//The buffer for adding information to the log file
int iSprintfReturn = 0;
double dTime = 12345.67;
uint numBytesWritten = 0;
uint numBytesRead = 0;

/* UART Variables */
static char SendBuffer[32];		// Buffer for Transmitting Data	// Used for RecvCommandPoll()
static char RecvBuffer[32];		// Buffer for Receiving Data

/* Menu Select Variable */
int	menusel = 99999;	// Menu Select

/* Set Mode Variables */
int mode = 9;			// Mode of Operation

/* Set Enable State Variables */
int enable_state = 0; 	// 0: disabled, 1: enabled

/* Set Threshold Variables */
int iThreshold0 = 0;	// Trigger Threshold
int iThreshold1 = 0;	// Beginning value of the trigger threshold

/* Set Integration Times Arrays */
char updateint = 'N';	// switch to change integral values
int setIntsArray[8] = {};
u32 setSamples[4] = {};
int setBL = 0;
int setSI = 0;
int setLI = 0;
int setFI = 0;

/* Check the size of the BRAM Buffer */
u32 databuff = 0;		// size of the data buffer

/* I2C Variables */
u8 i2c_Send_Buffer[TEST_BUFFER_SIZE];
u8 i2c_Recv_Buffer[2];
int IIC_SLAVE_ADDR1 = 0x20;
int IIC_SLAVE_ADDR2 = 0x48;
int *IIC_SLAVE_ADDR;		//pointer to slave
int rdac = 0;
int data_bits = 0;
int a, b;					//used for bitwise operations
short cntrl = 0;
short pot_addr = 0;

// General Purpose Variables
int Status; 					// General purpose Status indicator
int sw;  						// switch to stop and return to main menu  0= default.  1 = return
u32 global_frame_counter = 0;	// Counts ... for ...
int i = 0;						// Iterator in some places

// Methods
int InitializeAXIDma(void); 		// Initialize AXI DMA Transfer
int InitializeInterruptSystem(u16 deviceID);
void InterruptHandler (void );
int SetUpInterruptSystem(XScuGic *XScuGicInstancePtr);
int ReadCommandPoll();				// Read Command Poll Function
void SetIntegrationTimes();			// Set the Registers forIntegral Times
int PrintData();					// Print Data to the Terminal Window
void ClearBuffers();				// Clear Processeed Data Buffers
int DAQ();							// Clear Processeed Data Buffers
int ReadDataIn(int numfilesWritten);// Take data from DRAM, process it, save it to SD
int getWFDAQ();						// Print data skipping saving it to SD card
int LNumDigits(int number);			// Determine the number of digits in an int

#endif /* LAPP_H_ */
