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
#include "YMain.h"
#include "YSpriteManager.h"
#include "YFileSystem.h"
#include "YSprite.h"
#include "YSpriteSheet.h"
#include "YObject.h"
#include "YObjectManager.h"
#include "Bird.h"
#include "Cloud.h"
#include "Background.h"
#include "YSpriteHeader.h"

/** STL **/
#include <array>
#include <algorithm>

const char* kCloud01 = "cloud_01";
const char* kCloud02 = "cloud_02";
const char* kRedBird = "red_bird";
const char* kBackground = "background";

void createClouds(YMain* a_main,
                  std::vector<Cloud*>&& a_clouds,
                  int a_size,
                  YSpriteManager* a_manager)
{
    a_clouds.reserve(a_size);
    
    for (int i = 0; i < a_size; ++i)
    {
        const char* name = (i % 2 == 0) ? kCloud01 : kCloud02;
        float z = (i % 2 == 0) ? 0.f : 2.f;
        YSprite* cloudSprite = new YSprite(a_manager->findByName(name));
        Cloud* cloud01 = new Cloud(cloudSprite, a_main);
        YPoint<int> position = cloud01->position();
        
        position.z(z);
        cloud01->position(position);
        a_clouds.push_back(cloud01);
    }
}

#undef main
int main(int argc, char** argv)
{
    typedef struct
    {
        std::string key;
        std::string value;
    } KeyValue;
    
    YObjectManager* objectManager = new YObjectManager();
    YMain* game = new YMain("Z-Order - sergiosvieira@gmail.com",
                            YSize<int>(320, 240),
                            *objectManager);
    
    /** Load Resources **/
    YSpriteManager* manager = new YSpriteManager(*game->SDLRenderer());
    std::array<KeyValue, 4> images = {
      {
          {kCloud01, "cloud_01.png"},
          {kCloud02, "cloud_02.png"},
          {kRedBird, "red_bird_set.png"},
          {kBackground, "background.png"}
      }
    };
    
    for (const KeyValue& kv: images)
    {
        std::string fullpath;

        YFileSystem::fullPathName(fullpath,
                                  {"gfx"},
                                  kv.value.c_str());
        manager->add(kv.key.c_str(), fullpath);
    }
    
    /** Creates Background **/
    YSprite* bgSprite = new YSprite(manager->findByName(kBackground));
    Background* bg = new Background(bgSprite);

    bg->position().z(-1.f);
    objectManager->add(bg);


    /** Creates Clouds **/
    std::vector<Cloud*> clouds;
    createClouds(game,
                 std::move(clouds),
                 10,
                 manager);
    

    /** Creates Bird **/
    YFrame frame(0, 0, 5, YSize<int>(32, 32));
    YSpriteSheet* birdSprite = new YSpriteSheet(manager->findByName(kRedBird),
                                                frame,
                                                25);
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
