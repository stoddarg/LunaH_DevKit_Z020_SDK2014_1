/*
 * LI2C_Interface.c
 *
 *  Created on: Mar 16, 2017
 *      Author: GStoddard
 */

#include "LI2C_Interface.h"

/*****************************************************************************/
/**
*
* This function sends data and expects to receive data from slave as modular
* of 64.
*
* This function uses interrupt-driven mode of the device.
*
* @param	DeviceId is the Device ID of the IicPs Device and is the
*		XPAR_<IICPS_instance>_DEVICE_ID value from xparameters.h
*
* @return	XST_SUCCESS if successful, otherwise XST_FAILURE.
*
* @note		None.
*
*******************************************************************************/
int IicPsMasterSend(u16 DeviceId, u8 * ptr_Send_Buffer, u8 * ptr_Recv_Buffer, int * iI2C_slave_addr)
{
	XIicPs_Config *Config;

	/*
	 * Initialize the IIC driver so that it's ready to use
	 * Look up the configuration in the config table,
	 * then initialize it.
	 */
	Config = XIicPs_LookupConfig(DeviceId);
	if (NULL == Config) {
		return XST_FAILURE;
	}

	iStatus = XIicPs_CfgInitialize(&Iic, Config, Config->BaseAddress);
	if (iStatus != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*
	 * Perform a self-test to ensure that the hardware was built correctly.
	 */
	iStatus = XIicPs_SelfTest(&Iic);
	if (iStatus != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*
	 * Set the IIC serial clock rate.
	 */
	XIicPs_SetSClk(&Iic, IIC_SCLK_RATE);

	/*
	 * Initialize the send buffer bytes with a pattern to send and the
	 * the receive buffer bytes to zero to allow the receive data to be
	 * verified.
	 */
	for (iIndex = 0; iIndex < TEST_BUFFER_SIZE; iIndex++) {
		ptr_Recv_Buffer[iIndex] = 0;
	}

	/*
	 * Send the buffer using the IIC and ignore the number of bytes sent
	 * as the return value since we are using it in interrupt mode.
	 */

	 XIicPs_MasterSend(&Iic, ptr_Send_Buffer, TEST_BUFFER_SIZE, *iI2C_slave_addr);
	 sleep(1);

	/*
	 * Wait until bus is idle to start another transfer.
	 */
	while (XIicPs_BusIsBusy(&Iic))
	{
		/* NOP */
	}

	if (iStatus != XST_SUCCESS){
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}

int IicPsMasterRecieve(u16 DeviceId, u8 * ptr_Recv_Buffer, int * iI2C_slave_addr)
{
	iStatus = XIicPs_MasterRecvPolled(&Iic, ptr_Recv_Buffer, 0x2, *iI2C_slave_addr);
	if (iStatus != XST_SUCCESS) {
			return XST_FAILURE;
		}
	return XST_SUCCESS;
}
