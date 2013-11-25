/*
 *  RedispatchObserver.cpp
 *  masicore
 *
 *  Created by masi on 03/07/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#include "RedispatchObserver.h"

namespace masi {
	
	RedispatchObserver::RedispatchObserver() {
		
		_subject = 0;
		_notificationCentre = 0;
	}
	
	RedispatchObserver::RedispatchObserver(Object * subject, NotificationCentre * notificationCentre) {
		
		_subject = 0;
		_notificationCentre = 0;
		
		setSubject(subject);
		setNotificationCentre(notificationCentre);
	}
	RedispatchObserver::~RedispatchObserver() {
		
		setNotificationCentre(0);
		setSubject(0);
	}
	
	void RedispatchObserver::notify(Notification * notification) {
		getNotificationCentre()->dispatchNotification(notification->getType(), getSubject());
	}
	
	
	NotificationCentre * RedispatchObserver::getNotificationCentre() {
		return _notificationCentre;
	}
	void RedispatchObserver::setNotificationCentre(NotificationCentre * value) {
		
		if (_notificationCentre != value) {
			
			if (_notificationCentre != 0) {
				
				if (getSubject() != 0 && value != 0) {
					value->inheritObserversOfSubject(getSubject(), _notificationCentre, true);
				}
				
				release(_notificationCentre);
			}
			
			_notificationCentre = value;
			
			if (_notificationCentre != 0) {
				retain(_notificationCentre);
			}
		}
	}
	
	Object * RedispatchObserver::getSubject(){
		return _subject;
	}
	void RedispatchObserver::setSubject(Object * value) {
		
		if (_subject !=  value) {
			
			if (_subject != 0) {
				release(_subject);
			}
			
			_subject = value;
			
			if (_subject != 0) {
				retain(_subject);
			}
		}
	}
}