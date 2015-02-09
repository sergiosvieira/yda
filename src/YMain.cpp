#include "YMain.h"

/** C++ **/
#include <cassert>

YMain::YMain(const char* a_title,
		  	 int a_width,
		  	 int a_height,
		  	 kError* a_error)
{
	SDL_Init(SDL_INIT_VIDEO);
	m_window = SDL_CreateWindow(a_title,
								SDL_WINDOWPOS_UNDEFINED, 
								SDL_WINDOWPOS_UNDEFINED, 
								a_width,
								a_height, 
								0);
	if (m_window == NULL)
	{
		if (a_error != NULL)
		{
			*a_error = CREATING_ERROR;
		}
	}
	else
	{
    	m_renderer = SDL_CreateRenderer(m_window, 
										-1,
										0);

    	if (m_renderer == NULL)
    	{
    		if (a_error != NULL)
    		{
    			*a_error = RENDERING_ERROR;
    		}
    	}
	}
}

YMain::~YMain()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void YMain::start(FunctionUpdate* a_update,
                  FunctionRender* a_render,
                  int a_maxFrameRate,
                  int a_skipFrames)
{
    const int SKIP_TICKS = 1000 / a_maxFrameRate;
    bool quit = false;
    int loops;
    SDL_Event event;
    Uint32 next_game_tick = SDL_GetTicks();
    float interpolation;
    
    while (!quit)
    {
        SDL_PollEvent(&event);
        
        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }
        
        loops = 0;
        
        while(SDL_GetTicks() > next_game_tick
              && loops < a_skipFrames)
        {
            /** update game **/
            (*a_update)(&event);
            next_game_tick += SKIP_TICKS;
            loops++;
        }
        
        interpolation = float(SDL_GetTicks() + SKIP_TICKS - next_game_tick)
        / float( SKIP_TICKS );
        
        /** render game **/
        SDL_RenderClear(m_renderer);
        (*a_render)(m_renderer);
        SDL_RenderPresent(m_renderer);
    }
}

SDL_Renderer* YMain::renderer()
{
	return m_renderer;
}