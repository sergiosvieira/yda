#include "Penguin.h"

void Penguin::processEvents(SDL_Event* a_event)
{
	if (a_event->type == SDL_KEYDOWN)
	{	
		switch (a_event->key.keysym.sym)
		{
			case SDLK_LEFT:
			{

			} break;

			case SDLK_RIGHT:
			{

			} break;
		}
	}
}

void Penguin::update(float a_deltaT)
{

}

void Penguin::startJump()
{
	if (m_onTheGround == true)
	{
		m_onTheGround = false;
	}
}

void Peguin::endJump()
{

}
