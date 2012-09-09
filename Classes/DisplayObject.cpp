/*
 *  Display.cpp
 *  masicore
 *
 *  Created by masi woermann on 07/09/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#include "DisplayObject.h"

namespace masi {
	
	DisplayObject::~DisplayObject()
	{
		if (_parent != 0) {
			release(_parent);
		}
	}
	
	// Return the parent of <code>this</code> DisplayObject
	DisplayObject * DisplayObject::getParent()
	{
		return _parent;
	}
	void DisplayObject::setParent(DisplayObject * parent)
	{	
		if (_parent != 0) {
			release(_parent);
		}
		_parent = parent;
		if (_parent != 0) {
			retain(_parent);
		}
	}
	
	//Removes this DisplayObject from its parent, if it is parented,
	// else it does nothing.
	void DisplayObject::removeFromParent()
	{
		if (getParent() != 0) {
			DisplayObject * parent = getParent();
			parent->removeChild(this);
		}
	}
	
	
	// ------------------------------------------------------------------------------------
	// Drawing
	// ------------------------------------------------------------------------------------
	
	// Custom drawing. Sub classes need to implement this method.
	void DisplayObject::display()
	{
		for (unsigned int i = 0; i < numChildren(); i++)
		{
			DisplayObject * currentChild = _children[i];
			currentChild->display();
		}
		
	}
	
	
	// ------------------------------------------------------------------------------------
	// Add children
	// ------------------------------------------------------------------------------------
	
	// Adds DisplayObject as child at the above all other views
	void DisplayObject::addChild(DisplayObject * displayObject)
	{
		addChildAt(displayObject, numChildren());
	}
	
	// Adds child at <code>index<code/>, or does nothing if <code>index<code/> greater than <code>numChildren</code>.
	void DisplayObject::addChildAt(DisplayObject * displayObject, unsigned int index)
	{
		if (index <= numChildren()) {
			std::vector<DisplayObject*>::iterator it;
			
			// Get iterator for index.
			it = _children.begin();
			it += index;
			
			// Insert child
			_children.insert(it, displayObject);
			displayObject->setParent(this);
			
			// hold on to it so it doesn't get freed.
			retain(displayObject);
		}
	}
	
	
	// ------------------------------------------------------------------------------------
	// Remove children
	// ------------------------------------------------------------------------------------
	
	// Removes <code>displayObject<code/> from <code>children<code/> and returns it, or returns NULL if the child is not found.
	DisplayObject * DisplayObject::removeChild(DisplayObject * child)
	{
		DisplayObject * removedChild = NULL;
		for (unsigned int i = 0; i < numChildren(); i++)
		{
			if (_children[i] == child)
			{
				removedChild = removeChildAt(i);
				break;
			}
		}
		
		return removedChild;
	}
	// Removes and returns the child that is found at <arg name="index"/>,
	// or returns NULL if the index is greater than the number of children.
	DisplayObject * DisplayObject::removeChildAt(unsigned int index)
	{
		DisplayObject * removedChild = NULL;
		
		if (index < numChildren())
		{
			std::vector<DisplayObject*>::iterator it;
			
			it = _children.begin();
			it += index;
			
			removedChild = _children[index];
			removedChild->setParent( NULL );
			
			_children.erase(it);
			
			DisplayObject::release(removedChild);
		}
		
		return removedChild;
	}
	
	
	// ------------------------------------------------------------------------------------
	// Child access
	// ------------------------------------------------------------------------------------
	
	// Returns the child that is found at <arg name="index"/>,
	// or NULL if the index is greater than the number of children.
	DisplayObject * DisplayObject::getChildAt(unsigned int index)
	{
		DisplayObject * child = NULL;
		
		if (index < numChildren())
		{
			child = _children[index];
		}
		
		return child;
	}
	
	
	// ------------------------------------------------------------------------------------
	// Child order
	// ------------------------------------------------------------------------------------
	
	int DisplayObject::getChildIndex(DisplayObject * displayObject)
	{
		int index = -1;
		
		for (int i = 0; i < numChildren(); i++) {
			if (_children[i] == displayObject) {
				index = i;
				break;
			}
		}
		
		return index;
	}
	
	// Reorders the children so that the <arg name="displayObject"/> is put at <arg name="newIndex"/>
	// in the child list, if <code>displayObject</code> is found in the children, else it has no effect.
	void DisplayObject::setChildIndex(DisplayObject * displayObject, unsigned int newIndex)
	{
		for (int i = 0; i < numChildren(); i++) {
			if (_children[i] == displayObject) {
				setChildIndexAt(i, newIndex);
				break;
			}
		}
	}
	
	
	// Reorders the children so that the <code>DisplayObject</code> at <code>oldIndex</code> is put at <code>newIndex<code/>
	// in the child list, if <code>oldIndex</code> is smaller then <code>numChildren()</code>, else it
	// does nothing.
	void DisplayObject::setChildIndexAt(unsigned int oldIndex, unsigned int newIndex)
	{
		if (oldIndex < numChildren() && newIndex < numChildren()) {
			
			DisplayObject * obj;
			std::vector<DisplayObject*>::iterator it;
			
			// capture object
			obj = _children[oldIndex];
			
			// delete object from list
			it = _children.begin();
			it += oldIndex;
			_children.erase(it);
			
			// add object at newIndex
			it = _children.begin();
			it += newIndex;
			_children.insert(it, obj);
		}
	}
	
	
	// Moves the <code>child</code> to the top of the display list if it is found in the child list, otherwise it has no effect.
	void DisplayObject::moveChildToFront(DisplayObject * child)
	{
		setChildIndex(child, numChildren() - 1);
	}
	// Moves the <code>DisplayObject</code> found at <code>childIndex</code> to the top of the display list,
	//if <code>childIndex</code> is smaller than <code>numChildren</code>, otherwise it has no effect.
	void DisplayObject::moveChildAtToFront(unsigned int childIndex)
	{
		setChildIndexAt(childIndex, numChildren() - 1);
	}
	// Moves the <code>child</code> to the bottom of the display list if it is found in the child list, otherwise it has no effect.
	void DisplayObject::moveChildToBack(DisplayObject * child)
	{
		setChildIndex(child, 0);
	}
	// Moves the <code>DisplayObject</code> found at <code>childIndex</code> to the bottom of the display list,
	//if <code>childIndex</code> is smaller than <code>numChildren</code>, otherwise it has no effect.
	void DisplayObject::moveChildAtToBack(unsigned int childIndex)
	{
		setChildIndexAt(childIndex, 0);
	}
	
	
	// ------------------------------------------------------------------------------------
	// Child count
	// ------------------------------------------------------------------------------------
	
	// Returns the number of child <code>DisplayObject</code> that currently are in this components
	// child collection.
	unsigned int DisplayObject::numChildren()
	{
		return _children.size();
	}
	
	
	int DisplayObject::getZOrder()
	{
		int zOrder = -1;
		
		if (getParent() != 0) {
			
			zOrder = getParent()->getChildIndex(this);
		}
		
		return -zOrder;
	}
}