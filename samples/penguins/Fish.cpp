#include "Fish.h"

void Fish::jump()
{
    if (m_jumping == false)
    {
        m_jumping = true;
        m_velocity = YVector(m_velocity.x(), -12.f);
    }
}

void Fish::update()
{
    YVector gravity = YVector(0.f, 0.45);
    
    m_velocity = m_velocity + gravity;
    m_position = m_position.add(m_velocity);
    
    if (m_position.y() > 430.f)
    {
        m_position = YPoint(m_position.x(), 430.f);
        m_jumping = false;
        
        if (m_position.x() > 150 &&
            m_position.x() < 380)
        {
            jump();
            visible(true);
        }
        else
        {
            visible(false);
        }
    }
    
    if (m_position.x() < 0 ||
        m_position.x() > 640)
    {
        m_velocity = YVector(m_velocity.x() * -1.f, m_velocity.y());
        
        if (m_velocity.x() >= 0)
        {
            currentFrame(0);
            firstFrame(0);
            lastFrame(2);
        }
        else
        {
            currentFrame(3);
            firstFrame(3);
            lastFrame(5);
        }
        
    }
}