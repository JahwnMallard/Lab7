/*
 * ADC_Library.h
 *
 *  Created on: Dec 5, 2013
 *      Author: C2C John Miller
 */

#ifndef ADC_LIBRARY_H_
#define ADC_LIBRARY_H_

//initializes the ADC system
void initADC();

//reads from the right sensor and returns its value
int readRightSensor();

//reads from the left sensor and returns its value
int readLeftSensor();

//reads from the center sensor and returns its value
int readCenterSensor();




#endif /* ADC_LIBRARY_H_ */
