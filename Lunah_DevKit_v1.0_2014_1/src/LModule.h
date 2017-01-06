/*
 * LModule.h
 *
 *  Created on: Jul 5, 2016
 *      Author: EJohnson
 *
 *      Object of the parameters used for each Module.
 *
 */

#ifndef LMODULE_H_
#define LMODULE_H_

#include <xil_io.h>

u32 Bias;
u8 PMTID;

void LModule();

void SetID(u8 val) {PMTID = val;}
void SetBias(u32 val);

u8 GetID() {return PMTID;}
u32 GetBias() {return Bias;}

#endif /* LMODULE_H_ */
