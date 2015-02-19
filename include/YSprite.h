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
protected:
	int m_width;//! Sprite width
	int m_height;//! Sprite height
	SDL_Texture* m_texture;//! Sprite texture
};

#endif /** __YSPRITE __ **/