#include "YGameObject.h"

/** YDA **/
#include "YSprite.h"

/** SDL2 **/
#include <SDL.h>
#include <SDL2_image/SDL_image.h>


void YGameObject::render(SDL_Renderer* a_renderer,
                         YSprite* a_sprite) const
{
    SDL_Rect srcRect = a_sprite->rect();
    SDL_Rect dstRect;
    
    dstRect.x = m_position.x();
    dstRect.y = m_position.y();
    dstRect.w = a_sprite->width();
    dstRect.h = a_sprite->height();
    
    SDL_RenderCopy(a_renderer,
                   a_sprite->texture(),
                   &srcRect,
                   &dstRect);
}

YPoint YGameObject::position() const
{
	return m_position;
}

void YGameObject::position(YPoint a_position)
{
	m_position = a_position;
}

YPoint YGameObject::anchor() const
{
	return m_anchor;
}

void YGameObject::anchor(YPoint a_anchor)
{
	m_anchor = a_anchor;
}

void YGameObject::visible(bool a_value)
{
	m_visible = a_value;
}

bool YGameObject::isVisible() const
{
	return m_visible;
}
