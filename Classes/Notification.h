/*
 *  Notification.h
 *  masicore
 *
 *  Created by masi on 03/07/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#ifndef NOTIFICATION_H_
#define NOTIFICATION_H_

#include "Object.h"

namespace masi {
	
	class Observer;
	
	class Notification : public Object {
		
	private:
		unsigned int _type;
		Object * _subject;
		
	public:
		Notification();
		Notification(unsigned int type, Object * subject);
		~Notification();
		
		unsigned int getType();
		void setType(unsigned int value);
		
		Object * getSubject();
		void setSubject(Object * value);
	};
	
}

#endif // NOTIFICATION_H_