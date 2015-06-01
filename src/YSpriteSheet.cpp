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

#include "YSpriteSheet.h"

/** Public Methods **/
SDL_Rect YSpriteSheet::rect()
{
    return nextFrame();
}

void YSpriteSheet::pause(bool a_value)
{
	m_paused = a_value;
}

void YSpriteSheet::currentFrame(int a_frame)
{
	m_frame.current = a_frame;
}

void YSpriteSheet::frameRange(int a_first, int a_last)
{
    m_frame.first = a_first;
    m_frame.last = a_last;
}

int YSpriteSheet::width()
{
    return m_frame.size.width;
}

int YSpriteSheet::height()
{
    return m_frame.size.height;
}

/** Private Methods **/
SDL_Rect YSpriteSheet::nextFrame()
{
    SDL_Rect result = {};
    
    result.x = (m_frame.current % m_cols) * m_frame.size.width;
    result.y = (m_frame.current / m_cols) * m_frame.size.height;
    result.h = m_frame.size.height;
    result.w = m_frame.size.width;
    
    if (!m_paused)
    {
        if (SDL_GetTicks() - m_previousTick > m_updateCycle)
        {
            m_previousTick = SDL_GetTicks();
            
            if (m_frame.current + 1 <= m_frame.last)
            {
                ++m_frame.current;
            }
            else
            {
                m_frame.current = m_frame.first;
            }
        }
    }
    
    return result;
}
