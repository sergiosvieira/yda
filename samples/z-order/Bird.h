class Bird: public YObject
{
public:
    Bird(YSprite* a_sprite): YObject(nullptr,
                                     a_sprite,
                                     YPoint(320.f, 240.f, 1.f),
                                     YPoint(0.f, 0.f),
                                     true)
    {
    };
    void update(float a_deltaT)
    {
    };
};
