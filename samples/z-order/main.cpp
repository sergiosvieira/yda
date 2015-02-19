/** YDA **/
#include "YMain.h"
#include "YSpriteManager.h"
#include "YFileSystem.h"
#include "YSprite.h"
#include "YSpriteSheet.h"
#include "YObject.h"
#include "Bird.h"
#include "Cloud.h"

/** STL **/
#include <array>
#include <algorithm>

int main(int argc, char** argv)
{
    struct
    {
        bool operator()(YObject* a_first, YObject* a_second) const
        {
            return a_first->position().z() < a_second->position().z();
        }
    } Comparator;
    
    const char* kCloud01 = "cloud01";
    const char* kCloud02 = "cloud02";
    const int size = 20;
    std::array<YObject*, size> objects;
    YMain* game = new YMain("Z-Order - sergiosvieira@gmail.com",
                            640,
                            480);
    YSpriteManager* manager = new YSpriteManager(game->renderer());
    
    manager->add(kCloud01, YFileSystem::fullPathName({"gfx"},
                                                     "cloud_01.png"));
    manager->add(kCloud02, YFileSystem::fullPathName({"gfx"},
                                                     "cloud_02.png"));
    manager->add("red_bird", YFileSystem::fullPathName({"gfx"},
                                                    "red_bird_set.png"));
    
    for (int i = 0; i < size - 1; ++i)
    {
        const char* name = (i % 2 == 0) ? kCloud02 : kCloud02;
        float z = (i % 2 == 0) ? 0.f : 2.f;
        YSprite* cloudSprite = new YSprite(manager->findByName(name));
        Cloud* cloud01 = new Cloud(cloudSprite);
        YPoint position = cloud01->position();
        
        position.z(z);
        cloud01->position(position);
        objects[i] = cloud01;
    }
    
    YSpriteSheet* birdSprite = new YSpriteSheet(manager->findByName("red_bird"),
                                                YFrame(0, 0, 5),
                                                64,
                                                40,
                                                20);
    Bird* bird = new Bird(birdSprite);
    
    objects[size - 1] = bird;
    
    YMain::FunctionUpdate update = [&](SDL_Event* a_event, float a_deltaT)
    {
        std::sort(objects.begin(),
                  objects.end(),
                  Comparator);
        
        for (int i = 0; i < size; ++i)
        {
            objects[i]->processEvents(a_event);
            objects[i]->update(a_deltaT);
        }
    };
    
    YMain::FunctionRender renderer = [&](SDL_Renderer* a_renderer)
    {
        for (int i = 0; i < size; ++i)
        {
            objects[i]->render(a_renderer);
        }
    };
    
    game->start(&update,
                &renderer,
                25,
                5);
    
    for (int i = 0; i < size; ++i)
    {
        if (objects[i] != nullptr)
        {
            delete objects[i];
        }
    }
    
    return 0;
}