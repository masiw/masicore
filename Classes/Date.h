/*
 *  Date.h
 *  masicore
 *
 *  Created by masi woermann on 17/09/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#ifndef DATE_H_
#define DATE_H_

#include "Object.h"
#include <string>
#include <ctime>

namespace masi {
	
	class Date : public Object {
	private:
		
		struct tm dateValue; 
		
	public:
		Date();
		
		// Date in ISO8601 format
		Date(std::string pIsoDate);
		
		// Date in Unix Time format
		Date(int pUnixDate);
		
		int unixDate();
		void unixDate(int value);
		
		std::string isoDate();
		void isoDate(std::string value);
	};
}

#endif // DATE_H_