/*
 *  Point.cpp
 *  masicore
 *
 *  Created by masi woermann on 11/11/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#include "Point.h"

#include "NotificationCentre.h"


namespace masi {
	
	Point::Point() {
		
		_notificationCentre = NotificationCentre::getDefaultCentre();
		
		setX(0.0);
		setY(0.0);
		setZ(0.0);
	}
	
	Point::Point(double x, double y) {
		
		_notificationCentre = NotificationCentre::getDefaultCentre();
		
		setX(x);
		setY(y);
		setZ(0.0);
	}
	
	Point::Point(double x, double y, double z) {
		
		_notificationCentre = NotificationCentre::getDefaultCentre();
		
		setX(x);
		setY(y);
		setZ(z);
	}
	
	double Point::getX() {
		return _x;
	}
	
	void Point::setX(double value) {
		
		if (_x != value) {
			
			_x = value;
			
			getNotificationCentre()->dispatchNotification(CHANGE, this);
		}
	}
	
	double Point::getY() {
		return _y;
	}
	void Point::setY(double value) {
		
		if (_y != value) {
			
			_y = value;
			
			getNotificationCentre()->dispatchNotification(CHANGE, this);
		}
	}
	
	double Point::getZ() {
		return _z;
	}
	void Point::setZ(double value) {
		
		if (_z != value) {
			
			_z = value;
			
			getNotificationCentre()->dispatchNotification(CHANGE, this);
		}
	}
	
	Point * Point::addPoint(Point * point) {
		return new Point(getX() + point->getX(), getY() + point->getY(), getZ() + point->getZ());
	}
		
	Point * Point::multiplyBy(double value) {
		return new Point(getX() * value, getY() * value, getZ() * value);
	}
	
	NotificationCentre * Point::getNotificationCentre() {
		return _notificationCentre;
	}
	void Point::setNotificationCentre(NotificationCentre * value) {
		
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