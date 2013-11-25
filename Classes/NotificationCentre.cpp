/*
 *  NotificationCentre.cpp
 *  masicore
 *
 *  Created by masi on 02/07/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#include "NotificationCentre.h"
#include "Observer.h"

#include <iostream>

namespace masi {
	
	typedef std::map< Object *, std::map< unsigned int, std::vector< Observer * > > >::iterator SubjectIterator;
	typedef std::map< unsigned int, std::vector< Observer * > >::iterator TypeIterator;
	typedef std::vector< Observer * >::iterator ObserverIterator;
    
    typedef std::map<Object *, std::map<unsigned int, std::vector<Observer *> > > ObserverMap;
	
	NotificationCentre * NotificationCentre::defaultCentre = new NotificationCentre();
	
	NotificationCentre::NotificationCentre() {
	}
	NotificationCentre::~NotificationCentre() {
		
		while (observers.size() > 0) {
			
			SubjectIterator subjectIterator = observers.begin();
			
			while (subjectIterator->second.size() > 0) {
				
				TypeIterator typeIterator = subjectIterator->second.begin();
				
				while (typeIterator->second.size()) {
					
					ObserverIterator observerIterator = typeIterator->second.begin();
					typeIterator->second.erase(observerIterator);
					release(*observerIterator);
				}
				
				subjectIterator->second.erase(typeIterator);
			}
			
			release( subjectIterator->first );
			observers.erase( subjectIterator );
		}
	}
	
	void NotificationCentre::addObserver(Object * subject, Observer * observer, unsigned int type) {
		
		if ( !hasObserver(subject, observer, type) ) {
			
			retain(subject);
			retain(observer);
			
			if (observers.find(subject) == observers.end()) {
				
				observers[subject] = *(new std::map< unsigned int, std::vector< Observer * > >() );
			}
			
			if (observers[subject].find(type) == observers[subject].end()) {
				
				observers[subject][type] = *(new std::vector< Observer * >() );
			}
			
			observers[subject][type].push_back( observer );
		}
		
	}
	
	void NotificationCentre::removeObserver(Object * subject, Observer * observer, unsigned int type) {
		
		SubjectIterator subjectIterator = observers.find(subject);
		
		if (subjectIterator != observers.end()) {
			
			TypeIterator typeIterator = subjectIterator->second.find(type);
			
			if (typeIterator != subjectIterator->second.end()) {
				
				for (ObserverIterator observerIterator = typeIterator->second.begin();
					 observerIterator != typeIterator->second.end();
					 observerIterator++) {
					
					if (*observerIterator == observer) {
						
						typeIterator->second.erase(observerIterator);
						release(*observerIterator);
						break;
					}
				}
				
				if (typeIterator->second.empty()) {
					
					delete &(typeIterator->second);
					subjectIterator->second.erase( typeIterator );
					
					delete &(*typeIterator);
				}
			}
			
			if (subjectIterator->second.empty()) {
				
				observers.erase(subjectIterator);
				release(subjectIterator->first);
			}
		}
	}
	bool NotificationCentre::hasObserver(Object * subject, Observer * observer, unsigned int type) {
		
		SubjectIterator subjectIterator = observers.find(subject);
		
		if ( subjectIterator != observers.end() ) {
			
			TypeIterator typeIterator = subjectIterator->second.find(type);
			
			if ( typeIterator != subjectIterator->second.end() ) {
				
				for (int i = 0; i < typeIterator->second.size(); i++) {
					
					if (observer == typeIterator->second[i]) {
						return true;
					}
				}
			}
		}
		
		return false;
	}
    
    
	void NotificationCentre::dispatchNotification(unsigned int type, Object * subject) {
		
        Notification * notification = new Notification(type, subject);
        retain(notification);
        
		SubjectIterator subjectIterator = observers.find(notification->getSubject());
		
		if (subjectIterator != observers.end()) {
			
			TypeIterator typeIterator = subjectIterator->second.find(notification->getType());
			
			if (typeIterator != subjectIterator->second.end()) {
				
				for (int i = 0; i < typeIterator->second.size(); i++) {
					
					typeIterator->second[i]->notify(notification);
				}
			}
		}
        
        release(notification);
	}
	
	
	void NotificationCentre::inheritObserversOfSubject(Object * subject, NotificationCentre * notificationCentre, bool removeObservers) {
		
		
		SubjectIterator subjectIterator = notificationCentre->observers.find(subject);
		
		if (subjectIterator != notificationCentre->observers.end()) {
			
			TypeIterator typeIterator;
			
			for (typeIterator = subjectIterator->second.begin();
				 typeIterator != subjectIterator->second.end();
				 typeIterator++) {
				
				for (int i = 0; i < typeIterator->second.size(); i++) {
					
					addObserver(subject, typeIterator->second[i], typeIterator->first);
					
					if (removeObservers) {
						notificationCentre->removeObserver(subject, typeIterator->second[i], typeIterator->first);
					}
				}
			}
		}
		
	}
	
	NotificationCentre * NotificationCentre::getDefaultCentre() {
		
		return defaultCentre;
	}
	
	/*
	std::vector<Notification *> NotificationCentre::getNotifications() {
		return notifications;
	}
	 */
}