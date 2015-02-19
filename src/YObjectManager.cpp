#include "YObjectManager.h"

/** C++ **/
#include <cassert>


YObjectManager::YObjectManager()
{
	m_started = false;
}

YObjectManager~YObjectManager()
{

}

void YObjectManager::add(YObject* a_object)
{
	assert(a_object != nullptr);

	m_objects.push_back(a_object);
}

void YObjectManager::remove(YObject* a_object)
{
	m_objects.erase(std::remove(m_objects.begin(),
								m_objects.end(), 
								a_object), 
					m_object.end());
}

void YObjectManager::start()
{
	if (m_started == false)
	{
	    struct
	    {
	        bool operator()(YObject* a_first, YObject* a_second) const
	        {
	            return a_first->position().z() < a_second->position().z();
	        }
	    } Comparator;

	    m_update = [&](SDL_Event* a_event, float a_deltaT)
	    {
	        std::sort(m_objects.begin(),
	                  m_objects.end(),
	                  Comparator);
	        
	        for (const YObject& object: m_objects)
	        {
	            object.processEvents(a_event);
	            object.update(a_deltaT);					        	
	        }
	    };
	    
	    m_render = [&](SDL_Renderer* a_renderer)
	    {
	        for (const YObject& object: m_objects)
	        {
	            object.render(a_renderer);
	        }	    	
	    };	
	}
}