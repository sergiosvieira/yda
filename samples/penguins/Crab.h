#ifndef __CRAB__
#define __CRAB__

/** YDA **/
#include "YAnimatedSprite.h"
#include "YGameObject.h"
#include "YPoint.h"
#include "YVector.h"


class Crab : public
             YAnimatedSprite,
             YGameObject
{
public:
	typedef enum
	{
		JUMP_TO_ISLAND,
		JUMP_FROM_ISLAND
	} State;
    Crab(SDL_Texture* a_texture,
         YPoint a_point,
         YVector a_velocity,
         bool a_visible,
         YFrame a_frame,
         int a_frameWidth,
         int a_frameHeight,
         int a_framesPerSecond,
         int a_seaBorderY,
         SDL_Texture* a_scumaTexture):
         YAnimatedSprite(a_texture,
                         a_frame,
                         a_frameWidth,
                         a_frameHeight,
                         a_framesPerSecond),
         YGameObject(a_point,
                     a_velocity,
                     a_visible),
         m_seaY(a_seaBorderY)
    {
        m_state = JUMP_TO_ISLAND;
        m_jumping = false;
        m_onSea = true;
        m_oldHeight = m_frameHeight;
        
        m_scuma = new YAnimatedSprite(a_scumaTexture,
                                      YFrame(0, 0, 2),
                                      10,
                                      10,
                                      15);
    }
	void start(SDL_Rect a_islandRect);
	void jump();
	void update();
private:
    YVector m_gravity;
	bool m_onSea;
	bool m_jumping;
	YVector m_velocity;
	int m_seaY;
	State m_state;
	SDL_Rect m_islandRect;
	float m_oldHeight;
    YAnimatedSprite* m_scuma;
};

#endif /** __CRAB__ **/