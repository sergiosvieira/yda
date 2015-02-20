/** \addtogroup Samples
 *  @{
 */

#ifndef __FISH__
#define __FISH__

/** YDS **/
#include "YAnimatedSprite.h"
#include "YVector.h"

class Fish : public YAnimatedSprite
{
public:
	Fish(SDL_Texture* a_texture,
		 YPoint a_point,
		 YFrame a_frame): 
		 YAnimatedSprite(
		 	a_texture,
		 	a_point,
		 	a_frame)
		 {
		 	m_velocity = YVector(5.f, 0.f);
		 	m_jumping = false;
		 };
	void jump();
    void update();
protected:
	YVector m_velocity;
	bool m_jumping;
};

#endif /** __FISH __ **/

/** @}*/