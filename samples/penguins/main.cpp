#include "YMain.h"
#include "YSpriteSheetManager.h"

#include <functional>
#undef main

int main(int argc, char* argv[])
{	
    YMain* game = new YMain("Penguins - sergiosvieira@gmail.com",
                            640,
                            480);
    
	YSpriteSheetManager* spriteManager = new YSpriteSheetManager(game->renderer());

	YSpriteSheetManager::kError error = spriteManager->add("background", 
														   "C:\\Users\\sergiosvieira\\Documents\\Projects\\yda\\win-build\\samples\\penguins\\Debug\\scenario.png");

	if (error != YSpriteSheetManager::NONE)
	{
		return 1;
	}
					   
	error = spriteManager->add("penguin",
							  "C:\\Users\\sergiosvieira\\Documents\\Projects\\yda\\win-build\\samples\\penguins\\Debug\\penguim.png");

	if (error != YSpriteSheetManager::NONE)
	{
		return 1;
	}

    std::function<void()> update = []()
    {
    };
    
    std::function<void(SDL_Renderer*)> render = [&](SDL_Renderer* a_renderer)
    {
		SDL_RenderCopy(a_renderer,
					   spriteManager->findByName("background"),
					   NULL,
					   NULL);
    };
    
    game->start(&update,
                &render,
                25,
                5);
    
    
    delete game;
    
	return 0;
}
