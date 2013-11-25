/*
 *  Object.h
 *  masicore
 *
 *  Created by masi woermann on 07/09/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#ifndef OBJECT_H_
#define OBJECT_H_

namespace masi
{	
	class Object {
		
	private:
		
		unsigned int _retainCount = 0;
		
		void increaseRetainCount();
		void decreaseRetainCount();
		
	protected:
		
		Object * retain(Object * obj);
		void release(Object * obj);
		
	public:
		
		Object();
		
		
		unsigned int getRetainCount();
	};
}

#endif // OBJECT_H_