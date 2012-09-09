/*
 *  TextDisplay.cpp
 *  masicore
 *
 *  Created by masi woermann on 08/09/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#include "TextDisplay.h"

#include <iostream>

namespace masi
{
	TextDisplay::~TextDisplay()
	{
		
	}
	
	std::string TextDisplay::getText()
	{
		return _text;
	}
	
	void TextDisplay::setText(std::string value)
	{
		_text = value;
	}
	
	void TextDisplay::draw()
	{
		std::cout << _text << std::endl;
	}
}