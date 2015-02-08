#include "YSpriteSheetManager.h"

/** C++ **/
#include <cassert>


YSpriteSheetManager::YSpriteSheetManager(SDL_Renderer* a_renderer)
{
	assert(a_renderer != NULL);

	IMG_Init(IMG_INIT_PNG);
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

	IMG_Quit();
}

YSpriteSheetManager::kError YSpriteSheetManager::add(std::string a_key,
												   	 std::string a_filename)
{
	assert(a_key.size() > 0);
	assert(a_key.size() > 0);

	kError result = NONE;

	TextureMap::iterator it = m_textures.find(a_key);

	if (it == m_textures.end())
	{
		SDL_Surface* surface = IMG_Load(a_filename.c_str());

		if (surface == NULL)
		{
			result = LOADING_ERROR;			
		}
		else
		{
			SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer,
																surface);

			if (texture == NULL)
			{
				result = CREATING_TEXTURE_ERROR;
			}
			else
			{
				m_textures[a_key] = texture;
			}
		}
	}

	return result;
}

YSpriteSheetManager::kError YSpriteSheetManager::remove(std::string a_key)
{
	kError result = NONE;
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