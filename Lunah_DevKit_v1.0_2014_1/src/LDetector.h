/*
 * LDetector.h
 *
 *  Created on: Jul 6, 2016
 *      Author: EJohnson
 *
 *      Object of the parameters used for the detector.
 */

#ifndef LDETECTOR_H_
#define LDETECTOR_H_

#include <xil_io.h>

u32 Thres;
u32 Int_Start;
u32 Int_Stop1;
u32 Int_Stop2;
u32 Int_Stop3;
u32 Int_Stop4;
u8 Mode; 			//Mode of Operation Waveform (0) or Processed Data (1)
u8 Enable_State; 	// 0: Disabled, 1: Enabled
void LDetector();

void SetThres(u32 val) {Thres = val;}
void SetIntgralWin(u32 val0, u32 val1, u32 val2, u32 val3, u32 val4) {
	Int_Start = val0;
	Int_Stop1 = val1;
	Int_Stop2 = val2;
	Int_Stop3 = val3;
	Int_Stop4 = val4;
}
void SetMode(u8 val) {Mode = val;}
void Enable() {Enable_State = 1;}
void Disable() {Enable_State = 0;}

u8  GetMode() {return Mode;}
u32 GetThreshold() {return Thres;}


#endif /* LDETECTORPARAMS_H_ */
