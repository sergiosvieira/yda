#ifndef __FISH__
#define __FISH__

/** YDS **/
#include "YAnimatedSprite.h"

class Fish : public YAnimatedSprite
{
public:
	Fish(SDL_Texture* a_texture,
		 YPoint a_point,
		 YFrame a_frame): 
		 YAnimatedSprite(
		 	a_texture,
		 	a_point,
		 	a_frame){};
    void update();
};

#endif /** __FISH __ **/