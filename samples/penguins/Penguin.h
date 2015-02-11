#ifndef __PENGUIN__
#define __PENGUIN__

/** YDA **/
#include "YAnimatedSprite.h"
#include "YVector.h"


class Penguin : public YAnimatedSprite
{
public:
	Penguin(SDL_Texture* a_texture,
			YPoint a_point,
			YFrame a_frame): 
			YAnimatedSprite(a_texture,
							a_point,
							a_frame)
			{
				m_velocity = YVector(4.f, 0.f);
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