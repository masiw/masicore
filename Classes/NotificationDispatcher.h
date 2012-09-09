/*
 *  NotificationDispatcher.h
 *  masicore
 *
 *  Created by masi on 03/07/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#ifndef NOTIFICATION_DISPATCHER_H_
#define NOTIFICATION_DISPATCHER_H_

#include "Object.h"
#include "NotificationCentre.h"

namespace masi {
	
	class NotificationDispatcher: public Object {
		
	private:
		
		NotificationCentre * _notificationCentre;
		
	public:
		
		NotificationDispatcher();
		~NotificationDispatcher();
		
		NotificationCentre * getNotificationCentre();
		void setNotificationCentre(NotificationCentre * value);
	};
}

#endif // NOTIFICATION_DISPATCHER_H_