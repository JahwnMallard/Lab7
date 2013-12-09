#include <msp430.h> 
#include "ADC_Library.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    P1DIR |= BIT0;                            // Set P1.0 to output direction
    P1DIR |= BIT6;                            // Set P1.6 to output direction

    P1OUT &= ~BIT0;
    P1OUT &= ~BIT6;

    initADC();
    int output;
    while(1){
    	output = readLeftSensor();
    	if (output>0x0340){
    		P1OUT |= BIT0;                        // Set P1.0 LED on
    	}else{
    		P1OUT &= ~BIT0;
    	}

    	_delay_cycles(1000);

    	output = readRightSensor();
    	if (output>0x0340){
    		P1OUT |= BIT6;                        // Set P1.0 LED on
    	}else{
    		P1OUT &= ~BIT6;
    	}
    	_delay_cycles(1000);
    }
    return 0;
}
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);
	// Clear CPUOFF bit from 0(SR)
}
