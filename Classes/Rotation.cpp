/*
 *  Rotation.cpp
 *  masicore
 *
 *  Created by masi on 28/06/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#include "Rotation.h"

namespace masi {
	
	Rotation::Rotation() {
		
		changeObserver = new RedispatchObserver(this, getNotificationCentre());
		
		setAngle(0.0);
		setAxis(new Point());
	}
	
	Rotation::Rotation(double angle, Point * axis) {
		
		changeObserver = new RedispatchObserver(this, getNotificationCentre());
		
		setAngle(angle);
		setAxis(axis);
	}
	
	Rotation::Rotation(double angle, double x, double y, double z) {
		
		changeObserver = new RedispatchObserver(this, getNotificationCentre());
		
		setAngle(angle);
		setAxis(new Point(x, y, z));
	}
	
	Rotation::~Rotation() {
		setAxis(0);
	}
	
	double Rotation::getAngle() {
		return _angle;
	}
	void Rotation::setAngle(double value) {
		_angle = value;
	}
	
	Point * Rotation::getAxis() {
		return _axis;
	}
	void Rotation::setAxis(Point * value) {
		
		if (_axis != value) {
			
			if (_axis != 0) {
				
				_axis->getNotificationCentre()->removeObserver(_axis, changeObserver, CHANGE);
				
				release(_axis);
			}
			
			_axis = value;
			
			if (_axis != 0) {
				
				_axis->getNotificationCentre()->addObserver(_axis, changeObserver, CHANGE);
				
				release(_axis);
			}
		}
	}
	
	NotificationCentre * Rotation::getNotificationCentre() {
		return _notificationCentre;
	}
	void Rotation::setNotificationCentre(NotificationCentre * value) {
		
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