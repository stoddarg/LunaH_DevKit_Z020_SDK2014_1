/******************************************************************************
*
* Main Dev Kit Application
* Revision 1.0
*
* Notes:
* Initial Software package that is developed for the Dev Kit.  07/06/16 - EBJ
*
******************************************************************************/

#include "LApp.h"


//////////////////////////// MAIN //////////////////// MAIN //////////////
int main()
{
	// Local Variables for main()
	int i = 0;				// index
	int	menusel = 99999;	// Menu Select
	int mode = 9;			// Mode of Operation
	int enable_state = 0; 	// 0: disabled, 1: enabled
	int thres = 0;			// Trigger Threshold
	char updateint = 'N';	// switch to change integral values
	u32 databuff = 0;		// size of the data buffer
	int setBL = 0;
	int setSI = 0;
	int setLI = 0;
	int setFI = 0;

	// Initialize System
    init_platform();  		// This initializes the platform, which is ...
	ps7_post_config();
	Xil_DCacheDisable();	//
	InitializeAXIDma();		// Initialize the AXI DMA Transfer Interface
	Xil_Out32 (XPAR_AXI_GPIO_16_BASEADDR, 16384);
	Xil_Out32 (XPAR_AXI_GPIO_17_BASEADDR , 1);
	InitializeInterruptSystem(XPAR_PS7_SCUGIC_0_DEVICE_ID);

	for (i=0; i<32; i++ ) { RecvBuffer[i] = '_'; }		// Clear RecvBuffer Variable
	for (i=0; i<32; i++ ) { SendBuffer[i] = '_'; }		// Clear SendBuffer Variable

	//*******************Setup the UART **********************//
	XUartPs_Config *Config = XUartPs_LookupConfig(UART_DEVICEID);
	if (NULL == Config) { return 1;}
	Status = XUartPs_CfgInitialize(&Uart_PS, Config, Config->BaseAddress);
	if (Status != 0){ return 1;	}

	/* Conduct a Selftest for the UART */
	Status = XUartPs_SelfTest(&Uart_PS);
	if (Status != 0) { return 1; }

	/* Set to normal mode. */
	XUartPs_SetOperMode(&Uart_PS, XUARTPS_OPER_MODE_NORMAL);
	//*******************Setup the UART **********************//

	//*******************Receive and Process Packets **********************//
	Xil_Out32 (XPAR_AXI_GPIO_0_BASEADDR, 11);
	Xil_Out32 (XPAR_AXI_GPIO_1_BASEADDR, 71);
	Xil_Out32 (XPAR_AXI_GPIO_2_BASEADDR, 167);
	Xil_Out32 (XPAR_AXI_GPIO_3_BASEADDR, 2015);
/*	Xil_Out32 (XPAR_AXI_GPIO_4_BASEADDR, 12);
	Xil_Out32 (XPAR_AXI_GPIO_5_BASEADDR, 75);
	Xil_Out32 (XPAR_AXI_GPIO_6_BASEADDR, 75);
	Xil_Out32 (XPAR_AXI_GPIO_7_BASEADDR, 5);
	Xil_Out32 (XPAR_AXI_GPIO_8_BASEADDR, 25);*/
	//*******************enable the system **********************//
	Xil_Out32(XPAR_AXI_GPIO_18_BASEADDR, 1);
	//*******************Receive and Process Packets **********************//

	//******************Setup Detector and Module Objects*****************//
	//LDetector *Detector = LDetector();
	//Detector->SetMode(1); // Processed Data Mode
	//******************Setup Detector and Module Objects*****************//


	// *********** Setup the Hardware Reset GPIO ****************//
	GPIOConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	Status = XGpioPs_CfgInitialize(&Gpio, GPIOConfigPtr, GPIOConfigPtr ->BaseAddr);
	if (Status != XST_SUCCESS) { return XST_FAILURE; }
	XGpioPs_SetDirectionPin(&Gpio, SW_BREAK_GPIO, 1);
	// *********** Setup the Hardware Reset MIO ****************//

	// ******************* POLLING LOOP *******************//
	xil_printf("\n\r Turn on Local Echo: under Terminal-Setup in Tera Term \n\r");
	xil_printf(" Code is expecting a 'Return' after Each Command \n\r");
	while(1){
		sw = 0;   //  stop switch reset to 0
		XUartPs_SetOptions(&Uart_PS,XUARTPS_OPTION_RESET_RX);	// Clear UART Read Buffer
		for (i=0; i<32; i++ ) { RecvBuffer[i] = '_'; }			// Clear RecvBuffer Variable

		sleep(0.5);  // Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 0.5 s
		xil_printf("\n\r Devkit version 2.11 \n\r");
		xil_printf("MAIN MENU \n\r");
		xil_printf("*****\n\r");
		xil_printf(" 0) Set Mode of Operation\n\r");
		xil_printf(" 1) Enable or disable the system\n\r");
		xil_printf(" 2) Continuously Read of Processed Data\n\r");
		xil_printf("\n\r **Setup Parameters ** \n\r");
		xil_printf(" 3) Set Trigger Threshold\n\r");
		xil_printf(" 4) Set Integration Times (number of clock cycles * 4ns) \n\r");
		xil_printf("\n\r ** Additional Commands ** \n\r");
		xil_printf(" 5) Perform a DMA transfer of Waveform Data\n\r");
		xil_printf(" 6) Perform a DMA transfer of Processed Data\n\r");
		xil_printf(" 7) Check the Size of the Data Buffered (Max = 4095) \n\r");
		xil_printf(" 8) Clear the Processed Data Buffers\n\r");
		xil_printf(" 9) Execute Print of Data on DRAM \n\r");
		xil_printf("10) GUI Serial Transfer \n\r");
		xil_printf("11) GUI Serial Change Trigger Threshold\n\r");
		xil_printf("12) GUI Serial Change Integration Times\n\r");
		xil_printf("******\n\r");
		while (XUartPs_IsSending(&Uart_PS)) {i++;}  // Wait until Write Buffer is Sent

		// Wait for Input, Check
		// If input is valid break while and enter case statement
		// If input is invalid break and try again
		ReadCommandPoll();
		menusel = 99999;
		sscanf(RecvBuffer,"%02d",&menusel);
		if ( menusel < 0 || menusel > 13 ) {
			xil_printf(" Invalid Command: Enter 0-9 \n\r");
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
		}

		switch (menusel) { // Switch-Case Menu Select

		case 0: //Set Mode of Operation
			mode = 99; //Detector->GetMode();
			xil_printf("\n\r Waveform Data: \t Enter 0 <return>\n\r");
			xil_printf(" LPF Waveform Data: \t Enter 1 <return>\n\r");
			xil_printf(" DFF Waveform Data: \t Enter 2 <return>\n\r");
			xil_printf(" TRG Waveform Data: \t Enter 3 <return>\n\r");
			xil_printf(" Processed Data: \t Enter 4 <return>\n\r");
			ReadCommandPoll();
			sscanf(RecvBuffer,"%01d",&mode);

			if (mode < 0 || mode > 4 ) { xil_printf("Invalid Command\n\r"); break; }
			// mode = 0, AA waveform
			// mode = 1, LPF waveform
			// mode = 2, DFF waveform
			// mode = 3, TRG waveform
			// mode = 4, Processed Data
			//Detector->SetMode(mode);  // Set Mode for Detector
			Xil_Out32 (XPAR_AXI_GPIO_14_BASEADDR, ((u32)mode));
			// Register 14
			if ( mode == 0 ) { xil_printf("Transfer AA Waveforms\n\r"); }
			if ( mode == 1 ) { xil_printf("Transfer LPF Waveforms\n\r"); }
			if ( mode == 2 ) { xil_printf("Transfer DFF Waveforms\n\r"); }
			if ( mode == 3 ) { xil_printf("Transfer TRG Waveforms\n\r"); }
			if ( mode == 4 ) { xil_printf("Transfer Processed Data\n\r"); }
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			break;

		case 1: //Enable or disable the system
			xil_printf("\n\r Disable: Enter 0 <return>\n\r");
			xil_printf(" Enable: Enter 1 <return>\n\r");
			ReadCommandPoll();
			sscanf(RecvBuffer,"%01d",&enable_state);
			if (enable_state != 0 && enable_state != 1) { xil_printf("Invalid Command\n\r"); break; }
			Xil_Out32(XPAR_AXI_GPIO_18_BASEADDR, ((u32)enable_state));
			// Register 18 Out enabled, In Disabled
			if ( enable_state == 1 ) { xil_printf("DAQ Enabled\n\r"); }
			if ( enable_state == 0 ) { xil_printf("DAQ Disabled\n\r"); }
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			break;

		case 2: //Continuously Read of Processed Data
			xil_printf("\n\r ********Data Acquisition:\n\r");
			xil_printf(" Press 'q' to Stop or Press Hardware USR reset button  \n\r");
			xil_printf(" Press <return> to Start");
			ReadCommandPoll();	//Just get a '\n' to continue
			DAQ();
			sw = 0;   // broke out of the read loop, stop swith reset to 0
			break;

		case 3: //Set Threshold
			xil_printf("\n\r Existing Threshold = %d \n\r",Xil_In32(XPAR_AXI_GPIO_10_BASEADDR));
			xil_printf(" Enter Threshold (6144 to 10240) <return> \n\r");
			ReadCommandPoll();
			sscanf(RecvBuffer,"%04d",&thres);
			Xil_Out32(XPAR_AXI_GPIO_10_BASEADDR, ((u32)thres));
			xil_printf("New Threshold = %d \n\r",Xil_In32(XPAR_AXI_GPIO_10_BASEADDR));
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			break;

		case 4: //Set Integration Times
			xil_printf("\n\r Existing Integration Times \n\r");
			xil_printf(" Time = 0 ns is when the Pulse Crossed Threshold \n\r");
			xil_printf(" Baseline Integral Window \t [-200ns,%dns] \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_0_BASEADDR))*4 );
			xil_printf(" Short Integral Window \t [-200ns,%dns] \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_1_BASEADDR))*4 );
			xil_printf(" Long Integral Window  \t [-200ns,%dns] \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_2_BASEADDR))*4 );
			xil_printf(" Full Integral Window  \t [-200ns,%dns] \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_3_BASEADDR))*4 );

			xil_printf(" Change: (Y)es (N)o <return>\n\r");
			ReadCommandPoll();
			sscanf(RecvBuffer,"%c",&updateint);
			if (updateint == 'N' || updateint == 'n') { break; }
			if (updateint == 'Y' || updateint == 'y') { SetIntegrationTimes(0); }
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s

			break;

		case 5: //Perform a DMA transfer
			xil_printf("\n\r Perform DMA Transfer of Waveform Data\n\r");
			xil_printf(" Press 'q' to Exit Transfer  \n\r");
			Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x48, 0xa000000);
			Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x58 , 65536);
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			PrintData();		// Display data to console.
			sw = 0;   // broke out of the read loop, stop swith reset to 0
			break;

		case 6: //Perform a DMA transfer of Processed data
			xil_printf("\n\r ********Perform DMA Transfer of Processed Data \n\r");
			xil_printf(" Press 'q' to Exit Transfer  \n\r");
			//Xil_Out32 (XPAR_AXI_GPIO_18_BASEADDR, 0);	// Disable : GPIO Reg Capture Module
			Xil_Out32 (XPAR_AXI_GPIO_15_BASEADDR, 1);	// Enable: GPIO Reg to Readout Data MUX
			//sleep(1);				// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x48, 0xa000000); // Transfer from BRAM to DRAM, start address 0xa000000, 16-bit length
			Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x58 , 65536);
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			Xil_Out32 (XPAR_AXI_GPIO_15_BASEADDR, 0); 	// Disable: GPIO Reg turn off Readout Data MUX
			ClearBuffers();
			PrintData();								// Display data to console.
			//Xil_Out32 (XPAR_AXI_GPIO_18_BASEADDR, 1);	// Enable : GPIO Reg Capture Module
			sw = 0;   // broke out of the read loop, stop swith reset to 0
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			break;

		case 7: //Check the Size of the Data Buffers
			databuff = Xil_In32 (XPAR_AXI_GPIO_11_BASEADDR);
			xil_printf("\n\r BRAM Data Buffer Size = %d \n\r",databuff);
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			break;

		case 8: //Clear the processed data buffers
			xil_printf("\n\r Clear the Data Buffers\n\r");
			ClearBuffers();
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			break;

		case 9: //Print DMA Data
			xil_printf("\n\r Print Data\n\r");
			PrintData();
			break;
		case 10: //Transfer data over serial port	// Skips setting integrals, threshold	//Difference is this doesn't save to sd, it prints out the data for us
			//xil_printf("321");	//echo back to the gui that the request was received
			mode = 0;
			Xil_Out32 (XPAR_AXI_GPIO_14_BASEADDR, ((u32)mode));	//sets mode to transfer AA waveforms
			sleep(1);
			enable_state = 1;
			Xil_Out32(XPAR_AXI_GPIO_18_BASEADDR, ((u32)enable_state));	//enables the system
			sleep(1);
			getWFDAQ();
			break;
		case 11: //change threshold over the serial connection
			xil_printf("Enter the new threshold: <enter>\n");
			ReadCommandPoll();
			sscanf(RecvBuffer,"%04d",&thres);
			Xil_Out32(XPAR_AXI_GPIO_10_BASEADDR, ((u32)thres));
			xil_printf("New Threshold = %d \n\r",Xil_In32(XPAR_AXI_GPIO_10_BASEADDR));
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			break;
		case 12: //change integrals over the serial connection
			xil_printf("Enter each integral time followed by <enter>");
			ReadCommandPoll();
			sscanf(RecvBuffer,"%04d",&setBL);
			ReadCommandPoll();
			sscanf(RecvBuffer,"%04d",&setSI);
			ReadCommandPoll();
			sscanf(RecvBuffer,"%04d",&setLI);
			ReadCommandPoll();
			sscanf(RecvBuffer,"%04d",&setFI);

			Xil_Out32 (XPAR_AXI_GPIO_0_BASEADDR, ((u32)((setBL+52)/4)));	//set baseline int time
			Xil_Out32 (XPAR_AXI_GPIO_1_BASEADDR, ((u32)((setSI+52)/4)));	//set short int time
			Xil_Out32 (XPAR_AXI_GPIO_2_BASEADDR, ((u32)((setLI+52)/4)));	//set long int time
			Xil_Out32 (XPAR_AXI_GPIO_3_BASEADDR, ((u32)((setFI+52)/4)));	//set full int time

			//echo back the changed values //for checking
			xil_printf("  Inputs Rounded to the Nearest 4 ns : Number of Samples\n\r");
			xil_printf("  Baseline Integral Window  [-200ns,%dns]: %d \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_0_BASEADDR))*4, 38+Xil_In32(XPAR_AXI_GPIO_0_BASEADDR) );
			xil_printf("  Short Integral Window 	  [-200ns,%dns]: %d \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_1_BASEADDR))*4, 38+Xil_In32(XPAR_AXI_GPIO_1_BASEADDR));
			xil_printf("  Long Integral Window      [-200ns,%dns]: %d \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_2_BASEADDR))*4, 38+Xil_In32(XPAR_AXI_GPIO_2_BASEADDR));
			xil_printf("  Full Integral Window      [-200ns,%dns]: %d \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_3_BASEADDR))*4, 38+Xil_In32(XPAR_AXI_GPIO_3_BASEADDR));
			break;
		case 13: //Transfer processed data over the serial port
			mode = 4;
			Xil_Out32 (XPAR_AXI_GPIO_14_BASEADDR, ((u32)mode));	//sets mode to processed data
			sleep(1);
			enable_state = 1;
			Xil_Out32(XPAR_AXI_GPIO_18_BASEADDR, ((u32)enable_state)); //enables the system
			sleep(1);
			getWFDAQ();
			break;
		default :
			break;
		} // End Switch-Case Menu Select

	}	// ******************* POLLING LOOP *******************//


    cleanup_platform();  // Clean up the platform, which is ...

    return 0;
}
//////////////////////////// MAIN //////////////////// MAIN //////////////

//////////////////////////// InitializeAXIDma////////////////////////////////
// Sets up the AXI DMA
int InitializeAXIDma(void) {
	u32 tmpVal_0;
	u32 tmpVal_1;

	tmpVal_0 = 0;
	tmpVal_1 = 0;

	tmpVal_0 = Xil_In32(XPAR_AXI_DMA_0_BASEADDR +  0x30);

	tmpVal_0 = tmpVal_0 | 0x1001; //<allow DMA to produce interrupts> 0 0 <run/stop>

	Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x30, tmpVal_0);
	tmpVal_1 = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x30);

	return 0;
}
//////////////////////////// InitializeAXIDma////////////////////////////////

//////////////////////////// InitializeInterruptSystem////////////////////////////////
int InitializeInterruptSystem(u16 deviceID) {
	int Status;

	GicConfig = XScuGic_LookupConfig (deviceID);

	if(NULL == GicConfig) {

		return XST_FAILURE;
	}

	Status = XScuGic_CfgInitialize(&InterruptController, GicConfig, GicConfig->CpuBaseAddress);
	if(Status != XST_SUCCESS) {
		return XST_FAILURE;

	}

	Status = SetUpInterruptSystem(&InterruptController);
	if(Status != XST_SUCCESS) {
		return XST_FAILURE;

	}

	Status = XScuGic_Connect (&InterruptController,
			XPAR_FABRIC_AXI_DMA_0_S2MM_INTROUT_INTR,
			(Xil_ExceptionHandler) InterruptHandler, NULL);
	if(Status != XST_SUCCESS) {
		return XST_FAILURE;

	}

	XScuGic_Enable(&InterruptController, XPAR_FABRIC_AXI_DMA_0_S2MM_INTROUT_INTR );

	return XST_SUCCESS;

}
//////////////////////////// InitializeInterruptSystem////////////////////////////////


//////////////////////////// Interrupt Handler////////////////////////////////
void InterruptHandler (void ) {

	u32 tmpValue;
	tmpValue = Xil_In32(XPAR_AXI_DMA_0_BASEADDR + 0x34);
	tmpValue = tmpValue | 0x1000;
	Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x34, tmpValue);

	global_frame_counter++;
}
//////////////////////////// Interrupt Handler////////////////////////////////


//////////////////////////// SetUp Interrupt System////////////////////////////////
int SetUpInterruptSystem(XScuGic *XScuGicInstancePtr) {
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT, (Xil_ExceptionHandler)XScuGic_InterruptHandler, XScuGicInstancePtr);
	Xil_ExceptionEnable();
	return XST_SUCCESS;

}
//////////////////////////// SetUp Interrupt System////////////////////////////////

//////////////////////////// ReadCommandPoll////////////////////////////////
// Function used to clear the read buffer
// Read In new command, expecting a <return>
// Returns buffer size read
int ReadCommandPoll() {
	u32 rbuff = 0;			// read buffer size returned
	int i = 0; 				// index
	XUartPs_SetOptions(&Uart_PS,XUARTPS_OPTION_RESET_RX);	// Clear UART Read Buffer
	for (i=0; i<32; i++ ) { RecvBuffer[i] = '_'; }			// Clear RecvBuffer Variable
	while (!(RecvBuffer[rbuff-1] == '\n' || RecvBuffer[rbuff-1] == '\r' || RecvBuffer[rbuff-1] == 'd')) {
		rbuff += XUartPs_Recv(&Uart_PS, &RecvBuffer[rbuff],(32 - rbuff));
		sleep(0.1);			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 0.1 s
	}
	return rbuff;

}
//////////////////////////// ReadCommandPoll////////////////////////////////


//////////////////////////// Set Integration Times ////////////////////////////////
// wfid = 	0 for AA
//			1 for DFF
//			2 for LPF
// At the moment, the software is expecting a 5 char buffer.  This needs to be fixed.
void SetIntegrationTimes(u8 wfid){
	int integrals[8];
	u32 setsamples[8];
	int i = 0;

	for (i = 0; i<8; i++) {integrals[i] = 0; setsamples[i] = 0;}

	switch (wfid) { // Switch-Case for performing set integrals

			case 0: //AA Integrals
				xil_printf("  Enter Baseline Stop Time in ns: -52 to 0 <return> \t");
				ReadCommandPoll();
				sscanf(RecvBuffer,"%d",&integrals[0]);
				xil_printf("\n\r");

				xil_printf("  Enter Short Integral Stop Time in ns: -52 to 8000 <return> \t");
				ReadCommandPoll();
				sscanf(RecvBuffer,"%d",&integrals[1]);
				xil_printf("\n\r");

				xil_printf("  Enter Long Integral Stop Time in ns: -52 to 8000 <return> \t");
				ReadCommandPoll();
				sscanf(RecvBuffer,"%d",&integrals[2]);
				xil_printf("\n\r");

				xil_printf("  Enter Full Integral Stop Time in ns: -52 to 8000 <return> \t");
				ReadCommandPoll();
				sscanf(RecvBuffer,"%d",&integrals[3]);
				xil_printf("\n\r");

				setsamples[0] = ((u32)((integrals[0]+52)/4));
				setsamples[1] = ((u32)((integrals[1]+52)/4));
				setsamples[2] = ((u32)((integrals[2]+52)/4));
				setsamples[3] = ((u32)((integrals[3]+52)/4));

				Xil_Out32 (XPAR_AXI_GPIO_0_BASEADDR, setsamples[0]);
				Xil_Out32 (XPAR_AXI_GPIO_1_BASEADDR, setsamples[1]);
				Xil_Out32 (XPAR_AXI_GPIO_2_BASEADDR, setsamples[2]);
				Xil_Out32 (XPAR_AXI_GPIO_3_BASEADDR, setsamples[3]);

				xil_printf("\n\r  Inputs Rounded to the Nearest 4 ns : Number of Samples\n\r");
				xil_printf("  Baseline Integral Window  [-200ns,%dns]: %d \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_0_BASEADDR))*4, 38+Xil_In32(XPAR_AXI_GPIO_0_BASEADDR) );
				xil_printf("  Short Integral Window 	  [-200ns,%dns]: %d \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_1_BASEADDR))*4, 38+Xil_In32(XPAR_AXI_GPIO_1_BASEADDR));
				xil_printf("  Long Integral Window      [-200ns,%dns]: %d \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_2_BASEADDR))*4, 38+Xil_In32(XPAR_AXI_GPIO_2_BASEADDR));
				xil_printf("  Full Integral Window      [-200ns,%dns]: %d \n\r",-52 + ((int)Xil_In32(XPAR_AXI_GPIO_3_BASEADDR))*4, 38+Xil_In32(XPAR_AXI_GPIO_3_BASEADDR));

				break;

			case 1://DFF Integrals
				xil_printf("Enter Baseline Stop Time in ns: -32 to 0 <return> \t");
				ReadCommandPoll();
				sscanf(RecvBuffer,"%d",&integrals[0]);
				xil_printf("\n\r");

				xil_printf("Enter Integral Stop Time in ns: 0 to 500 <return> \t");
				ReadCommandPoll();
				sscanf(RecvBuffer,"%d",&integrals[1]);
				xil_printf("\n\r");

				setsamples[0] = ((u32)((integrals[0]+32)/4));
				setsamples[1] = ((u32)((integrals[1])/4));

		/*		Xil_Out32 (XPAR_AXI_GPIO_7_BASEADDR, setsamples[0]);
				Xil_Out32 (XPAR_AXI_GPIO_8_BASEADDR, setsamples[1]);*/

				xil_printf("Inputs Rounded to the Nearest 4 ns : Number of Samples");
		/*		xil_printf("Baseline Integral Window  [-32ns,%dns]: %d \n\r",-32 + ((int)Xil_In32(XPAR_AXI_GPIO_7_BASEADDR))*4, 9+Xil_In32(XPAR_AXI_GPIO_7_BASEADDR) );
				xil_printf("Integral Window 	      [0ns,%dns]: %d \n\r",((int)Xil_In32(XPAR_AXI_GPIO_8_BASEADDR))*4, 1+Xil_In32(XPAR_AXI_GPIO_8_BASEADDR));*/

				break;

			case 2://LPF Integrals
				xil_printf("Enter Baseline Stop Time in ns: -60 to 0 <return> \t");
				ReadCommandPoll();
				sscanf(RecvBuffer,"%d",&integrals[0]);
				xil_printf("\n\r");

				xil_printf("Enter Tail Integral Stop Time in ns: 200 to 8000 <return> \t");
				ReadCommandPoll();
				sscanf(RecvBuffer,"%d",&integrals[1]);
				xil_printf("\n\r");

				xil_printf("Enter Full Integral Stop Time in ns: 0 to 8000 <return> \t");
				ReadCommandPoll();
				sscanf(RecvBuffer,"%d",&integrals[2]);
				xil_printf("\n\r");

				setsamples[0] = ((u32)((integrals[0]+60)/4));
				setsamples[1] = ((u32)((integrals[1])/4));
				setsamples[2] = ((u32)((integrals[1])/4));

/*				Xil_Out32 (XPAR_AXI_GPIO_4_BASEADDR, setsamples[0]);
				Xil_Out32 (XPAR_AXI_GPIO_5_BASEADDR, setsamples[1]);
				Xil_Out32 (XPAR_AXI_GPIO_6_BASEADDR, setsamples[2]);*/

/*				xil_printf("Inputs Rounded to the Nearest 4 ns : Number of Samples");
				xil_printf("Baseline Integral Window  [-32ns,%dns]: %d \n\r",-32 + ((int)Xil_In32(XPAR_AXI_GPIO_4_BASEADDR))*4, 16+Xil_In32(XPAR_AXI_GPIO_4_BASEADDR) );
				xil_printf("Tail Integral Window 	  [200ns,%dns]: %d \n\r",((int)Xil_In32(XPAR_AXI_GPIO_5_BASEADDR))*4, 1+Xil_In32(XPAR_AXI_GPIO_5_BASEADDR));
				xil_printf("Full Integral Window 	  [0ns,%dns]: %d \n\r",((int)Xil_In32(XPAR_AXI_GPIO_6_BASEADDR))*4, 1+Xil_In32(XPAR_AXI_GPIO_6_BASEADDR));*/

				break;

			default:
				break;
	}

	return;
}
//////////////////////////// Set Integration Times ////////////////////////////////

//////////////////////////// PrintData ////////////////////////////////
int PrintData( ){
	u32 data;
	int dram_addr;

	//Read all data from DRAM
//	int dram_base = 0xa000000;
//	int dram_cieling = 0xa00ffff; //read out data from all integration channels

	// Read only Adj Average data from DRAM
	int dram_base = 0xa000000;
	int dram_cieling = 0xA004000; //read out just adjacent average (0xA004000 - 0xa000000 = 16384)

	Xil_DCacheInvalidateRange(0x00000000, 65536);

	for (dram_addr = dram_base; dram_addr <= dram_cieling; dram_addr+=4){
		if (!sw) { sw = XGpioPs_ReadPin(&Gpio, SW_BREAK_GPIO); } //read pin
		data = Xil_In32(dram_addr);
		xil_printf("%d\r\n",data);
		XUartPs_Recv(&Uart_PS, &RecvBuffer, 32);
		if ( RecvBuffer[0] == 'q' ) { sw = 1;  }
		if(sw) { return sw; }
	}

	return sw;
}
//////////////////////////// PrintData ////////////////////////////////


//////////////////////////// Clear Processed Data Buffers ////////////////////////////////
void ClearBuffers() {
	Xil_Out32(XPAR_AXI_GPIO_9_BASEADDR,1);
	sleep(1);						// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
	Xil_Out32(XPAR_AXI_GPIO_9_BASEADDR,0);
}
//////////////////////////// Clear Processed Data Buffers ////////////////////////////////

//////////////////////////// DAQ ////////////////////////////////
int DAQ(){
	int buffsize; 	//BRAM buffer size
	int dram_addr;	// DRAM Address
	static int filesWritten = 0;

	XUartPs_SetOptions(&Uart_PS,XUARTPS_OPTION_RESET_RX);

	Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x48, 0xa000000); 		// DMA Transfer Step 1
	Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x58 , 65536);			// DMA Transfer Step 2
	sleep(1);						// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
	ClearBuffers();												// Clear Buffers.
	// Capture garbage in DRAM
	for (dram_addr = 0xa000000; dram_addr <= 0xA004000; dram_addr+=4){Xil_In32(dram_addr);}

	while(1){
		buffsize = Xil_In32 (XPAR_AXI_GPIO_11_BASEADDR);
		if (!sw) { sw = XGpioPs_ReadPin(&Gpio, SW_BREAK_GPIO); } //read pin
		XUartPs_Recv(&Uart_PS, &RecvBuffer, 32);
		if ( RecvBuffer[0] == 'q' ) { sw = 1; }
		if(sw) { return sw;	}

		if(buffsize >= 4095){
			//Xil_Out32 (XPAR_AXI_GPIO_18_BASEADDR, 0); // Disable Capture Module in FPGA
			Xil_Out32 (XPAR_AXI_GPIO_15_BASEADDR, 1);
			//sleep(10);  // Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 10 s
			Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x48, 0xa000000);
			Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x58 , 65536);
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			Xil_Out32 (XPAR_AXI_GPIO_15_BASEADDR, 0);
			//Xil_Out32(XPAR_AXI_GPIO_18_BASEADDR, 1);
			ClearBuffers();
			sw = ReadDataIn(filesWritten);
			++filesWritten;
			// PrintData();
		}
	}

	return sw;
}
//////////////////////////// DAQ ////////////////////////////////

