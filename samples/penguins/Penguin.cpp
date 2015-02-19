#include "Penguin.h"


void Penguin::startJump()
{
	if (m_onGround == true)
	{
		m_velocity = YVector(m_velocity.x(), -12.f);
		m_onGround = false;
	}
}

void Penguin::endJump()
{
    if (m_velocity.y() < -6.0)
	{
		m_velocity = YVector(m_velocity.x(), -6.f);
	}
}

void Penguin::onGround(bool a_value)
{
	m_onGround = a_value;
}

void Penguin::update()
{
	m_velocity = m_velocity + m_gravity;
	m_position = m_position.add(m_velocity);
    
    if (m_position.y() > 410.f)
    {
		m_position = YPoint(m_position.x(), 410.f);
        m_velocity = YVector(m_velocity.x(), 0.f);
        m_onGround = true;
    }    

    if (m_position.x() < 150.f || 
		m_position.x() > 350.f)
	{
		/** invert vector **/
		m_velocity = YVector(0, 0) - m_velocity;

		if (m_velocity.x()> 0.f)
		{
			this->currentFrame(0);
			this->frameRange(0, 3);
		}
		else
		{
			this->currentFrame(4);
			this->frameRange(4, 7);
		}
	}
}