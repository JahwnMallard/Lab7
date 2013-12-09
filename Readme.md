#ADC library
##API

C2C John Miller, ECE 382
ADC library for the MSP430, designed for the ECE382 robot. 

	
-void `initADC()`
	- initializes the pins and timer of the ADC system. Left sensor(A3) is on 1.3, Center Sensor(A4) is on 1.4, and Right Sensor(A5) is on 1.5

-int `readLeftSensor()`
	- Reads the value on the left sensor and returns it
	
-int `readCenterSensor()`
	- Reads the value on the center sensor and returns it
	
-int `readRightSensor()`
	- Reads the value on the right sensor and returns it
	