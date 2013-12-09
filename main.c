#include <msp430.h> 
#include "ADC_Library.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    P1DIR |= 0x01;                            // Set P1.0 to output direction
    P1DIR |= 0x06;                            // Set P1.0 to output direction
    P1OUT &= ~0x01;
    P1OUT &= ~0x06;
    initADC();
    while(1){
    	if (readLeftSensor()>0x16C){
    		P1OUT |= 0x01;                        // Set P1.0 LED on
    	}else{
    		P1OUT &= ~0x01;
    	}

    	if (readRightSensor()>0x16C){
    		P1OUT |= 0x06;                        // Set P1.0 LED on
    	}else{
    		P1OUT &= ~0x06;
    	}
    }
    return 0;
}
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);
	// Clear CPUOFF bit from 0(SR)
}
