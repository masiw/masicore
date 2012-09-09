/*
 *  commonMathFunctions.c
 *  AudioUnitThreadingTest
 *
 *  Created by masi woermann on 13/08/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#include "commonMathFunctions.h"

#include "math.h"

double max(double value1, double value2) {
	
	if (value1 < value2) {
		return value2;
	}
	
	return value1;
}

double min(double value1, double value2) {
	return -max(-value1, -value2);
}


double sgn(double value) {
	
	if (value > 0) {
		return 1.0;
	} else if (value < 0) {
		return -1.0;
	} else {
		return 0.0;
	}

}

double degreesToRadians (double degrees) {
	return degrees * M_PI/180;
}
double radiansToDegrees(double radians) {
	return radians * 180/M_PI;
}