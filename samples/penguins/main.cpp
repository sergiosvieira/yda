#include "YMain.h"

/** YDA **/
#include "YSpriteSheetManager.h"

/** Penguin **/
#include "Penguin.h"

/** C++ **/
#include <functional>
#undef main

int main(int argc, char* argv[])
{	
	/** creates window **/
    YMain* game = new YMain("Penguins - sergiosvieira@gmail.com",
                            640,
                            480);
    
	/** loads resources **/
	YSpriteSheetManager* spriteManager = new YSpriteSheetManager(game->renderer());
	YSpriteSheetManager::kError error = spriteManager->add("background", 
														   "C:\\Users\\sergiosvieira\\Documents\\Projects\\yda\\win-build\\samples\\penguins\\Debug\\scenario.png");

	if (error != YSpriteSheetManager::NONE)
	{
		return 1;
	}
					   
	error = spriteManager->add("penguin",
							  "C:\\Users\\sergiosvieira\\Documents\\Projects\\yda\\win-build\\samples\\penguins\\Debug\\penguin.png");

	if (error != YSpriteSheetManager::NONE)
	{
		return 1;
	}


	/** creates penguin **/
	bool right = true;
	int speed = 2;

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
		SDL_RenderCopy(a_renderer,
					   penguin->texture(),
					   &penguin->nextFrame(),
					   &penguin->rect(4));
    };
    
    game->start(&update,
                &render,
                25,
                5);
    
    
    delete game;
    
	return 0;
}
