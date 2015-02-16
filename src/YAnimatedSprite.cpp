#include "YAnimatedSprite.h"

/** Public Methods **/
SDL_Rect YAnimatedSprite::rect()
{
    return nextFrame();
}

void YAnimatedSprite::pause(bool a_value)
{
	m_paused = a_value;
}

void YAnimatedSprite::currentFrame(int a_frame)
{
	m_frame.current = a_frame;
}

void YAnimatedSprite::frameRange(int a_first, int a_last)
{
    m_frame.first = a_first;
    m_frame.last = a_last;
}

int YAnimatedSprite::frameWidth()
{
    return m_frameWidth;
}

int YAnimatedSprite::frameHeight()
{
    return m_frameHeight;
}

/** Private Methods **/
SDL_Rect YAnimatedSprite::nextFrame()
{
    SDL_Rect result = {};
    
    result.x = (m_frame.current % m_cols) * m_frameWidth;
    result.y = (m_frame.current / m_cols) * m_frameHeight;
    result.h = m_frameHeight;
    result.w = m_frameWidth;
    
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