#include "YMain.h"

/** YDA **/
#include "YObjectManager.h"
#include "YSpriteManager.h"
#include "YPoint.h"
#include "YVector.h"
#include "YFileSystem.h"

/** Penguin **/
#include "../z-order/Cloud.h"
#include "YSprite.h"

/** C++ **/
#include <functional>
#include <array>
#undef main

static const char* kBackground = "background";
static const char* kCloud_01 = "cloud_01";
static const char* kCloud_02 = "cloud_02";

void createClouds(YMain* a_main,
                  std::vector<Cloud*>&& a_clouds,
                  int a_size,
                  YSpriteManager* a_manager)
{
    a_clouds.reserve(a_size);
    
    for (int i = 0; i < a_size; ++i)
    {
        const char* name = (i % 2 == 0) ? kCloud_01 : kCloud_02;
        float z = (i % 2 == 0) ? 0.f : 2.f;
        YSprite* cloudSprite = new YSprite(a_manager->findByName(name));
        Cloud* cloud01 = new Cloud(cloudSprite, a_main);
        YPoint position = cloud01->position();
        
        position.z(z);
        cloud01->position(position);
        a_clouds.push_back(cloud01);
    }
}

YSpriteManager::Error loadResources(YSpriteManager* a_manager)
{
    typedef struct
    {
        std::string key;
        std::string value;
    } KeyValue;
    

    std::array<KeyValue, 7> images = {
        {
            {kBackground, "scenario.png"},
            {kCloud_01, "cloud_01.png"},
            {kCloud_02, "cloud_02.png"},
            {"penguin", "penguin.png"},
            {"fish_blue", "fish_blue.png"},
    		{"crab_pink", "crab_pink.png"},
            {"scuma", "scuma.png"}
        }
    };
    
    bool success = true;
    YSpriteManager::Error result;
    
    for (const KeyValue& kv: images)
    {
        std::string fullPath;
        YFileSystem::fullPathName(fullPath,
                                  {"gfx"},
                                  kv.value.c_str());

        result = a_manager->add(kv.key.c_str(), fullPath);

        if (result != YSpriteManager::NONE)
        {
            printf("Error on loading %s\n",
                   kv.value.c_str());
            success &= false;
        }
    }
    
    return success == true ? YSpriteManager::NONE : YSpriteManager::LOADING_ERROR;
}

int main(int argc, char* argv[])
{
    YObjectManager* objectManager = new YObjectManager();
	/** creates window **/
    YMain* game = new YMain("Penguins - sergiosvieira@gmail.com",
                            640, 480,
                            objectManager);
    
	/** loads resources **/
	YSpriteManager* spriteManager = new YSpriteManager(game->SDLRenderer());

    loadResources(spriteManager);
    game->textureBackground(spriteManager->findByName(kBackground));

    /** Creates Clouds **/
    std::vector<Cloud*> clouds;
    createClouds(game,
                 std::move(clouds),
                 10,
                 spriteManager);

    for (Cloud* cloud: clouds)
    {
        objectManager->add(cloud);
    }

    game->start();

    delete spriteManager;
    delete game;
    delete objectManager;

	return 0;
}
