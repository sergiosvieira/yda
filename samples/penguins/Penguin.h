#ifndef __PENGUIN__
#define __PENGUIN__

/** YDA **/
#include "YAnimatedSprite.h"
#include "YGameObject.h"
#include "YVector.h"


class Penguin : public YAnimatedSprite, YGameObject
{
public:
	Penguin(SDL_Texture* a_texture,
			YPoint a_point,
            YVector a_velocity,
            bool a_visible,
			YFrame a_frame,
            int a_frameWidth,
            int a_frameHeight,
            int a_framesPerSecond):
			YAnimatedSprite(a_texture,
                            a_frame,
                            a_frameWidth,
                            a_frameHeight,
                            a_framesPerSecond),
            YGameObject(a_point,
                        a_velocity,
                        a_visible)
    {
        m_gravity = YVector(0.f, 0.8);
        m_onGround = false;
    }

	/** criar gerente de movimentação **/
	void startJump();
	void endJump();
	void onGround(bool a_value);
	void update();
private:
	bool m_onGround;
	YVector m_velocity;
	YVector m_gravity;
};

#endif /** __PENGUIN__ **/