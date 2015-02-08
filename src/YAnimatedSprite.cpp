#include "YAnimatedSprite.h"

YAnimatedSprite::YAnimatedSprite(SDL_Texture* a_texture,
								 float a_x,
								 float a_y,
								 YFrame a_frame): 
								 YSprite(a_texture,
										 a_x,
										 a_y)
									
{
	m_frame = a_frame;
	m_cols = (float)m_width / (float)m_frame.width;
	m_rows = (float)m_height / (float)m_frame.height;
	m_previousTick = SDL_GetTicks();
	m_updateCycle = 1000 / a_frame.fps;
}

SDL_Rect YAnimatedSprite::nextFrame()
{
	SDL_Rect result = {};

	result.x = (m_frame.current % m_cols) * m_frame.width;
	result.y = (m_frame.current / m_cols) * m_frame.height;
	result.h = m_frame.height;
	result.w = m_frame.width;

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

SDL_Rect YAnimatedSprite::rect(int a_size)
{
	SDL_Rect result;

	result.x = m_x;
	result.y = m_y;
	result.w = m_frame.width * a_size;
	result.h = m_frame.height * a_size;

	return result;
}

void YAnimatedSprite::pause(bool a_value)
{
	m_paused = a_value;
}

void YAnimatedSprite::currentFrame(int a_frame)
{
	m_frame.current = a_frame;
}

void YAnimatedSprite::firstFrame(int a_frame)
{
	m_frame.first = a_frame;
}

void YAnimatedSprite::lastFrame(int a_frame)
{
	m_frame.last = a_frame;
}
