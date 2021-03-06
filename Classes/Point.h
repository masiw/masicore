/*
 *  Point.h
 *  masicore
 *
 *  Created by masi woermann on 11/11/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#ifndef POINT_H_
#define POINT_H_

#include "Object.h"
#include "NotificationCentre.h"

namespace masi {
	class Point : public Object {
		
	private:
		
		double _x;
		double _y;
		double _z;
		
		NotificationCentre * _notificationCentre;
		
	public:
		
		Point();
		Point(double x, double y);
		Point(double x, double y, double z);
		
		double getX();
		void setX(double value);
		
		double getY();
		void setY(double value);
		
		double getZ();
		void setZ(double value);
		
		Point * addPoint(Point * point);
		Point * multiplyBy(double value);
		
		NotificationCentre * getNotificationCentre();
		void setNotificationCentre(NotificationCentre * value);
	};
}


#endif // POINT_H_