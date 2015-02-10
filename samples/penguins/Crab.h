#ifndef __CRAB__
#define __CRAB__

/** Penguin **/
#include "YAnimatedSprite.h"

class Crab : public YAnimatedSprite
{
public:
	typedef enum
	{
		JUMP_TO_ISLAND,
		JUMP_FROM_ISLAND
	} State;
	Crab(SDL_Texture* a_texture,
		 float a_x,
		 float a_y,
		 YFrame a_frame,
		 int a_seaY): 
		 YAnimatedSprite(
		 	a_texture,
		 	a_x,
		 	a_y,
		 	a_frame)
		{
			m_state = JUMP_TO_ISLAND;
			m_velocityX = 2.0f;
			m_velocityY = 0.f;
			m_jumping = false;
			m_onSea = true;
			m_seaY = a_seaY;
			m_oldHeight = m_frame.height;
		};
	void start(SDL_Rect a_islandRect);
	void jump();
	void update();
private:
	bool m_onSea;
	bool m_jumping;
	float m_velocityX;
	float m_velocityY;
	int m_seaY;
	State m_state;
	SDL_Rect m_islandRect;
	float m_oldHeight;
};

#endif /** __CRAB__ **/