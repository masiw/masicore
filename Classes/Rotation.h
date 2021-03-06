/*
 *  Rotation.h
 *  masicore
 *
 *  Created by masi on 28/06/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#ifndef ROTATION_H_
#define ROTATION_H_

#include "Object.h"
#include "Point.h"

#include "NotificationCentre.h"
#include "RedispatchObserver.h"

namespace masi {
	
	class Rotation : public Object{
		
	private:
		double _angle;
		Point * _axis;
		
		RedispatchObserver * changeObserver;
		NotificationCentre * _notificationCentre;
		
	public:
		Rotation();
		Rotation(double angle, Point * axis);
		Rotation(double angle, double x, double y, double z);
		
		~Rotation();
		
		double getAngle();
		void setAngle(double value);
		
		Point * getAxis();
		void setAxis(Point * value);
		
		NotificationCentre * getNotificationCentre();
		void setNotificationCentre(NotificationCentre * value);
	};
}

#endif // ROTATION_H_