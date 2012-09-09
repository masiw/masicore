/*
 *  Rectangle.h
 *  masicore
 *
 *  Created by masi woermann on 11/11/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Object.h"

#include "Point.h"
#include "Size.h"

#include "NotificationCentre.h"
#include "RedispatchObserver.h"

namespace masi {
	
	class Rectangle : public Object {
		
	private:
		Point * _position;
		Size * _size;
		
		RedispatchObserver * changeObserver;
		NotificationCentre * _notificationCentre;
		
	public:
		Rectangle();
		Rectangle(Point * position, Size * size);
		Rectangle(double x, double y, double width, double height);
		
		Point * getPosition();
		void setPosition(Point * value);
		
		Size * getSize();
		void setSize(Size * value);
		
		NotificationCentre * getNotificationCentre();
		void setNotificationCentre(NotificationCentre * value);
		
		bool hitTest(Point * hitPoint);
	};
}

#endif // RECTANGLE_H_