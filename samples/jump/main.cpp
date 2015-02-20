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
#include "YSpriteSheetManager.h"
#include "YSprite.h"
#include "YFileSystem.h"
#include "Box.h"

YSpriteSheetManager::Error loadResources(YSpriteSheetManager* a_manager)
{
    typedef struct Sprites
    {
        std::string key;
        std::string value;
    } Sprite;
    
    Sprite sprites[] = {
        {"box", "box.png"},
        {"background", "background.png"}
    };
    
    int size = sizeof(sprites) / sizeof(Sprite);
    bool success = true;
    YSpriteSheetManager::Error result;
    
    for (int i = 0; i < size; ++i)
    {
        std::string key = sprites[i].key;
        std::string value = YFileSystem::getCurrentDir() +
                            YFileSystem::kSeparator +
                            "gfx" +
                            YFileSystem::kSeparator +
                            sprites[i].value;
        
        result = a_manager->add(key, value);
        
        if (result != YSpriteSheetManager::NONE)
        {
            printf("Error on loading %s\n",
                   value.c_str());
            success &= false;
        }
    }
    
    return success == true ? YSpriteSheetManager::NONE : YSpriteSheetManager::LOADING_ERROR;
}

int main(int argc, char** argv)
{
    /** creates window **/
    YMain* game = new YMain("Jumping - sergiosvieira@gmail.com",
                            640,
                            480);
    
    /** loads resources **/
    YSpriteSheetManager* spriteManager = new YSpriteSheetManager(game->renderer());
    
    if (loadResources(spriteManager) != YSpriteSheetManager::NONE)
    {
        printf("Error on loading resources!\n");
        
        return 1;
    }
    
    SDL_Texture* background = spriteManager->findByName("background");
    YSprite* boxSprite = new YSprite(spriteManager->findByName("box"));
    Box* box = new Box(boxSprite);
    
    YMain::FunctionUpdate update = [&](SDL_Event* a_event, float a_deltaT)
    {
        box->processEvents(a_event);
        box->update(a_deltaT);
    };
    
    YMain::FunctionRender renderer = [&](SDL_Renderer* a_renderer)
    {
        SDL_RenderCopy(a_renderer,
                       background,
                       nullptr,
                       nullptr);
        box->render(a_renderer,
                    boxSprite);
    };
    
    game->start(&update,
                &renderer,
                25,
                5);
    
    return 0;
}