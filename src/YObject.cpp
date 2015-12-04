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

#include "YObject.h"

/** YDA **/
#include "YSprite.h"
#include "YTransformations.h"
#include "YMain.h"

/** C++ **/
#include <cassert>

/** SDL2 **/
#include <SDL.h>
#ifdef WIN32
	#include <SDL_image.h>	
#endif
#ifdef UNIX
  #include <SDL_image.h>  
#endif
#ifdef APPLE
  #include <SDL2_image/SDL_image.h> 
#endif
	

/** Public Methods **/
void YObject::render(SDL_Renderer* a_renderer) const
{
    assert(a_renderer != nullptr);
    assert(m_sprite != nullptr);
    
    SDL_Rect srcRect = m_sprite->rect();
    SDL_Rect dstRect;    
    YPoint<int> topLeft;
    YRect<int> window = YMain::window();
    YRect<int> viewport = YMain::viewport();
    YTransformations::transformPointBetweenRects(topLeft,
                                                 m_position,
                                                 window,
                                                 viewport);
    dstRect.x = topLeft.x();
    dstRect.y = topLeft.y();
    YPoint<int> dstBottomRight = {};
    YPoint<int> srcBottomRight =
    {
        m_position.x() + m_sprite->width(),
        m_position.y() + m_sprite->height()
    };
    YTransformations::transformPointBetweenRects(dstBottomRight,
                                                 srcBottomRight,
                                                 window,
                                                 viewport);
    int width = dstBottomRight.x() - topLeft.x();
    int height = topLeft.y() - dstBottomRight.y();
    dstRect.w = width * m_sprite->scale().x();
    dstRect.h = height * m_sprite->scale().y();
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_RenderCopyEx(a_renderer,
                     m_sprite->texture(),
                     &srcRect,
                     &dstRect,
                     m_sprite->rotation(),
                     nullptr,
                     flip);
}

YPoint<int> YObject::position() const
{
	return m_position;
}

void YObject::position(YPoint<int> a_position)
{
	m_position = a_position;
}

YPoint<int> YObject::anchor() const
{
	return m_anchor;
}

void YObject::anchor(YPoint<int> a_anchor)
{
	m_anchor = a_anchor;
}

void YObject::visible(bool a_value)
{
	m_visible = a_value;
}

bool YObject::isVisible() const
{
	return m_visible;
}

YSprite* YObject::sprite() const
{
    return m_sprite;
}
