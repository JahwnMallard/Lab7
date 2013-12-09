/*
 * ADC_Library.h
 *
 *  Created on: Dec 5, 2013
 *      Author: Administrator
 */

#ifndef ADC_LIBRARY_H_
#define ADC_LIBRARY_H_

void initADC();
void changeInputChannel(char channel);
void startConversion();
//#pragma vector=ADC10_VECTOR;
//__interrupt void ADC10_ISR(void);




#endif /* ADC_LIBRARY_H_ */
