/** YDA **/
#include "YObject.h"
#include "YPoint.h"
#include "YVector.h"

/** C++ **/
#include <random>

static std::mt19937_64 seed;

class Cloud: public YObject
{
public:
    Cloud(YSprite* a_sprite): YObject(nullptr,
                                      a_sprite,
                                      YPoint(0.f, 0.f),
                                      YPoint(0.f, 0.f),
                                      true)
    {
        randomize();
    };
    void update(float a_deltaT)
    {
        if (m_position.x() > 640)
        {
            randomize();
        }
        
        m_position = m_position.add(m_velocity);
    }
protected:

    YVector m_velocity;
    void randomize()
    {
        std::uniform_int_distribution<> distributionY(0, 480);
        std::uniform_real_distribution<> velocityX(0.5, 3.5);
        m_velocity = YVector(velocityX(seed), 0.f);
        m_position = YPoint(-320, distributionY(seed), (m_velocity.x() <= 1.5f) ? 0.f : 2.f );
    }
};
