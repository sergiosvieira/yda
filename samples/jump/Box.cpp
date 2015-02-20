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

#include "Box.h"

/** C++ **/
#include <cstddef>

/** SDL2 **/
#include <SDL.h>

/** YDA **/
#include "YSprite.h"


Box::Box(YSprite* a_sprite): YGameObject(nullptr,
                             YPoint(0.f, 0.f),
                             YPoint(0.f, 0.f),
                             true)
{
    m_onGround = false;
    m_velocity = YVector(4.f, 0.f);
    m_gravity = YVector(0.2f, 0.8);
    m_sprite = a_sprite;
}

void Box::processEvents(SDL_Event *a_event)
{
    if( a_event->type == SDL_MOUSEBUTTONDOWN )
    {
        startJump();
    }
    else if (a_event->type == SDL_MOUSEBUTTONUP)
    {
        endJump();
    }
}

void Box::update(float a_deltaT)
{
    m_velocity = m_velocity + m_gravity;
    m_position = m_position.add(m_velocity);
    
    if (m_position.y() + m_sprite->height() > 350.f)
    {
        m_position = YPoint(m_position.x(), 350.f - m_sprite->height());
        m_velocity = YVector(m_velocity.x(), 0.f);
        m_onGround = true;
    }
    
    if (m_position.x() + m_sprite->width() > 640.f ||
        m_position.x() < 0.f)
    {
        m_velocity = YVector(m_velocity.x() * -1.f, m_velocity.y());
        m_gravity = YVector(0.2 * -1.f, m_gravity.y());
    }
}

void Box::startJump()
{
    if (m_onGround == true)
    {
        m_velocity = YVector(m_velocity.x(), -12.f);
        m_onGround = false;
    }
}

void Box::endJump()
{
    if (m_velocity.y() < -6.0)
    {
        m_velocity = YVector(m_velocity.x(), -6.f);
    }
}