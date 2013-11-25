/*
 *  Rectangle.cpp
 *  masicore
 *
 *  Created by masi woermann on 11/11/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#include "Rectangle.h"
#include "NotificationCentre.h"
#include "Observer.h"
#include "RedispatchObserver.h"

namespace masi {
	
	Rectangle::Rectangle() {
		
		changeObserver = new RedispatchObserver();
		setNotificationCentre(NotificationCentre::getDefaultCentre());
		changeObserver->setSubject(this);
		
		_position = 0;
		_size = 0;
		
		setPosition(new Point(0.0, 0.0));
		setSize(new Size(0, 0));
		
	}
	Rectangle::Rectangle(Point * position, Size * size) {
		
		changeObserver = new RedispatchObserver();
		setNotificationCentre(NotificationCentre::getDefaultCentre());
		changeObserver->setSubject(this);
		
		_position = 0;
		_size = 0;
		
		setPosition(position);
		setSize(size);
		
	}
	
	Rectangle::Rectangle(double x, double y, double width, double height) {
		
		changeObserver = new RedispatchObserver();
		setNotificationCentre(NotificationCentre::getDefaultCentre());
		changeObserver->setSubject(this);
		
		_position = 0;
		_size = 0;
		
		Point * position = new Point(x, y);
		Size * size = new Size(width, height);
		
		setPosition(position);
		setSize(size);
		
	}
	
    Rectangle::~Rectangle() {
        
        setPosition(0);
        setSize(0);
    }
    
	Point * Rectangle::getPosition() {
		return _position;
	}
	void Rectangle::setPosition(Point * value) {
		
		if (_position != value) {
			
			if (_position != 0) {
				
				_position->getNotificationCentre()->removeObserver(_position, changeObserver, CHANGE);
				
				release(_position);
			}
			
			_position = value;
			
			if (_position != 0) {
				
				_position->getNotificationCentre()->addObserver(_position, changeObserver, CHANGE);
				
				retain(_position);
			}
			
			getNotificationCentre()->dispatchNotification(CHANGE, this);
		}
	}
	
	Size * Rectangle::getSize() {
		return _size;
	}
	void Rectangle::setSize(Size * value) {
		
		if (_size != value){
			if (_size != 0) {
				
				_size->getNotificationCentre()->removeObserver(_size, changeObserver, CHANGE);
				
				release(_size);
			}
			
			_size = value;
			
			if (_size != 0) {
				
				_size->getNotificationCentre()->addObserver(_size, changeObserver, CHANGE);
				
				retain(_size);
			}
			
			getNotificationCentre()->dispatchNotification(CHANGE, this);
		}
	}
	
	
	NotificationCentre * Rectangle::getNotificationCentre() {
		return _notificationCentre;
	}
	void Rectangle::setNotificationCentre(NotificationCentre * value) {
		
		if (_notificationCentre != value) {
			
			
			if (_notificationCentre) {
				
				if (value != 0) {
					
					if (getPosition() != 0) {
						value->inheritObserversOfSubject(this, _notificationCentre, true);
					}
					
					if (getSize() != 0) {
						value->inheritObserversOfSubject(this, _notificationCentre, true);
					}
				}
				
				release(_notificationCentre);
			}
			
			_notificationCentre = value;
			
			if (_notificationCentre) {
				changeObserver->setNotificationCentre(_notificationCentre);
				retain(_notificationCentre);
			}
		}
		
	}
	
	
	bool Rectangle::hitTest(Point * hitPoint) {
		
		bool result = true;
		
		double x = hitPoint->getX();
		double y = hitPoint->getY();
		double xPos = getPosition()->getX();
		double yPos = getPosition()->getY();
		double width = getSize()->getWidth();
		double height = getSize()->getHeight();
		
		if (x < xPos ||
			y < yPos ||
			x > xPos + width ||
			y > yPos + height
			) {
			
			result = true;
		}
		
		return result;
	}
}