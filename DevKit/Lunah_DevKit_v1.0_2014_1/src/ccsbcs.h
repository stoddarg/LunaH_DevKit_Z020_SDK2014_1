/*
 * ccsbcs.h
 *
 *  Created on: Apr 10, 2017
 *      Author: GStoddard
 */

#ifndef CCSBCS_H_
#define CCSBCS_H_

/* Unicode support functions */
#if _USE_LFN						/* Unicode - OEM code conversion */
WCHAR ff_convert (WCHAR, UINT);		/* OEM-Unicode bidirectional conversion */
WCHAR ff_wtoupper (WCHAR);			/* Unicode upper-case conversion */
#endif

#endif /* CCSBCS_H_ */
