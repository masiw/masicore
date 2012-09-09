/*
 *  Application.h
 *  masicore
 *
 *  Created by masi woermann on 07/09/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "DisplayObject.h"

namespace masi
{
	
	class Application : public Object
	{
	private:
		bool _shouldLoop;
		DisplayObject * _rootView;
		
		static Application * _mainApplication;
		
	protected:
		Application();
		
		
	public:
		
		static Application * getApplication();
		
		Application(DisplayObject * rootView, bool shouldLoop);
		virtual ~Application();
		
		virtual void run();
		void exit();
		
		bool isRunning();
		
		DisplayObject * getRootView();
	};
}

#endif // APPLICATION_H_