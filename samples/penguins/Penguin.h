#ifndef __PENGUIN__
#define __PENGUIN__

/** YDA **/
#include "YAnimatedSprite.h"

class Penguin : public YAnimatedSprite
{
public:
	Penguin(SDL_Texture* a_texture,
					float a_x,
					float a_y,
					YFrame a_frame): 
					YAnimatedSprite(a_texture,
									a_x,
									a_y,
									a_frame)
					{
						m_velocityX = 4.f;
						m_velocityY = 0.f;
						m_onGround = false;
					}

	/** criar gerente de movimentação **/
	void moveBy(float a_x,
				float a_y);
	void startJump();
	void endJump();
	void onGround(bool a_value);
	void update();
private:
	bool m_onGround;
	float m_velocityX;
	float m_velocityY;
};

#endif /** __PENGUIN__ **/