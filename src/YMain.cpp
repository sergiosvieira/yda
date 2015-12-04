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

#include "YMain.h"

/** C++ **/
#include <cassert>

/** YDA **/
#include "YObjectManager.cpp"

/** SDL2 **/
#include <SDL_image.h>

/** Initializing Variables **/
YRect<int> YMain::m_world = {};
YRect<int> YMain::m_window = {};
YRect<int> YMain::m_viewport = {};


YRect<int> YMain::world()
{
    return m_world;
}

YRect<int> YMain::window()
{
    return m_window;
}

YRect<int> YMain::viewport()
{
    return m_viewport;
}

void YMain::updateError(Error* a_error, Error a_errorValue)
{
    if (a_error != nullptr)
    {
        *a_error = a_errorValue;
    }
}

YMain::YMain(const char* a_title,
             const YSize<int> &a_size,
             YObjectManager& a_objectManager,
             Error* a_error): m_objectManager(a_objectManager),
                              m_size(a_size)
{
    YMain::m_world = YRect<int>(YPoint<int>(0, 0), YSize<int>(1024, 768));
    YMain::m_window = m_world;
    YMain::m_viewport = YRect<int>(YPoint<int>(0, 0), a_size);
    m_texture = nullptr;
	SDL_Init(SDL_INIT_VIDEO);
    m_sdlWindow = SDL_CreateWindow(a_title,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   m_size.width,
                                   m_size.height,
                                   0);
    if (m_sdlWindow == nullptr)
	{
        updateError(a_error, CREATING_ERROR);
	}
	else
	{
        m_renderer = SDL_CreateRenderer(m_sdlWindow, -1, 0);
    	if (m_renderer == nullptr)
    	{
            updateError(a_error, RENDERING_ERROR);
    	}
	}
}

YMain::~YMain()
{
    SDL_DestroyWindow(m_sdlWindow);
	SDL_Quit();
}

void YMain::start(int a_maxFrameRate,
                  int a_skipFrames)
{
    const int SKIP_TICKS = 1000.f / (float)a_maxFrameRate;
    bool quit = false;
    int loops;
    SDL_Event event;
    Uint32 next_game_tick = SDL_GetTicks();
    float interpolation = 0.f;
    FunctionUpdate* updater = m_objectManager.updater();
    FunctionRender* renderer = m_objectManager.renderer();
    SDL_Rect srcRect =
    {
        m_viewport.left(),
        m_viewport.top(),
        m_viewport.size.width,
        m_viewport.size.height
    };
    SDL_Rect dstRect =
    {
        m_window.left(),
        m_window.top(),
        m_window.size.width,
        m_window.size.height
    };
    SDL_Texture* offscreen = SDL_CreateTexture(m_renderer,
                                               SDL_PIXELFORMAT_ARGB8888,
                                               SDL_TEXTUREACCESS_TARGET,
                                               m_viewport.size.width,
                                               m_viewport.size.height);
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
            (*updater)(&event, interpolation);
            next_game_tick += SKIP_TICKS;
            loops++;
        }
        interpolation = float(SDL_GetTicks() + SKIP_TICKS - next_game_tick)
                        / float( SKIP_TICKS );
        /** render game **/
        bool success = SDL_SetRenderTarget(m_renderer, offscreen) == 0;
        if (m_texture == nullptr)
        {
            SDL_RenderClear(m_renderer);
        }
        else
        {
            SDL_RenderSetViewport(m_renderer, &srcRect);
            SDL_RenderCopy(m_renderer,
                           m_texture,
                           nullptr,
                           nullptr);
        }
        (*renderer)(m_renderer);
        SDL_SetRenderTarget(m_renderer, nullptr);
        SDL_RenderCopy(m_renderer,
                       offscreen,
                       nullptr,
                       &dstRect);
        SDL_RenderPresent(m_renderer);
    }
    SDL_DestroyTexture(offscreen);
}

SDL_Renderer* YMain::SDLRenderer()
{
	return m_renderer;
}

void YMain::textureBackground(SDL_Texture* a_texture)
{
    m_texture = a_texture;
}

int YMain::width() const
{
    return m_size.width;
}

int YMain::height() const
{
    return m_size.height;
}
