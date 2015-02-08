#ifndef __YANIMATED_SPRITE__
#define __YANIMATED_SPRITE__

/** YDA Framework **/
#include "YSprite.h"
#include "YAnimated.h"

/** SDL2 **/
#include "SDL.h"

class YAnimatedSprite : public YSprite
{
public:
	YAnimatedSprite(SDL_Texture* a_texture,
					float a_x,
					float a_y,
					YFrame a_frame);
	SDL_Rect nextFrame();
	SDL_Rect rect(int a_size = 1);
	void pause(bool a_value);
	void currentFrame(int a_frame);
	void firstFrame(int a_frame);
	void lastFrame(int a_frame);
protected:
	YFrame m_frame;
private:
	bool m_paused;
	int m_rows;
	int m_cols;
	Uint32 m_updateCycle;
	Uint32 m_previousTick;
};

#endif /** __YANIMATED_SPRITE__ **/