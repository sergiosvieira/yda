#ifndef __FISH__
#define __FISH__

/** YDS **/
#include "YAnimatedSprite.h"

class Fish : public YAnimatedSprite
{
public:
	Fish(SDL_Texture* a_texture,
		 float a_x,
		 float a_y,
		 YFrame a_frame): 
		 YAnimatedSprite(
		 	a_texture,
		 	a_x,
		 	a_y,
		 	a_frame){};
    void update();
};

#endif /** __FISH __ **/