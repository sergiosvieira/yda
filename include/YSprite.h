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

#ifndef __YSPRITE__
#define __YSPRITE__

/** C++ **/
#include <string>

/** Forwarding class **/
struct SDL_Texture;
struct SDL_Rect;

/** YDA **/
#include "YPoint.h"

class YSprite
{
public:
    //! Default constructor
    /*!
      \param SDL_Texture*
    */
	YSprite(SDL_Texture* a_texture);
    /*!
      \return SDL_Texture*
    */
	SDL_Texture* texture();
    /*!
      \return int - Sprite width
    */
	virtual int width();
    /*!
      \return int - Sprite height
    */
	virtual int height();
    /*!
      \return SDL_Rect - Rect(0, 0, width, height)
    */
	virtual SDL_Rect rect();
    //! Setting scale width and height
    void scale(const YPoint& a_scale);
    //! Getting scale width and height
    const YPoint scale() const;
    //! Setting sprite rotation angle in degrees
    void rotation(float m_angle);
    //! Getting sprite rotation angle
    float rotation() const;
protected:
	int m_width;//! Sprite width
	int m_height;//! Sprite height
    YPoint m_scale;//! Sprite width scale (default 1.0f)
    float m_angle;//! Sprite rotation angle in degrees
    SDL_Texture* m_texture;//! Sprite texture
};

#endif /** __YSPRITE __ **/

/** @}*/