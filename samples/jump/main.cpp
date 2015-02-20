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
#include "YSprite.h"
#include "YFileSystem.h"
 #include "YObjectManager.h"
#include "Box.h"

/** STL **/
#include <array>

YSpriteManager::Error loadResources(YSpriteManager* a_manager)
{
    typedef struct Sprites
    {
        std::string key;
        std::string value;
    } KeyValue;
    
    std::array<KeyValue, 2> images = 
    {
        {
            {"box", "box.png"},
            {"background", "background.png"}
        }
    };

    bool success = true;
    YSpriteManager::Error result;
    
    for (const KeyValue& kv: images)
    {
        result = a_manager->add(kv.key.c_str(),
                                YFileSystem::fullPathName({"gfx"},
                                                           kv.value.c_str()));

        if (result != YSpriteManager::NONE)
        {
            printf("Error on loading %s\n",
                   kv.value.c_str());
            success &= false;
        }
    }
    
    return success == true ? YSpriteManager::NONE : YSpriteManager::LOADING_ERROR;
}

int main(int argc, char** argv)
{
    /** creates window **/
    YObjectManager* objectManager = new YObjectManager();
    YMain* game = new YMain("Jumping - sergiosvieira@gmail.com",
                            640, 480,
                            objectManager);
    
    /** loads resources **/
    YSpriteManager* spriteManager = new YSpriteManager(game->SDLRenderer());
    
    if (loadResources(spriteManager) != YSpriteManager::NONE)
    {
        printf("Error on loading resources!\n");
        
        return 1;
    }
    
    SDL_Texture* background = spriteManager->findByName("background");

    game->textureBackground(background);

    YSprite* boxSprite = new YSprite(spriteManager->findByName("box"));
    Box* box = new Box(boxSprite);
    
    objectManager->add(box);

    game->start();
    
    return 0;
}