/*
 * LI2C_Interface.h
 *
 *  Created on: Mar 16, 2017
 *      Author: GStoddard
 */

#ifndef LI2C_INTERFACE_H_
#define LI2C_INTERFACE_H_

#include "xparameters.h"
#include "ps7_init.h"
#include "platform_config.h"
#include "xiicps.h"
#include "xil_printf.h"
#include "unistd.h"
#include "xuartps.h"

#include <xil_io.h>
#include <stdio.h>

//#define UART_DEVICEID	XPAR_XUARTPS_0_DEVICE_ID
#define IIC_DEVICE_ID		XPAR_XIICPS_0_DEVICE_ID
#define IIC_SCLK_RATE		90000

/* Globals */


/* Declare Variables */
XIicPs Iic;					//Instance of the IIC device
int IIC_SLAVE_ADDR1 = 0x20;
int IIC_SLAVE_ADDR2 = 0x48;
int *IIC_SLAVE_ADDR;		//pointer to slave
int a, b;				//used for bitwise operations
int Status = 0;
int Index = 0;

int rdac = 0;
int data_bits = 0;
int i = 0;

short cntrl = 0;
short addr = 0;

/* Function Declarations */
int IicPsMasterSend(u16 DeviceId, int * ptr_Send_Buffer, u8 * ptr_Recv_Buffer);
int IicPsMasterRecieve(u16 DeviceId, u8 * ptr_Recv_Buffer);

#endif /* LI2C_INTERFACE_H_ */
