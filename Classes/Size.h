/*
 *  Size.h
 *  masicore
 *
 *  Created by masi woermann on 11/11/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#ifndef SIZE_H_
#define SIZE_H_

#include "Object.h"
#include "NotificationCentre.h"

namespace masi {
	
	class Size : public Object {
		
	private:
		
		double _width;
		double _height;
		
		NotificationCentre * _notificationCentre;
		
	public:
		Size();
		Size(double width, double height);
		
		double getWidth();
		void setWidth(double value);
		
		double getHeight();
		void setHeight(double value);
		
		NotificationCentre * getNotificationCentre();
		void setNotificationCentre(NotificationCentre * value);
	};
}

#endif // SIZE_H_