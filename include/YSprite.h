#ifndef __YSPRITE__
#define __YSPRITE__

/** C++ **/
#include <string>

/** SDL2 **/
#include <SDL.h>
//#include <SDL2_image/SDL_image.h>
#include <SDL_image.h>


class YSprite
{
public:
	YSprite(SDL_Texture* a_texture,
			float a_x, 
			float a_y);
	YSprite(SDL_Texture* a_texture,
			float a_x, 
			float a_y,
			int a_width,
			int a_height);
	SDL_Texture* texture();
	float x();
	float y();
	void x(float a_x);
	void y(float a_y);
	int width();
	int height();
	SDL_Rect rect();
protected:
	float m_x;
	float m_y;
	int m_width;
	int m_height;
	SDL_Texture* m_texture;
};

#endif /** __YSPRITE __ **/