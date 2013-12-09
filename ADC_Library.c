/*
 * ADC_Library.c
 *
 *  Created on: Dec 5, 2013
 *      Author: Administrator
 */

#include <msp430.h>
#include "ADC_Library.h"

void initADC() {

	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK
	ADC10CTL1 |= ADC10DIV_7; //slow clock to slowest setting

}

int readLeftSensor() {
	ADC10CTL0 &= ~ENC;                   // Allows for channel switching
	ADC10CTL1 = INCH_3;			         //set to channel A3
	ADC10AE0 |= BIT3;				     //enable channel A3
	ADC10CTL0 |= ENC + ADC10SC;          // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);	 //turn cpu off
	return ADC10MEM;
}

int readRightSensor() {
	ADC10CTL0 &= ~ENC;             // Allows for channel switching
	ADC10CTL1 = INCH_5;			   // Set to channel A5
	ADC10AE0 |= BIT5;			   // Enable channel A5
	ADC10CTL0 |= ENC + ADC10SC;    // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE); //turn cpu off
	return ADC10MEM;
}

int readCenterSensor() {
	ADC10CTL0 &= ~ENC;             // Allows for channel switching
	ADC10CTL1 = INCH_4;			   // Set to channel A4
	ADC10AE0 |= BIT4;			   // Enable channel A4
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);
	return ADC10MEM;
}

//#pragma vector=ADC10_VECTOR
//__interrupt void ADC10_ISR(void) {
//	__bic_SR_register_on_exit(CPUOFF);
//	// Clear CPUOFF bit from 0(SR)
//}
