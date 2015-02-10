#include "YMain.h"

/** YDA **/
#include "YSpriteSheetManager.h"
#include "YFileSystem.h"

/** Penguin **/
#include "Penguin.h"
#include "Fish.h"
#include "Crab.h"

/** C++ **/
#include <functional>
#include <vector>
#undef main

YSpriteSheetManager::kError loadResources(YSpriteSheetManager* a_manager)
{
    typedef struct Sprites
    {
        std::string key;
        std::string value;
    } Sprite;
    
    Sprite sprites[] = {
        {"background", "tropical_island_day.png"},
        {"penguin", "penguin.png"},
        {"fish_blue", "fish_blue.png"},
		{"fish_green", "fish_green.png"},
		{"fish_red", "fish_red.png"},
		{"crab_pink", "crab_pink.png"},
    };
    
    int size = sizeof(sprites) / sizeof(Sprite);
    bool success = true;
    YSpriteSheetManager::kError result;
    
    for (int i = 0; i < size; ++i)
    {
        std::string key = sprites[i].key;
        std::string value = YFileSystem::getCurrentDir() + "\\" + sprites[i].value;
        
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

    if (loadResources(spriteManager) != YSpriteSheetManager::NONE)
    {
    	printf("Error on loading resources!\n");
    	
    	return 1;
    }

	/** creates penguin **/
	Penguin* penguin = new Penguin(spriteManager->findByName("penguin"),
								   160.0,
								   -10.0,
								   YFrame(0, 0, 8, 10, 10, 5));
	penguin->firstFrame(0);
	penguin->lastFrame(3);

    /** creates fishes **/
    std::vector<Fish*> fishes;
    
    for (int i = 0; i < 5; ++i)
    {
		Fish *fish = NULL;

		fish = new Fish(spriteManager->findByName("fish_blue"),
                            100.0,
                            100.0,
                            YFrame(0, 0, 2, 10, 10, 15));
        
        if (fish != NULL)
        {
        	fish->pause(false);
            fishes.push_back(fish);
        }
    }
    
	float gravity = 15.0;
	float ground = 410;
	SDL_Rect islandRect;

	islandRect.x = 100;
	islandRect.y = ground;
	islandRect.w = 270;
	islandRect.h = 70;

	/** creates crab **/
	Crab* crab = new Crab(spriteManager->findByName("crab_pink"),
						  50.0,
						  ground,
						  YFrame(0, 0, 2, 10, 11, 8),
						  ground);
	crab->pause(false);
	crab->visible(false);

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
				crab->start(islandRect);
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
			crab->update();
		}		
    };
    
    YMain::FunctionRender render = [&](SDL_Renderer* a_renderer)
    {
		SDL_RenderCopy(a_renderer,
					   spriteManager->findByName("background"),
					   NULL,
					   NULL);
        
        /** draw penguin **/
        SDL_Rect nextFrameRect = penguin->nextFrame();
        SDL_Rect dstRect = penguin->rect(4);
        SDL_RenderCopy(a_renderer,
                       penguin->texture(),
                       &nextFrameRect,
                       &dstRect);

        /** draw fish **/
        Fish* fish = fishes.at(0);
        
        if (fish != NULL)
        {
            SDL_Rect nextFishFrameRect = fish->nextFrame();
            SDL_Rect dstFishRect = fish->rect(3);
            SDL_RenderCopy(a_renderer,
                           fish->texture(),
                           &nextFishFrameRect,
                           &dstFishRect);
        }

		/** draw crab **/
        nextFrameRect = crab->nextFrame();
        dstRect = crab->rect(3);
        SDL_RenderCopy(a_renderer,
                       crab->texture(),
                       &nextFrameRect,
                       &dstRect);
    };
    
    game->start(&update,
                &render,
                25,
                5);
    
    /** dealloc resources **/
    for (Fish* fish: fishes)
    {
        if (fish != NULL)
        {
            delete fish;
        }
    }
    
    delete game;
    
	return 0;
}
