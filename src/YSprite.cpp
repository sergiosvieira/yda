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

#include "YSprite.h"

/** C++ **/
#include <cassert>

/** SDL2 **/
#include <SDL.h>
#include <SDL_image.h>


YSprite::YSprite(SDL_Texture* a_texture):
                 m_scale(YPoint<float>(1.f, 1.f))
{
	m_texture = a_texture;
    
	/** getting texture width and height **/
	SDL_QueryTexture(a_texture, 
					 nullptr,
					 nullptr,
					 &m_width, 
					 &m_height);
}

SDL_Texture* YSprite::texture()
{
	return m_texture;
}

int YSprite::width()
{
	return m_width;
}

int YSprite::height()
{
	return m_height;
}

SDL_Rect YSprite::rect()
{
	SDL_Rect result = {}; // Fill SDL_Rect with zero value

	result.w = m_width;
	result.h = m_height;

	return result;
}

void YSprite::scale(const YPoint<float> &a_scale)
{
    m_scale = a_scale;
}

const YPoint<float> YSprite::scale() const
{
    return m_scale;
}

void YSprite::rotation(float a_angle)
{
    m_angle = a_angle;
}
//! Getting sprite rotation angle
float YSprite::rotation() const
{
    return m_angle;
}
