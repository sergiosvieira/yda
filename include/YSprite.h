#ifndef __YSPRITE__
#define __YSPRITE__

/** C++ **/
#include <string>

/** Forwarding class **/
struct SDL_Texture;
struct SDL_Rect;

/** YDA **/
#include "YPoint.h"

class YSprite
{
public:
	YSprite(SDL_Texture* a_texture);
	SDL_Texture* texture();
	int width();
	int height();
	SDL_Rect rect();
protected:
	int m_width;
	int m_height;
	SDL_Texture* m_texture;
};

#endif /** __YSPRITE __ **/