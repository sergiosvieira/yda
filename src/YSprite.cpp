#include "YSprite.h"

/** C++ **/
#include <cassert>

/** SDL2 **/
#include <SDL.h>
#include <SDL_image.h>


YSprite::YSprite(SDL_Texture* a_texture)
{
	m_texture = a_texture;

	/** getting texture width and height **/
	SDL_QueryTexture(a_texture, 
					 NULL, 
					 NULL, 
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
