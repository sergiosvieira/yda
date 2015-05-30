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

#ifndef __YOBJECT__
#define __YOBJECT__

/** C++ **/
#include <cstdio>

/** YDA **/
#include "YPoint.h"

/** Forwarding Class **/
struct SDL_Renderer;
union SDL_Event;
class YSprite;

/*!
  This class is used to store some characteristics (position, velocity etc) 
  of game objects (Main person, enemies, scenario objects etc)
*/
class YObject
{
public:
	//! Constructor with arguments
	/*!
	  \param Game object position
	  \param Game object vectorial velocity
	  \param Game object visibility
	 */
	YObject(YObject* a_parent,
			YSprite* a_sprite,
            YPoint a_position,
			YPoint a_anchor,
			bool a_visibility):
            m_parent(a_parent),
            m_sprite(a_sprite),
            m_position(a_position),
			m_anchor(a_anchor),
			m_visible(a_visibility){};
	//! Default constructor
	YObject(): m_parent(nullptr),
			   m_sprite(nullptr),
               m_position(YPoint(0.f, 0.f)),
			   m_anchor(YPoint(0.f, 0.f)),
			   m_visible(true){};
    //! Default desctructor
    virtual ~YObject(){};
	//! Process SDL Events (Keyboard etc)
	/*!
	  \param SDL Event
	*/
    virtual void processEvents(SDL_Event* a_event){};
	//! Update game object
	/*!
	  \param Time diference between current frame update and the last frame update
	  */
	virtual void update(float a_deltaT) = 0;
    //! Render game object
    /*!
      \param SDL_Renderer*
    */
    virtual void render(SDL_Renderer* a_renderer) const final;
	/*!
	  \return Current game object position
	 */
	YPoint position() const;
	/*!
	  Setting the game object position
	*/
	void position(YPoint a_position);
	/*!
	  \return Anchor position
	*/
	YPoint anchor() const;
	/*!
	  Setting the game object velocity
	*/ 
	void anchor(YPoint a_anchor);
	/*!
	  Setting the visibility of game object
	*/
	void visible(bool a_value);
	/*!
	  Current visibility of game object
	*/
	bool isVisible() const;
    //! Getting object sprite
    /*!
      \return YSprite*
    */
    YSprite* sprite() const;
protected:
    //! Game object parent
    YObject* m_parent;
    //! Sprite
    YSprite* m_sprite;
    //! Position on the screen
	YPoint m_position;
	//! Anchor position
	YPoint m_anchor;
	//! Visibility
	bool m_visible;
};

#endif /** __YOBJECT__ **/

/** @}*/