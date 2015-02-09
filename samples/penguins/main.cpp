#include "YMain.h"

/** YDA **/
#include "YSpriteSheetManager.h"
#include "YFileSystem.h"

/** Penguin **/
#include "Penguin.h"

/** C++ **/
#include <functional>
#undef main

YSpriteSheetManager::kError loadResources(YSpriteSheetManager* a_manager)
{
    typedef struct Sprites
    {
        std::string key;
        std::string value;
    } Sprite;
    
    Sprite sprites[] = {
        {"background", "scenario.png"},
        {"penguin", "penguin.png"},
        {"fish", "fish.png"},
    };
    
    int size = sizeof(sprites) / sizeof(Sprite);
    bool success = true;
    YSpriteSheetManager::kError result;
    
    for (int i = 0; i < size; ++i)
    {
        std::string key = sprites[i].key;
        std::string value = YFileSystem::getCurrentDir() + "/" + sprites[i].value;
        
        result = a_manager->add(key, value);

        if (result != YSpriteSheetManager::NONE)
        {
            success &= false;
        }
    }
    
    return success == true ? YSpriteSheetManager::NONE : YSpriteSheetManager::LOADING_ERROR;
}

int main(int argc, char* argv[])
{
	/** creates window **/
    YMain* game = new YMain("Penguins - sergiosvieira@gmail.com",
                            640,
                            480);
    
	/** loads resources **/
	YSpriteSheetManager* spriteManager = new YSpriteSheetManager(game->renderer());
    loadResources(spriteManager);

	/** creates penguin **/
	Penguin* penguin = new Penguin(spriteManager->findByName("penguin"),
								   160.0,
								   -10.0,
								   YFrame(0, 0, 8, 10, 10, 5));
	penguin->firstFrame(0);
	penguin->lastFrame(3);

	float gravity = 15.0;
	float ground = 410;
	bool falling = true;

    YMain::FunctionUpdate update = [&](SDL_Event* a_event)
    {	

		if (falling == true)
		{
			if (penguin->y() + gravity < ground)
			{
				penguin->moveBy(0.0, 15.0); // 15 pixels x framerate
				penguin->currentFrame(8);
				penguin->pause(true);
			}
			else
			{
				penguin->y(ground);
				falling = false;
			}
		}
		else
		{
			penguin->pause(false);

			if( a_event->type == SDL_MOUSEBUTTONDOWN )
			{
				penguin->startJump();
			}
			else if (a_event->type == SDL_MOUSEBUTTONUP)
			{
				penguin->endJump();
			}

			penguin->update();
		}
    };
    
    YMain::FunctionRender render = [&](SDL_Renderer* a_renderer)
    {
		SDL_RenderCopy(a_renderer,
					   spriteManager->findByName("background"),
					   NULL,
					   NULL);
        SDL_Rect nextFrameRect = penguin->nextFrame();
        SDL_Rect dstRect = penguin->rect(4);
		SDL_RenderCopy(a_renderer,
					   penguin->texture(),
					   &nextFrameRect,
					   &dstRect);
    };
    
    game->start(&update,
                &render,
                25,
                5);
    
    
    delete game;
    
	return 0;
}
