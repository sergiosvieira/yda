#include "YSpriteManager.h"

/** C++ **/
#include <cassert>

/** Initializing constants **/
bool YSpriteManager::m_initialized = false;

YSpriteManager::YSpriteManager(SDL_Renderer* a_renderer)
{
	assert(a_renderer != nullptr);

    if (YSpriteManager::m_initialized == false)
    {
        IMG_Init(IMG_INIT_PNG);
        YSpriteManager::m_initialized = true;
    }
    
	m_renderer = a_renderer ;
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

SDL_Texture* YSpriteManager::loadTexture(SDL_Renderer* a_renderer,
                                              const char* a_filename,
                                              Error* a_error)
{
    SDL_Texture* result = nullptr;

    if (a_renderer == nullptr ||
        a_filename == nullptr)
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
            result = SDL_CreateTextureFromSurface(a_renderer,
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