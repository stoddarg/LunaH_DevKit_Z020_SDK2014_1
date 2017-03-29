/*
 * LNumDigits.c
 *
 *  Created on: Mar 22, 2017
 *      Author: GStoddard
 */
#include "LNumDigits.h"

int LNumDigits(int n) {
	if(n < 0) return 99;		//return error
	if(n < 10) return 1;
	if(n < 100) return 2;
	if(n < 1000) return 3;
	if(n < 10000) return 4;
	if(n < 100000) return 5;
	if(n < 1000000) return 6;
	if(n < 10000000) return 7;
	if(n < 100000000) return 8;
	if(n < 1000000000) return 9;
	return 10;
}
