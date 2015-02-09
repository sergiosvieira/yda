#include "Penguin.h"


void Penguin::moveBy(float a_x,
					 float a_y)
{
	m_x += a_x;
	m_y += a_y;
}

void Penguin::startJump()
{
	if (m_onGround == true)
	{
		m_velocityY = -12.f;
		m_onGround = false;
	}
}

void Penguin::endJump()
{
    if (m_velocityY < -6.0)
	{
        m_velocityY = -6.0;
	}
}

void Penguin::onGround(bool a_value)
{
	m_onGround = a_value;
}

void Penguin::update()
{
	float gravity = 0.8;

	m_velocityY += gravity;
    m_y += m_velocityY;
    m_x += m_velocityX;
    
    if (m_y > 410.f)
    {
        m_y = 410;
        m_velocityY = 0.0;
        m_onGround = true;
    }    

    if (m_x < 150.f || m_x > 350.f)
	{
        m_velocityX *= -1.f;

		if (m_velocityX > 0.f)
		{
			this->currentFrame(0);
			this->firstFrame(0);
			this->lastFrame(3);
		}
		else
		{
			this->currentFrame(4);
			this->firstFrame(4);
			this->lastFrame(7);
		}
	}
}