#ifndef __CLOUD__
#define __CLOUD__

/** YDA **/
#include "YSprite.h"
#include "YGameObject.h"
#include "YVector.h"

class Cloud: public
             YSprite,
             YGameObject
{
public:
	Cloud(SDL_Texture* a_texture,
		  YPoint a_point,
          YVector a_velocity,
          bool a_visible,
		  SDL_Rect a_screenSize):
		  YSprite(a_texture),
          YGameObject(a_point,
                      a_velocity,
                      a_visible)
    {
        m_screenSize = a_screenSize;
    };
	void update(float a_deltaT);
protected:
	SDL_Rect m_screenSize;
};

#endif /** __CLOUD__ **/