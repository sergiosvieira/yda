
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