/*
 *  EventDispatcher.h
 *  masicore
 *
 *  Created by masi on 02/07/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#ifndef NOTIFICATION_CENTRE_H_	
#define NOTIFICATION_CENTRE_H_

#include "Object.h"
#include "Notification.h"

#include <vector>
#include <map>
#include <string>

namespace masi {
	
	typedef enum CoreNotifications {
		
		CHANGE = 1,
		KEY_DOWN,
		KEY_UP,
		MOUSE_DOWN,
		MOUSE_UP,
		MOUSE_MOVE,
		MOUSE_OUT
		
	} CoreNotifications;
	
	
	class NotificationCentre : public Object {
		
	private:
		
		static NotificationCentre * defaultCentre;
		
		std::map<Object *, std::map<unsigned int, std::vector<Observer *> > > observers;
		
	public:
		NotificationCentre();
		~NotificationCentre();
		
		void addObserver(Object * subject, Observer * observer, unsigned int type);
		void removeObserver(Object * subject, Observer * observer, unsigned int type);
		bool hasObserver(Object * subject, Observer * observer, unsigned int type);
		//void dispatchNotification(Notification * notification);
        void dispatchNotification(unsigned int type, Object * subject);
		
		void inheritObserversOfSubject(Object * subject, NotificationCentre * notificationCentre, bool removeObservers);
		
		static NotificationCentre * getDefaultCentre();
	};
}

#endif // NOTIFICATION_CENTRE_H_