/*
 *  Color.cpp
 *  masicore
 *
 *  Created by masi on 17/06/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#include "Color.h"

#include <climits>
#include <cmath>
#include "commonMathFunctions.h"

/*
double max(double value1, double value2) {
	
	if (value1 < value2) {
		return value2;
	}
	
	return value1;
}

double min(double value1, double value2) {
	return -max(-value1, -value2);
}
*/

namespace masi {

	Color::Color() {
		setIntValue(0);
	}
	
	Color::Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
		setRed(red);
		setGreen(green);
		setBlue(blue);
		setAlpha(alpha);
	}
	Color::Color(unsigned int value) {
		setIntValue(value);
	}
	
	Color::Color(float red, float green, float blue, float alpha) {
		setRedF(red);
		setGreenF(green);
		setBlueF(blue);
		setAlphaF(alpha);
	}
	
	unsigned char Color::getRed() {
		return ((unsigned char *)&_intValue)[0];
	}
	void Color::setRed(unsigned char value) {
		((unsigned char *)&_intValue)[0] = value;
	}
	
	unsigned char Color::getGreen() {
		return ((unsigned char *)&_intValue)[1];
	}
	void Color::setGreen(unsigned char value) {
		((unsigned char *)&_intValue)[1] = value;
	}
	
	unsigned char Color::getBlue() {
		return ((unsigned char *)&_intValue)[2];
	}
	void Color::setBlue(unsigned char value) {
		((unsigned char *)&_intValue)[2] = value;
	}
	
	unsigned char Color::getAlpha() {
		return ((unsigned char *)&_intValue)[3];
	}
	void Color::setAlpha(unsigned char value) {
		((unsigned char *)&_intValue)[3] = value;
	}
	
	unsigned int Color::getIntValue() {
		return _intValue;
	}
	void Color::setIntValue(unsigned int value) {
		_intValue = value;
	}
	
	unsigned char convertToUnsignedChar(float value) {
		
		value = min(1.0, value);
		value = max(0.0, value);
		
		return (unsigned char) floor(value * UCHAR_MAX);
	}
	
	float Color::getRedF() {
		return getRed() / UCHAR_MAX;
	}
	void Color::setRedF(float value) {
		
		setRed(convertToUnsignedChar(value));
	}
	
	float Color::getGreenF() {
		return getGreen() / UCHAR_MAX;
	}
	void Color::setGreenF(float value) {
		
		setRed(convertToUnsignedChar(value));
	}
	
	float Color::getBlueF() {
		return getBlue() / UCHAR_MAX;
	}
	void Color::setBlueF(float value) {
		
		setBlue(convertToUnsignedChar(value));
	}
	
	float Color::getAlphaF() {
		return getAlpha() / UCHAR_MAX;
	}
	void Color::setAlphaF(float value) {
		
		setAlpha(convertToUnsignedChar(value));
	}
	
}