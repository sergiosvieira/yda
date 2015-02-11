#include "Crab.h"

void Crab::start(SDL_Rect a_islandRect)
{
	m_islandRect = a_islandRect;
	m_visible = true;
	//jump();
}

void Crab::jump()
{
	if (m_jumping == false &&
		m_visible == true)
	{
		m_jumping = true;
		m_velocityY = -20.f;
	}
}


void Crab::update()
{
	if (m_visible)
	{
		bool swimming = false;
		float offset = 15.0;

        if (m_x < m_islandRect.x + m_islandRect.w &&
            m_x + m_frame.width > m_islandRect.x)
        {
            m_scuma->visible(false);
			if (m_state == JUMP_TO_ISLAND)
			{
				this->jump();
				m_state = JUMP_FROM_ISLAND;
			}

			m_frame.height = m_oldHeight;
		}
		else
		{
			if (m_state == JUMP_FROM_ISLAND)
			{
				this->jump();
				m_state = JUMP_TO_ISLAND;
			}

			swimming = true;
			m_frame.height = m_oldHeight - 3.0;
		}

		float gravity = 2.0;

		m_velocityY += gravity;
		m_y += m_velocityY + (swimming == true ? offset : 0.0);    
		m_x += m_velocityX;

		if (m_y > m_seaY + (swimming == true ? offset : 0.0))
		{
			m_y = m_seaY + (swimming == true ? offset : 0.0);
			m_velocityY = 0.0;
			m_jumping = false;
		}

        if (swimming)
        {
            m_scuma->visible(true);
        }
        
		if (m_x < 5.0
			|| m_x > 620 - 16)
		{
			m_velocityX *= -1.0;
		}
        
        m_scuma->x(m_x);
        m_scuma->y(m_y + 10.0);
        
	}
}