/*
 *  Application.cpp
 *  masicore
 *
 *  Created by masi woermann on 07/09/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#include "Application.h"

namespace masi
{
	Application * Application::_mainApplication = 0;
	
	Application::Application()
	{
		if (_mainApplication == 0) {
			_mainApplication = this;
		}
	}
	
	Application::Application(DisplayObject * rootView, bool shouldLoop)
	{
		if (_mainApplication == 0) {
			_mainApplication = this;
		}
		_shouldLoop != shouldLoop;
		_rootView = (DisplayObject *)retain(rootView);
	}
	
	Application::~Application()
	{
		release(_rootView);
	}
	
	void Application::run()
	{
		do {
			_rootView->display();
		} while (isRunning());
	}
	
	void Application::exit()
	{
		_shouldLoop = false;
	}
	
	
	DisplayObject * Application::getRootView() {
		return _rootView;
	}
	
	bool Application::isRunning() {
		return _shouldLoop;
	}
}