/*
 *  Object.cpp
 *  masicore
 *
 *  Created by masi woermann on 07/09/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#include "Object.h"
#include <iostream>


namespace masi
{	
	Object::Object()
	{
		_retainCount = 1;
	}
	
	void Object::increaseRetainCount()
	{
		_retainCount++;
	}
	void Object::decreaseRetainCount()
	{
		_retainCount--;
	}
	
	Object * Object::retain(Object * obj)
	{
		if (obj != NULL)
		{
			obj->increaseRetainCount();
		}
		return obj;
	}
	void Object::release(Object * obj)
	{
		if (obj != NULL)
		{
			obj->decreaseRetainCount();
			if (obj->getRetainCount() <= 0)
			{
				delete obj;
			}
		}
	}
	
	unsigned int Object::getRetainCount()
	{
		return _retainCount;
	}
}