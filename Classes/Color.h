/*
 *  Color.h
 *  masicore
 *
 *  Created by masi on 17/06/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#ifndef COLOR_H_
#define COLOR_H_

#include "Object.h"

namespace masi {

	class Color : public Object {
		
	private:
		unsigned int _intValue = 0;
		
	public:
		Color();
		Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
		Color(unsigned int value);
		Color(float red, float green, float blue, float alpha);
		
		unsigned char getRed();
		void setRed(unsigned char value);
		
		unsigned char getGreen();
		void setGreen(unsigned char value);
		
		unsigned char getBlue();
		void setBlue(unsigned char value);
		
		unsigned char getAlpha();
		void setAlpha(unsigned char value);
		
		unsigned int getIntValue();
		void setIntValue(unsigned int value);
		
		float getRedF();
		void setRedF(float value);
		
		float getGreenF();
		void setGreenF(float value);
		
		float getBlueF();
		void setBlueF(float value);
		
		float getAlphaF();
		void setAlphaF(float value);
	};
	
}

#endif // COLOR_H_