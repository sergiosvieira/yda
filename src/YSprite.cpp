#include "YSprite.h"

/** C++ **/
#include <cassert>

YSprite::YSprite(SDL_Texture* a_texture,
				 float a_x,
				 float a_y)
{
	m_texture = a_texture;
	m_x = a_x;
	m_y = a_y;
	
	/** getting texture width and height **/
	SDL_QueryTexture(a_texture, 
					 NULL, 
					 NULL, 
					 &m_width, 
					 &m_height);
}

YSprite::YSprite(SDL_Texture* a_texture,
				 float a_x,
				 float a_y,
				 int a_width,
				 int a_height)
{
	m_texture = a_texture;
	m_x = a_x;
	m_y = a_y;
}

SDL_Texture* YSprite::texture()
{
	return m_texture;
}

float YSprite::x()
{
	return m_x;
}

float YSprite::y()
{
	return m_y;
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
	SDL_Rect result;

	result.x = m_x;
	result.y = m_y;
	result.w = m_width;
	result.h = m_height;

	return result;
}
