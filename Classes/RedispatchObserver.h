/*
 *  RedispatchObserver.h
 *  masicore
 *
 *  Created by masi on 03/07/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#ifndef REDISPATCH_OBSERVER_H_
#define REDISPATCH_OBSERVER_H_

#include "Observer.h"
#include "NotificationCentre.h"

namespace masi {
	
	class RedispatchObserver : public Observer {
		
	private:
		NotificationCentre * _notificationCentre;
		Object * _subject;
	public:
		RedispatchObserver();
		RedispatchObserver(Object * subject, NotificationCentre * notificationCentre);
		~RedispatchObserver();
		
		void notify(Notification * notification);
		
		NotificationCentre * getNotificationCentre();
		void setNotificationCentre(NotificationCentre * value);
		
		Object * getSubject();
		void setSubject(Object * value);
	};
	
}

#endif