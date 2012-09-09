/*
 *  Notification.cpp
 *  masicore
 *
 *  Created by masi on 03/07/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#include "Notification.h"
#include "NotificationCentre.h"
#include "Observer.h"

namespace masi {
	
	
	Notification::Notification() {
		_type = 0;
		_subject = 0;
	}
	Notification::Notification(unsigned int type, Object * subject) {
		
		_type = 0;
		_subject = 0;
		
		setType(type);
		setSubject(subject);
	}
	Notification::~Notification(){
		setType(0);
		setSubject(0);
	}
	
	unsigned int Notification::getType() {
		return _type;
	}
	void Notification::setType(unsigned int value) {
		_type = value;
	}
	
	Object * Notification::getSubject() {
		return _subject;
	}
	void Notification::setSubject(Object * value) {
		if (_subject != value) {
			
			if (_subject) {
				release(_subject);
			}
			
			_subject = value;
			
			if (_subject) {
				retain(_subject);
			}
		}
	}
	
}