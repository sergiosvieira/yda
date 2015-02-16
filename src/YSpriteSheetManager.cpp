#include "YSpriteSheetManager.h"

/** C++ **/
#include <cassert>

/** Initializing constants **/
bool YSpriteSheetManager::m_initialized = false;

YSpriteSheetManager::YSpriteSheetManager(SDL_Renderer* a_renderer)
{
	assert(a_renderer != NULL);

    if (YSpriteSheetManager::m_initialized == false)
    {
        IMG_Init(IMG_INIT_PNG);
        YSpriteSheetManager::m_initialized = true;
    }
    
	m_renderer = a_renderer ;
}

YSpriteSheetManager::~YSpriteSheetManager()
{
	for (TextureMap::iterator it = m_textures.begin();
		 it != m_textures.end();
		 ++it)
	{
		SDL_Texture *texture = (*it).second;

		if (texture != NULL)
		{
			SDL_DestroyTexture(texture);
		}
	}

    if (YSpriteSheetManager::m_initialized == true)
    {
        IMG_Quit();
    }
}

YSpriteSheetManager::Error YSpriteSheetManager::add(std::string a_key,
												   	 std::string a_filename)
{
	assert(a_key.size() > 0);
	assert(a_key.size() > 0);

	Error error = NONE;

	TextureMap::iterator it = m_textures.find(a_key);

	if (it == m_textures.end())
	{
        SDL_Texture* texture = YSpriteSheetManager::loadTexture(m_renderer,
                                                                a_filename.c_str(),
                                                                &error);
        
        if (texture != NULL)
        {
            m_textures[a_key] = texture;
        }
    }

	return error;
}

YSpriteSheetManager::Error YSpriteSheetManager::remove(std::string a_key)
{
	Error result = NONE;
	TextureMap::iterator it = m_textures.find(a_key);

	if (it != m_textures.end())
	{
		SDL_Texture* texture = (*it).second;

		if (texture != NULL)
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

SDL_Texture* YSpriteSheetManager::findByName(std::string a_key)
{
	SDL_Texture* result = NULL;
	TextureMap::iterator it = m_textures.find(a_key);

	if (it != m_textures.end())
	{
		result = (*it).second;
	}

	return result;
}

SDL_Texture* YSpriteSheetManager::loadTexture(SDL_Renderer* a_renderer,
                                              const char* a_filename,
                                              Error* a_error)
{
    SDL_Texture* result = NULL;

    if (a_renderer == NULL ||
        a_filename == NULL)
    {
        if (a_error != NULL)
        {
            *a_error = LOADING_ERROR;
        }
    }
    else
    {
        if (YSpriteSheetManager::m_initialized == false)
        {
            YSpriteSheetManager::m_initialized = true;
            IMG_Init(IMG_INIT_PNG);
        }
        

        SDL_Surface* surface = IMG_Load(a_filename);
        
        if (surface == NULL)
        {
            if (a_error != NULL)
            {
                *a_error = LOADING_ERROR;
            }
        }
        else
        {
            result = SDL_CreateTextureFromSurface(a_renderer,
                                                  surface);
            
            if (result == NULL)
            {
                if (a_error != NULL)
                {
                    *a_error = CREATING_TEXTURE_ERROR;
                }
            }
        }
    }
    
    return result;
}