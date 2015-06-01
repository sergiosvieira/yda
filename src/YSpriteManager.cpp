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

#include "YSpriteManager.h"

/** C++ **/
#include <cassert>

/** Initializing constants **/
bool YSpriteManager::m_initialized = false;

YSpriteManager::YSpriteManager(SDL_Renderer& a_renderer): m_renderer(a_renderer)
{
    if (YSpriteManager::m_initialized == false)
    {
        IMG_Init(IMG_INIT_PNG);
        YSpriteManager::m_initialized = true;
    }
}

YSpriteManager::~YSpriteManager()
{
	for (TextureMap::iterator it = m_textures.begin();
		 it != m_textures.end();
		 ++it)
	{
		SDL_Texture *texture = (*it).second;

		if (texture != nullptr)
		{
			SDL_DestroyTexture(texture);
		}
	}

    if (YSpriteManager::m_initialized == true)
    {
        IMG_Quit();
    }
}

YSpriteManager::Error YSpriteManager::add(std::string a_key,
												   	 std::string a_filename)
{
	assert(a_key.size() > 0);
	assert(a_key.size() > 0);

	Error error = NONE;

	TextureMap::iterator it = m_textures.find(a_key);

	if (it == m_textures.end())
	{
        SDL_Texture* texture = YSpriteManager::loadTexture(m_renderer,
                                                                a_filename.c_str(),
                                                                &error);
        
        if (texture != nullptr)
        {
            m_textures[a_key] = texture;
        }
    }

	return error;
}

YSpriteManager::Error YSpriteManager::remove(std::string a_key)
{
	Error result = NONE;
	TextureMap::iterator it = m_textures.find(a_key);

	if (it != m_textures.end())
	{
		SDL_Texture* texture = (*it).second;

		if (texture != nullptr)
		{
			SDL_DestroyTexture(texture);			
			m_textures.erase(it);
		}
	}
	else
	{
		result = TEXTURE_NOT_FOUND;
	}

	return result;
}

SDL_Texture* YSpriteManager::findByName(std::string a_key)
{
	SDL_Texture* result = nullptr;
	TextureMap::iterator it = m_textures.find(a_key);

	if (it != m_textures.end())
	{
		result = (*it).second;
	}

	return result;
}

SDL_Texture* YSpriteManager::loadTexture(SDL_Renderer& a_renderer,
                                          const char* a_filename,
                                          Error* a_error)
{
    SDL_Texture* result = nullptr;

    if (a_filename == nullptr)
    {
        if (a_error != nullptr)
        {
            *a_error = LOADING_ERROR;
        }
    }
    else
    {
        if (YSpriteManager::m_initialized == false)
        {
            YSpriteManager::m_initialized = true;
            IMG_Init(IMG_INIT_PNG);
        }
        

        SDL_Surface* surface = IMG_Load(a_filename);
        
        if (surface == nullptr)
        {
            if (a_error != nullptr)
            {
                *a_error = LOADING_ERROR;
            }
        }
        else
        {
            result = SDL_CreateTextureFromSurface(&a_renderer,
                                                  surface);
            
            if (result == nullptr)
            {
                if (a_error != nullptr)
                {
                    *a_error = CREATING_TEXTURE_ERROR;
                }
            }
        }
    }
    
    return result;
}
