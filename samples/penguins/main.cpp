#include "YMain.h"

#include <functional>

int main(int argc, char** argv)
{
    YMain* game = new YMain("Penguins - sergiosvieira@gmail.com",
                            640,
                            480);
    
    std::function<void()> update = []()
    {
    };
    
    std::function<void(SDL_Renderer*)> render = [](SDL_Renderer* a_renderer)
    {
    };
    
    game->start(&update,
                &render,
                25,
                5);
    
    
    delete game;
    
	return 0;
}
