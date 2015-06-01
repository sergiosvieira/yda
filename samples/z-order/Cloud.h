/** \addtogroup Samples
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

/** YDA **/
#include "YObject.h"
#include "YPoint.h"
#include "YVector.h"
#include "YMain.h"

/** C++ **/
#include <random>


static std::mt19937_64 seed;

class Cloud: public YObject
{
public:
    Cloud(YSprite* a_sprite,
          YMain* a_main): YObject(nullptr,
                                  a_sprite,
                                  YPoint<int>(0, 0),
                                  YPoint<int>(0, 0),
                                  true)
    {
        m_main = a_main;
        randomize();
    };
    void update(float a_deltaT)
    {
        if (m_position.x() > m_main->width())
        {
            randomize();
        }
        
        m_position = m_position.add(m_velocity);
    }
protected:
    YMain* m_main;
    YVector m_velocity;
    void randomize()
    {
        std::uniform_int_distribution<> distributionY(0, m_main->height() / 2.f);
        std::uniform_real_distribution<> velocityX(0.5, 3.5);
        m_velocity = YVector(velocityX(seed), 0.f);
        m_position = YPoint<int>(-m_main->width(),
                            distributionY(seed), 
                            (m_velocity.x() <= 1.5f) ? 0.f : 2.f );
    }
};

/** @}*/
