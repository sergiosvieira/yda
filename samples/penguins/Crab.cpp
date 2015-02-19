#include "Crab.h"

/** YDA **/
#include "YPoint.h"


void Crab::start(SDL_Rect a_islandRect)
{
	m_islandRect = a_islandRect;
	m_visible = true;
}

void Crab::jump()
{
	if (m_jumping == false &&
		m_visible == true)
	{
		m_jumping = true;
		m_velocity = YVector(m_velocity.x(), -20.f);
	}
}


void Crab::update()
{
	if (m_visible)
	{
		bool swimming = false;
		float offset = 15.0;

        if (m_position.x() < m_islandRect.x + m_islandRect.w &&
            m_position.x() + m_frameWidth > m_islandRect.x)
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

		YVector gravity = YVector(0.f, 2.f);

		m_velocity = m_velocity + gravity;
        
        YVector velocity = YVector(m_velocity.x(), m_velocity.y() + (swimming == true ? offset : 0.0));
        
		m_position = m_position.add(velocity);

		if (m_position.y() > m_seaY + (swimming == true ? offset : 0.0))
		{
			m_position = YPoint(m_position.x(),
								m_seaY + (swimming == true ? offset : 0.0));
			m_velocity = YVector(m_velocity.x(),
								 0.f);
			m_jumping = false;
		}

        if (swimming)
        {
            m_scuma->visible(true);
        }
        
		if (m_position.x() < 5.0 || 
			m_position.x() > 620 - 16)
		{
			/** invert velocity vector **/
			m_velocity = YVector(0.f, 0.f) - m_velocity;
		}
        
        m_scuma->position(YPoint(m_position.x(), m_position.y() + 10.f));
	}
}