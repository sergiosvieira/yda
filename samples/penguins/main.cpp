#include "YMain.h"

/** YDA **/
#include "YSpriteSheetManager.h"
#include "YPoint.h"
#include "YVector.h"
#include "YFileSystem.h"

/** Penguin **/
#include "Penguin.h"
#include "Fish.h"
#include "Crab.h"
#include "Cloud.h"

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
        {"background", "scenario.png"},
        {"penguin", "penguin.png"},
        {"fish_blue", "fish_blue.png"},
		{"fish_green", "fish_green.png"},
		{"fish_red", "fish_red.png"},
		{"crab_pink", "crab_pink.png"},
        {"scuma", "scuma.png"},
        {"cloud", "cloud.png"}
    };
    
    int size = sizeof(sprites) / sizeof(Sprite);
    bool success = true;
    YSpriteSheetManager::kError result;
    
    std::string kSeparator =
#ifdef _WIN32
    "\\";
#else
    "/";
#endif
    
    for (int i = 0; i < size; ++i)
    {
        std::string key = sprites[i].key;
        std::string value = YFileSystem::getCurrentDir() + kSeparator + sprites[i].value;
        
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
								   YPoint(160.f, -10.f),
								   YFrame(0, 0, 8, 10, 10, 5));
	penguin->firstFrame(0);
	penguin->lastFrame(3);

    /** creates fishes **/
    std::vector<Fish*> fishes;
    
    for (int i = 0; i < 5; ++i)
    {
		Fish *fish = NULL;

		fish = new Fish(spriteManager->findByName("fish_blue"),
						YPoint(0.f, 430.f),
                        YFrame(0, 0, 5, 10, 10, 15));
        
        if (fish != NULL)
        {
        	fish->pause(false);
            fishes.push_back(fish);
        }
    }
    
	YVector gravity(0, 15.0);
	float ground = 410.f;
	SDL_Rect islandRect;

	islandRect.x = 150;
	islandRect.y = ground;
	islandRect.w = 230;
	islandRect.h = 70;

	/** creates crab **/
    SDL_Texture* scuma = spriteManager->findByName("scuma");
	Crab* crab = new Crab(spriteManager->findByName("crab_pink"),
						  YPoint(50.f, ground),
						  YFrame(0, 0, 2, 10, 11, 8),
						  ground,
                          scuma);
	crab->pause(false);
	crab->visible(false);

    /** creates cloud **/
    SDL_Rect screen;
    
    screen.x = 0;
    screen.y = 0;
    screen.w = 640;
    screen.h = 300;
    
    Cloud* cloud = new Cloud(spriteManager->findByName("cloud"),
                             YPoint(-500, 0),
                             screen);
    
    bool falling = true;

    YMain::FunctionUpdate update = [&](SDL_Event* a_event)
    {
        fishes[0]->update();
        cloud->update();
        
		if (falling == true)
		{
			YPoint position = penguin->position().add(gravity);

			if (position.y() < ground)
			{				
				penguin->position(position);
				penguin->currentFrame(8);
				penguin->pause(true);
			}
			else
			{
				YPoint position(penguin->position().x(), ground);

				penguin->position(position);
				crab->start(islandRect);
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

        /** draw cloud **/
        dstRect = cloud->rect();
        SDL_RenderCopy(a_renderer,
                       cloud->texture(),
                       NULL,
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
        nextFrameRect = crab->scuma()->nextFrame();
        dstRect = crab->scuma()->rect(3);
        SDL_RenderCopy(a_renderer,
                       scuma,
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
