/*
 *  Observer.h
 *  masicore
 *
 *  Created by masi on 03/07/2011.
 *  Copyright 2011 memorphic. All rights reserved.
 *
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "Object.h"
#include "Notification.h"

namespace masi {
	
	class Observer : public Object
	{
		
	public:
		virtual void notify(Notification * notification) = 0;
	};
}

#endif // OBSERVER_H_