#include "YObjectManager.h"

/** C++ **/
#include <cassert>

/** YDA */
#include "YObject.cpp"

YObjectManager::YObjectManager()
{
    m_started = false;
}

YObjectManager::~YObjectManager()
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
                    m_objects.end());
}

void YObjectManager::updateRender()
{
    if (m_started == false)
    {
        m_started = true;
        
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
            
            for (YObject* object: m_objects)
            {
                object->processEvents(a_event);
                object->update(a_deltaT);
            }
        };
        
        m_render = [&](SDL_Renderer* a_renderer)
        {
            for (YObject* object: m_objects)
            {
                object->render(a_renderer);
            }	    	
        };	
    }
}

YMain::FunctionUpdate* YObjectManager::updater()
{
    return &m_update;
}

YMain::FunctionRender* YObjectManager::renderer()
{
    return &m_render;
}