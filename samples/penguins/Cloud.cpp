#include "Cloud.h"

/** C++ **/
#include <random>
#include <iostream>

void Cloud::update(float a_deltaT)
{
    if (m_position.x() + m_width < 0)
    {
        std::random_device randomDevice;
        std::mt19937_64 seed(randomDevice());
        std::uniform_int_distribution<> distributionX(m_screenSize.x, m_screenSize.w);
        std::uniform_int_distribution<> distributionY(m_screenSize.y, m_screenSize.h);
        std::uniform_real_distribution<> velocityX(0.5, 3.0);
        m_position = YPoint(m_screenSize.w + distributionX(seed), distributionY(seed));
        m_velocity = YVector(-1.f * velocityX(seed), 0.f);
    }
    
    m_position = m_position.add(m_velocity);
}
