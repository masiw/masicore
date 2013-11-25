/*
 *  NotificationDispatcher.cpp
 *  masicore
 *
 *  Created by masi on 03/07/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#include "NotificationDispatcher.h"

namespace masi {
	
	NotificationDispatcher::NotificationDispatcher() {
		
		_notificationCentre = 0;
		setNotificationCentre(NotificationCentre::getDefaultCentre());
	}
	
	NotificationDispatcher::~NotificationDispatcher() {
		
		setNotificationCentre(0);
	}
	
	NotificationCentre * NotificationDispatcher::getNotificationCentre() {
		return _notificationCentre;
	}
	void NotificationDispatcher::setNotificationCentre(NotificationCentre * value) {
		
		if (_notificationCentre != value) {
			
			if (_notificationCentre) {
				
				value->inheritObserversOfSubject(this, _notificationCentre, true);
				release(_notificationCentre);
			}
			
			_notificationCentre = value;
			
			if (_notificationCentre) {
				
				retain(_notificationCentre);
			}
		}
	}
}