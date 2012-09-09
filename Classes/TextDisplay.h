/*
 *  TextDisplay.h
 *  masicore
 *
 *  Created by masi woermann on 08/09/2010.
 *  Copyright 2010 memorphic. All rights reserved.
 *
 */

#ifndef TEXT_DISPLAY_H_
#define TEXT_DISPLAY_H_

#include "DisplayObject.h"
#include <string>

namespace masi
{
	class TextDisplay : public DisplayObject {
	private:
		std::string _text;
	public:
		virtual ~TextDisplay();
		
		std::string getText();
		void setText(std::string value);
		
		void draw();
	};
}

#endif // TEXT_DISPLAY_H_