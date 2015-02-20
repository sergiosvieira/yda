#include "YObject.h"

#include "YVector.h"

union SDL_Event;

class Box: public YObject
{
public:
    Box(YSprite* a_sprite): YObject(nullptr,
                                     a_sprite,
                                     YPoint(320.f, 240.f, 1.f),
                                     YPoint(0.f, 0.f),
                                     true)
    {
        m_onGround = false;
        m_velocity = YVector(4.f, 0.f);
        m_gravity = YVector(0.0f, 0.8);          
    };
    ~Box(){};
    //! Process SDL Events
    void processEvents(SDL_Event* a_event);
    void update(float a_deltaT);
    //! Starting jump method
    void startJump();
    //! Ending jump method
    void endJump();    
protected:
    bool m_onGround; //! Checks if the box is on the ground
    YVector m_velocity;
    YVector m_gravity;    
};