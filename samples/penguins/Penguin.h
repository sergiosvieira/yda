#ifndef __PENGUIN__
#define __PENGUIN__

/** YDA **/
#include "YMain.h"
#include "YObject.h"
#include "YVector.h"



class Penguin: public YObject
{
public:
    Penguin(YSprite* a_sprite,
            YMain* a_main): YObject(nullptr,
                                    a_sprite,
                                    YPoint(a_main->width() / 2.f, 0.f),
                                    YPoint(0.f, 0.f),
                                    true)
    {
        m_jumping = false;
        m_main = a_main;
        m_speed = 4.f;
    };
    virtual void processEvents(SDL_Event* a_event) override;
    virtual void update(float a_deltaT) override;
    void startJump();
    void endJump();
protected:
    YMain* m_main;
    bool m_jumping;
    YVector m_velocity;
    float m_speed;
};

#endif /** __PENGUIM__ **/
