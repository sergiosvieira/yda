/****************************************************************************
 Copyright (c) 2015 Sérgio Vieira - sergiosvieira@gmail.com
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "YObjectManager.h"

/** C++ **/
#include <cassert>
#include <algorithm>

/** YDA */
#include "YObject.cpp"

YObjectManager::YObjectManager()
{
    m_started = false;
    updateRender();    
}

void YObjectManager::add(YObject* a_object)
{
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
