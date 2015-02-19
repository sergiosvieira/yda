#include "YObject.h"

/** YDA **/
#include "YSprite.h"

/** C++ **/
#include <cassert>

/** SDL2 **/
#include <SDL.h>
#include <SDL2_image/SDL_image.h>

/** Public Methods **/
void YObject::render(SDL_Renderer* a_renderer) const
{
    assert(a_renderer != nullptr);
    assert(m_sprite != nullptr);
    
    SDL_Rect srcRect = m_sprite->rect();
    SDL_Rect dstRect;
    
    dstRect.x = m_position.x();
    dstRect.y = m_position.y();
    dstRect.w = m_sprite->width();
    dstRect.h = m_sprite->height();
    
    SDL_RenderCopy(a_renderer,
                   m_sprite->texture(),
                   &srcRect,
                   &dstRect);
}

YPoint YObject::position() const
{
	return m_position;
}

void YObject::position(YPoint a_position)
{
	m_position = a_position;
}

YPoint YObject::anchor() const
{
	return m_anchor;
}

void YObject::anchor(YPoint a_anchor)
{
	m_anchor = a_anchor;
}

void YObject::visible(bool a_value)
{
	m_visible = a_value;
}

bool YObject::isVisible() const
{
	return m_visible;
}

YSprite* YObject::sprite() const
{
    return m_sprite;
}