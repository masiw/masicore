/*
 *  Size.cpp
 *  masicore
 *
 *  Created by masi woermann on 11/11/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#include "Size.h"

namespace masi {
	
	
	Size::Size() {
		
		_notificationCentre = 0;
		setNotificationCentre(NotificationCentre::getDefaultCentre());
		
		setWidth(0.0);
		setHeight(0.0);
	}
	
	Size::Size(double width, double height) {
		
		_notificationCentre = 0;
		setNotificationCentre(NotificationCentre::getDefaultCentre());
		
		setWidth(width);
		setHeight(height);
	}
	
	double Size::getWidth() {
		return _width;
	}
	void Size::setWidth(double value) {
		
		if (_width != value) {
			
			_width = value;
			
			getNotificationCentre()->dispatchNotification(CHANGE, this);
		}
	}
	
	double Size::getHeight() {
		return _height;
	}
	void Size::setHeight(double value) {
		
		if (_height != value) {
			
			_height = value;
			
			getNotificationCentre()->dispatchNotification(CHANGE, this);
		}
	}
	
	NotificationCentre * Size::getNotificationCentre() {
		return _notificationCentre;
	}
	void Size::setNotificationCentre(NotificationCentre * value) {
		
		if (_notificationCentre != value) {
			
			
			if (_notificationCentre) {
				release(_notificationCentre);
			}
			
			_notificationCentre = value;
			
			if (_notificationCentre) {
				retain(_notificationCentre);
			}
			
		}
	}
}