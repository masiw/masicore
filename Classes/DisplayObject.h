/*
 *  Display.h
 *  masicore
 *
 *  Created by masi woermann on 07/09/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#ifndef DISPLAY_OBJECT_H_
#define DISPLAY_OBJECT_H_



#include "Object.h"
#include <vector>


namespace masi {
	
	class DisplayContainer;
	
	class DisplayObject : public Object {
		
	private:
		DisplayObject * _parent = 0;
		
		// A collection of child <code>DisplayObject</code>'s that willbe processed
		// in the order as they are found in the collection.
		std::vector<DisplayObject*> _children;
		
		
	public:
		
		virtual ~DisplayObject();
		
		// Custom drawing. Sub classes need to implement this method.
		virtual void display();
		
		// Return the parent of <code>this</code> DisplayObject
		DisplayObject * getParent();
		virtual void setParent(DisplayObject * parent);
		
		//Removes this DisplayObject from its parent, if it is parented,
		// else it does nothing.
		void removeFromParent();
		
		// Adds <code>child</code> as child at the above all other views
		void addChild(DisplayObject * child);
		// Adds child at <code>index</code>, or does nothing if <code>index</code> is out of bounds.
		void addChildAt(DisplayObject * displayObject, unsigned long index);
		
		// Removes <code>child</code> from <code>children</code> and returns it, or returns NULL if the child is not found.
		DisplayObject * removeChild(DisplayObject * child);
		// Removes and returns the child that is found at <arg name="index"/>,
		// or returns NULL if the index is greater than the number of children.
		DisplayObject * removeChildAt(unsigned long index);
		
		// Returns the child that is found at <arg name="index"/>,
		// or NULL if the index is greater than the number of children.
		DisplayObject * getChildAt(unsigned long index);
		
		// Returns the index if the child in the child list or -1 if
		// it is not int the child list.
		int getChildIndex(DisplayObject * child);
		
		// Reorders the children so that the <arg name="displayObject"/> is put at <arg name="newIndex"/>
		// in the child list, if <code>child</code> is found in the children, else it has no effect.
		void setChildIndex(DisplayObject * child, unsigned long newIndex);
		
		
		// Reorders the children so that the <code>DisplayObject</code> at <code>oldIndex</code> is put at <code>newIndex</code>
		// in the child list, if <code>oldIndex</code> is smaller then <code>numChildren()</code>, else it
		// does nothing.
		void setChildIndexAt(unsigned long oldIndex, unsigned long newIndex);
		
		// Moves the <code>child</code> to the top of the display list if it is found in the child list, otherwise it has no effect.
		void moveChildToFront(DisplayObject * child);
		// Moves the <code>DisplayObject</code> found at <code>childIndex</code> to the top of the display list,
		//if <code>childIndex</code> is smaller than <code>numChildren</code>, otherwise it has no effect.
		void moveChildAtToFront(unsigned long childIndex);
		// Moves the <code>child</code> to the bottom of the display list if it is found in the child list, otherwise it has no effect.
		void moveChildToBack(DisplayObject * child);
		// Moves the <code>DisplayObject</code> found at <code>childIndex</code> to the bottom of the display list,
		//if <code>childIndex</code> is smaller than <code>numChildren</code>, otherwise it has no effect.
		void moveChildAtToBack(unsigned long childIndex);
		
		// Returns the number of child <code>DisplayObject</code> that currently are in this components
		// child collection.
		unsigned long numChildren();
		
		// Returns the index this has in the parents child list or -1 if
		// it is not parented.
		long getZOrder();
	};
}

#endif // DISPLAY_OBJECT_H_