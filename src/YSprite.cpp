#include "YSprite.h"

/** C++ **/
#include <cassert>


YSprite::YSprite(SDL_Texture* a_texture,
				 YPoint a_point)
{
	m_texture = a_texture;
	m_position = a_point;

	/** getting texture width and height **/
	SDL_QueryTexture(a_texture, 
					 NULL, 
					 NULL, 
					 &m_width, 
					 &m_height);
	m_visible = true;
}

SDL_Texture* YSprite::texture()
{
	return m_texture;
}

YPoint YSprite::position()
{
	return m_position;
}

void YSprite::position(YPoint a_point)
{
	m_position = a_point;
}

void YSprite::visible(bool a_value)
{
	m_visible = a_value;
}

bool YSprite::isVisible()
{
	return m_visible;
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
	SDL_Rect result = {};

	if (m_visible == true)
	{
		result.x = m_position.x();
		result.y = m_position.y();
		result.w = m_width;
		result.h = m_height;
	}

	return result;
}
