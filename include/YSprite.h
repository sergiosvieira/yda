#ifndef __YSPRITE__
#define __YSPRITE__

/** C++ **/
#include <string>

/** SDL2 **/
#include <SDL.h>
#include <SDL_image.h>

/** YDA **/
#include "YPoint.h"

class YSprite
{
public:
	YSprite(SDL_Texture* a_texture,
			YPoint a_position);
	SDL_Texture* texture();
	YPoint position();
	void position(YPoint a_position);
	void visible(bool a_value);
	bool isVisible();
	int width();
	int height();
	SDL_Rect rect();
protected:
	YPoint m_position;
	int m_width;
	int m_height;
	SDL_Texture* m_texture;
	bool m_visible;
};

#endif /** __YSPRITE __ **/