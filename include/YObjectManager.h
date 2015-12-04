/** \addtogroup YDA
 *  @{
 */

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

#ifndef __YOBJECT_MANAGER__
#define __YOBJECT_MANAGER__

/** YDA **/
#include "YMain.h"
#include "YObject.h"

/** STL **/
#include <vector>

/*!
  This class is used to manager the objects of the game (deallocation, z-order etc)
*/
class YObjectManager
{
public:
    typedef std::vector<YObject*> VectorOfYObjects;
    //! Default constructor
    YObjectManager();
    //! Adds a object to manager
    /*!
      \param YObject - Game object pointer
    */
    void add(YObject* a_object);
    //! Remove a object from manager
    /*!
      \param YObject - Game object pointer
    */
    void remove(YObject* a_object);
    //! Get object pointer at index
    YObject* operator[](int a_index) const
    {
        return m_objects.at(a_index);
    }
    //! Starting to update and render game objects
    void updateRender();
    //! Updater
    YMain::FunctionUpdate* updater();
    //! Renderer
    YMain::FunctionRender* renderer();
protected:
	int m_size; //! amount of objects
    VectorOfYObjects m_objects;//! Vector of YObject pointers
	YMain::FunctionUpdate m_update;//! Function update
	YMain::FunctionRender m_render;//! Function render
private:
    struct
    {
        bool operator()(YObject* a_first, YObject* a_second) const
        {
            return a_first->position().z() < a_second->position().z();
        }
    } Comparator;
	bool m_started;//! Stating update and render flag
};

#endif /** __YOBJECT_MANAGER__ **/

/** @}*/
