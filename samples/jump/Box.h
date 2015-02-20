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

#ifndef __BOX__
#define __BOX__

/** YDA **/
#include "YGameObject.h"
#include "YVector.h"

class YSprite;
union SDL_Event;


class Box: public YGameObject
{
public:
    //! Default constructor overriding
    Box(YSprite* a_sprite);
    ~Box();
    //! Process SDL Events
    void processEvents(SDL_Event* a_event);
    //! Update overriding
    void update(float a_deltaT);
    //! Starting jump method
    void startJump();
    //! Ending jump method
    void endJump();
private:
    bool m_onGround; //! Checks if the box is on the ground
    YVector m_velocity;
    YVector m_gravity;
    YSprite* m_sprite;
};

#endif /** __BOX__ */
