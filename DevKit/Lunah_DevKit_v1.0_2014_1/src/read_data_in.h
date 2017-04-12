/*
 * read_data_in.h
 *
 *  Created on: Feb 14, 2017
 *      Author: GStoddard
 */

#ifndef READ_DATA_IN_H_
#define READ_DATA_IN_H_

///// Include statements that PrintData() needs
#include <stdio.h>
#include <xil_io.h>
#include <stdlib.h>
#include "xaxidma.h"
#include "xtime_l.h"
#include "xgpiops.h"
#include "xuartps.h"

///// Include statements that SD card needs
#include "xparameters.h"	/* SDK generated parameters */
#include "xsdps.h"			/* SD device driver */
#include "ff.h"
#include "xil_cache.h"
#include "LNumDigits.h"

///// Global Variables /////
#define SW_BREAK_GPIO		51
#define data_array_size		512
#define FILENAME_BUFF_SIZE	120

///// Structure Definitions ////

struct event_raw {			// Structure is 8+4+8+8+8+8= 44 bytes long
	double time;
	double total_events;
	double event_num;
	double bl;
	double si;
	double li;
	double fi;
	double psd;
	double energy;
};

///// General Variables /////
XUartPs Uart_PS;			// Instance of the UART Device
XGpioPs Gpio;				// Instance of the GPIO Driver Interface

int sw;						// switch to stop and return to main menu  0= default.  1 = return
u8 RecvBuffer[32];			// Buffer for receiving data, made global GS

u32 data;
int dram_base, dram_ceiling;
int dram_addr, array_index, diff, nevents;
double bl1, bl2, bl3, bl4, bl_avg;	// bl_sum;
long long howFar;

//FIL file;
//FATFS fatfs;
FILINFO finfo;
int iwrPtr = 0;
char wrPtrBuff[11] = {};		// Holds 10 numbers and a null terminator
char cDirectoryLogFile1[] = "DirectoryFile.txt";	//Directory File to hold all filenames
uint inumBytesRead = 0;
uint inumBytesWritten = 0;
int iSprintfRet = 0;

///// Function Definitions /////
int ReadDataIn(int numFilesWritten, FIL * filObj, int iptr_writeToDIRFile);	// Print Data to the Terminal Window

#endif /* READ_DATA_IN_H_ */
