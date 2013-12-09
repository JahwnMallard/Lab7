/*
 * ADC_Library.c
 *
 *  Created on: Dec 5, 2013
 *      Author: Administrator
 */

#include <msp430.h>
#include "ADC_Library.h"

void initADC() {
	WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 = INCH_3;                       // input A2,
	ADC10AE0 |= BIT3;                         // PA.1 ADC option select
	ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	ADC10AE0 |= BIT5;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK
}

void changeInputChannel(char channel) {
	ADC10CTL0 &= ~ENC;             // Sampling and conversion start
	ADC10CTL1 &= ~(INCH_3|INCH_4|INCH_5);
	ADC10CTL1 |= channel;
}

void startConversion() {
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);
	// LPM0, ADC10_ISR will force exit
}

int readLeftSensor(){
	changeInputChannel( INCH_3);
	startConversion();
	return ADC10MEM;
}

int readRightSensor(){
	changeInputChannel(INCH_5);
	startConversion();
	return ADC10MEM;
}

int readCenterSensor(){
	changeInputChannel(INCH_4);
	startConversion();
	return ADC10MEM;
}

//#pragma vector=ADC10_VECTOR
//__interrupt void ADC10_ISR(void) {
//	__bic_SR_register_on_exit(CPUOFF);
//	// Clear CPUOFF bit from 0(SR)
//}
