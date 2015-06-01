/** \addtogroup YDA
 *  @{
 */

/****************************************************************************
 Copyright (c) 2015 Sérgio Vieira - sergiosvieira@gmail.com
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __YSPRITE_SHEET__
#define __YSPRITE_SHEET__

/** YDA Framework **/
#include "YSprite.h"
#include "YSpriteHeader.h"

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
                            m_frame(YFrame(0, 0, 0, YSize<int>(0,0))),
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
				 int a_framesPerSecond):
				 YSprite(a_texture),
                 m_frame(a_frame),
                 m_fps(a_framesPerSecond),
                 m_paused(false)
	{
        m_cols = (float)a_frame.size.width / (float)a_frame.size.height;
        m_rows = (float)m_height / (float)a_frame.size.height;
		m_previousTick = SDL_GetTicks();
        m_updateCycle = 1000.f / (float)m_fps;
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

#endif /** __YSPRITE_SHEET__ **/

/** @}*/
