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
    return m_frameWidth;
}

int YSpriteSheet::height()
{
    return m_frameHeight;
}

/** Private Methods **/
SDL_Rect YSpriteSheet::nextFrame()
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