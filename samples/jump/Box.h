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