//////////////////////////// getWFDAQ ////////////////////////////////

int getWFDAQ(){
	int buffsize; 	//BRAM buffer size
	int dram_addr;	// DRAM Address

	XUartPs_SetOptions(&Uart_PS,XUARTPS_OPTION_RESET_RX);

	Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x48, 0xa000000); 		// DMA Transfer Step 1
	Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x58 , 65536);			// DMA Transfer Step 2
	sleep(1);						// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
	ClearBuffers();												// Clear Buffers.
	// Capture garbage in DRAM
	for (dram_addr = 0xa000000; dram_addr <= 0xA004000; dram_addr+=4){Xil_In32(dram_addr);}

	while(1){
		buffsize = Xil_In32 (XPAR_AXI_GPIO_11_BASEADDR);	// what does this look at?
		if (!sw) { sw = XGpioPs_ReadPin(&Gpio, SW_BREAK_GPIO); } //read pin
		XUartPs_Recv(&Uart_PS, &RecvBuffer, 32);
		if ( RecvBuffer[0] == 'q' ) { sw = 1; }
		if(sw) { return sw;	}

		if(buffsize >= 4095){
			//Xil_Out32 (XPAR_AXI_GPIO_18_BASEADDR, 0); // Disable Capture Module in FPGA
			Xil_Out32 (XPAR_AXI_GPIO_15_BASEADDR, 1);
			Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x48, 0xa000000);
			Xil_Out32 (XPAR_AXI_DMA_0_BASEADDR + 0x58 , 65536);
			sleep(1); 			// Built in Latency ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 1 s
			Xil_Out32 (XPAR_AXI_GPIO_15_BASEADDR, 0);
			//Xil_Out32(XPAR_AXI_GPIO_18_BASEADDR, 1);
			ClearBuffers();
			PrintData();
		}
	}
	return sw;
}

//////////////////////////// getWFDAQ ////////////////////////////////
