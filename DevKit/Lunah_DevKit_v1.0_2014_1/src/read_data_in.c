/*
 * read_data_in.c
 *
 *  Created on: Feb 14, 2017
 *      Author: GStoddard
 */

#include "read_data_in.h"

int ReadDataIn(int numFilesWritten){

	struct event_raw *data_array;
	data_array = (double *)malloc(sizeof(double)*512);

	array_index = 0;
	dram_addr = 0;
	nevents = 0;
	//bl_sum = 0;
	bl1 = 0.0;
	bl2 = 0.0;
	bl3 = 0.0;
	bl4 = 0.0;
	bl_avg = 0.0;
	diff = 0;
	howFar = 0;

	dram_addr = 0xa000000;		// Read only Adj Average data from DRAM
	dram_ceiling = 0xA004000; 	//read out just adjacent average (0xA004000 - 0xa000000 = 16384)	//167788544

	Xil_DCacheInvalidateRange(0x00000000, 65536);

	while (dram_addr <= dram_ceiling) {

		data = Xil_In32(dram_addr);
		diff = (dram_ceiling - dram_addr) / 4;

		if( data == 111111 && diff > 7 ) {
			data_array[array_index].time = (double)Xil_In32(dram_addr + 4) * 262.144e-6;
			// trying out using just struct of ints (not doubles)
			data_array[array_index].total_events = (double)Xil_In32(dram_addr + 8);
			data_array[array_index].event_num = (double)Xil_In32(dram_addr + 12);
			data_array[array_index].bl = (double)Xil_In32(dram_addr + 16) / ( 16.0 * 38.0 );
			//++nevents;
			//bl_sum += data_array[array_index].bl;
			bl4 = bl3;
			bl3 = bl2;
			bl2 = bl1;
			bl1 = data_array[array_index].bl;
			bl_avg = (bl1 + bl2 + bl3 + bl4) / 4;

			data_array[array_index].si = ((double)Xil_In32(dram_addr + 20) / 16.0) - bl_avg * 73.0;
			data_array[array_index].li = ((double)Xil_In32(dram_addr + 24) / 16.0) - bl_avg * 169.0;
			data_array[array_index].fi = ((double)Xil_In32(dram_addr + 28) / 16.0) - bl_avg * 1551.0;
			data_array[array_index].psd = data_array[array_index].si / (data_array[array_index].li - data_array[array_index].si);
			data_array[array_index].energy = 1.0 * data_array[array_index].fi + 0.0;
			++array_index;
			dram_addr = dram_addr + 32;		//align the loop with the data
		}
		else {
			dram_addr += 4;
		}

	}	// end of while loop

	static FIL file1;
	static FATFS fatfs;
	char filename[15];
	char *SD_File;

	FRESULT res;				// Return variable for SD functions
	uint numBytesWritten;
	int fileSize = 8 * 9 * array_index;	// 8 bytes * 9 values * number of rows filled in array

	Xil_DCacheFlush();
	Xil_DCacheDisable();

	if( numFilesWritten == 0 ){	// The first iteration we need to unmount anything that was already there and
	res = f_mount(0, NULL);		// mount the SD Card so that we may open, write, and close files on it
	res = f_mount(0, &fatfs);	// This is the line that initializes the FAT File System
	}

	sprintf(filename, "test%04d.bin",4143);	// fills in "test0xxx.bin" with the number of times we have written a file
	SD_File = (char *)filename;							// so the final name is something like "test0001.bin" -> "test9999.bin"
	res = f_open(&file1, SD_File, FA_OPEN_ALWAYS | FA_WRITE);	// Open the file if it exists, if not create a new file; file has write permission

	howFar = 36720 * numFilesWritten;					// Calculate where to put the file pointer for writing
	res = f_lseek(&file1, howFar);						// Move the file write pointer to somewhere in the file

	res = f_write(&file1, (const void*)data_array, fileSize, &numBytesWritten);	// Write the array data from above to the file, returns the #bytes written

	res = f_close(&file1);		// Close the file on the SD card

	//res = f_mount(0, NULL);	// Unmount the SD Card	// don't un-comment this line or the SD card will unmount and then be unable to re-mount correctly

	free(data_array);			// Return the space reserved for the array back to the OS
	return sw;
} //eof
