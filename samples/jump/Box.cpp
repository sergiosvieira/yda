#include "Box.h"

/** C++ **/
#include <cstddef>

/** YDA **/
#include "YSprite.h"

/** SDL2 **/
#include <SDL.h>

void Box::processEvents(SDL_Event *a_event)
{
    if( a_event->type == SDL_MOUSEBUTTONDOWN )
    {
        startJump();
    }
    else if (a_event->type == SDL_MOUSEBUTTONUP)
    {
        endJump();
    }
}

void Box::update(float a_deltaT)
{
    m_velocity = m_velocity + m_gravity;
    m_position = m_position.add(m_velocity);
    
    if (m_position.y() + m_sprite->height() > 350.f)
    {
        m_position = YPoint<int>(m_position.x(), 350 - m_sprite->height());
        m_velocity = YVector(m_velocity.x(), 0.f);
        m_onGround = true;
    }
    
    if (m_position.x() + m_sprite->width() > 640.f ||
        m_position.x() < 0.f)
    {

        m_velocity = YVector(m_velocity.x() * -1.0, m_velocity.y());
    }
}

void Box::startJump()
{
    if (m_onGround == true)
    {
        m_velocity = YVector(m_velocity.x(), -12.f);
        m_onGround = false;
    }
}

void Box::endJump()
{
    if (m_velocity.y() < -6.0)
    {
        m_velocity = YVector(m_velocity.x(), -6.f);
    }
}