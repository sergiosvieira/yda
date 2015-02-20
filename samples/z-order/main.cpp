/** YDA **/
#include "YMain.h"
#include "YSpriteManager.h"
#include "YFileSystem.h"
#include "YSprite.h"
#include "YSpriteSheet.h"
#include "YObject.h"
#include "YObjectManager.h"
#include "Bird.h"
#include "Cloud.h"

/** STL **/
#include <array>
#include <algorithm>

const char* kCloud01 = "cloud_01";
const char* kCloud02 = "cloud_02";
const char* kRedBird = "red_bird";

void createClouds(std::vector<Cloud*>&& a_clouds,
                  int a_size,
                  YSpriteManager* a_manager)
{
    a_clouds.reserve(a_size);
    
    for (int i = 0; i < a_size; ++i)
    {
        const char* name = (i % 2 == 0) ? kCloud01 : kCloud02;
        float z = (i % 2 == 0) ? 0.f : 2.f;
        YSprite* cloudSprite = new YSprite(a_manager->findByName(name));
        Cloud* cloud01 = new Cloud(cloudSprite);
        YPoint position = cloud01->position();
        
        position.z(z);
        cloud01->position(position);
        a_clouds.push_back(cloud01);
    }
}

int main(int argc, char** argv)
{
    typedef struct
    {
        std::string key;
        std::string value;
    } KeyValue;
    
    YObjectManager* objectManager = new YObjectManager();
    YMain* game = new YMain("Z-Order - sergiosvieira@gmail.com",
                            640, 480,
                            objectManager);
    
    /** Load Resources **/
    YSpriteManager* manager = new YSpriteManager(game->SDLRenderer());
    std::array<KeyValue, 3> images = {
      {
          {kCloud01, "cloud_01.png"},
          {kCloud02, "cloud_02.png"},
          {kRedBird, "red_bird_set.png"}
      }
    };
    
    for (const KeyValue& kv: images)
    {
        manager->add(kv.key.c_str(),
                     YFileSystem::fullPathName({"gfx"},
                                               kv.value.c_str()));
    }
    
    /** Creates Clouds **/
    std::vector<Cloud*> clouds;
    createClouds(std::move(clouds),
                 100,
                 manager);
    

    /** Creates Bird **/
    YSpriteSheet* birdSprite = new YSpriteSheet(manager->findByName("red_bird"),
                                                YFrame(0, 0, 5),
                                                64,
                                                40,
                                                20);
    Bird* bird = new Bird(birdSprite);
    
    /** Update/Render Objects **/
    for (Cloud* cloud: clouds)
    {
        objectManager->add(cloud);
    }
    
    objectManager->add(bird);
    game->start();
    
    delete objectManager;
    delete game;
    delete manager;
    
    return 0;
}