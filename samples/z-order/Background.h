/****************************************************************************
 Copyright (c) 2015 Sérgio Vieira - sergiosvieira@gmail.com
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
 
#ifndef __BACKGROUND__
#define __BACKGROUND__

#include "YObject.h"

class Background: public YObject
{
public:
	Background(YSprite* a_sprite): YObject(nullptr,
										   a_sprite,
										   YPoint(0.f, 0.f),
										   YPoint(0.f, 0.f),
										   true)
	{
		m_position = YPoint(-(m_sprite->width() - 320.f), 0.f);
		m_velocity = YVector(4.f, 0.f);
	};
	virtual void update(float a_deltaT)
	{
		m_position = m_position.add(m_velocity);

		if (m_position.x() == 0)
		{
			m_position = YPoint(-(m_sprite->width() - 320.f), 0.f);
		}
	} 	
protected:
	YVector m_velocity;
};


#endif /** __BACKGROUND__ **/