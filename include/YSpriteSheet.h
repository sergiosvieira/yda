#ifndef __YANIMATED_SPRITE__
#define __YANIMATED_SPRITE__

/** YDA Framework **/
#include "YSprite.h"
#include "YAnimated.h"

/** SDL2 **/
#include "SDL.h"
/*!
  This class is used to animate sprites
*/
class YSpriteSheet : public YSprite
{
public:
	//! Default constructor
	YSpriteSheet(): YSprite(nullptr),
					   		m_frame(YFrame(0, 0, 0)),
					   		m_frameWidth(0),
							m_frameHeight(0),
							m_fps(0),
							m_paused(false){};
	//! Constructor with arguments
	/*!
	  \param Texture
	  \param Settings used to animate the game object
	  \param Frame width
	  \param Frame Height
	  \param Animation FPS (Frame Per Second)
	*/
	YSpriteSheet(SDL_Texture* a_texture,
				 YFrame a_frame,
				 int a_frameWidth,
				 int a_frameHeight,
				 int a_framesPerSecond):
				 YSprite(a_texture),
				 m_frame(a_frame),
				 m_frameWidth(a_frameWidth),
				 m_frameHeight(a_frameHeight),
				 m_fps(a_framesPerSecond)
	{
		m_frame = a_frame;
		m_cols = (float)m_width / (float)m_frameWidth;
		m_rows = (float)m_height / (float)m_frameHeight;
		m_previousTick = SDL_GetTicks();
        m_updateCycle = 1000.f / (float)m_fps;
        m_paused = false;
	};
    //! Rect method overriding
    virtual SDL_Rect rect() override;
	//! Pause the sprite animation
	/*!
	  \param Pause or continue animation
	*/
	void pause(bool a_value);
	//! Setting the current animation frame
	/*!
	  \param Frame index
	*/
	void currentFrame(int a_frame);
	//! Setting the first and the last frame animation index
	/*!
	  \param First frame index
	  \param Last frame index
	*/
	void frameRange(int a_first,
					int a_last);
	/*!
	  \return Frame width
	*/
    virtual int width() override;
    /*!
      \return Fram Height
    */
    virtual int height() override;
protected:
	YFrame m_frame; //! Frame settings
	int m_frameWidth; //! Frame width
	int m_frameHeight; //! Frame height
	int m_fps; //! Animation speed (Frames per Second)
private:
	bool m_paused;
	int m_rows;
	int m_cols;
	Uint32 m_updateCycle;
	Uint32 m_previousTick;
    //! Next rect of the animation frame
    /*!
     \return rect of the next frame
     */
    SDL_Rect nextFrame();    
};

#endif /** __YANIMATED_SPRITE__ **/