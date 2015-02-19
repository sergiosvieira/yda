#ifndef __YSPRITE_SHEET_MANAGER__
#define __YSPRITE_SHEET_MANAGER__

/** C++ **/
#include <string>
#include <map>

/** SDL2 **/
#include <SDL.h>
#include <SDL_image.h>

class YSpriteManager
{
public:
	typedef enum
	{
		NONE,
		LOADING_ERROR,
		CREATING_TEXTURE_ERROR,
		TEXTURE_NOT_FOUND
	} Error;
	YSpriteManager(SDL_Renderer* a_renderer);
	~YSpriteManager();
	Error add(std::string a_key,
			   std::string a_filename);
	Error remove(std::string a_key);
	SDL_Texture* findByName(std::string a_key);
	static SDL_Texture* loadTexture(SDL_Renderer* a_renderer,
									const char* a_filename,
									Error* a_error = nullptr);
private:
	typedef std::map<std::string, SDL_Texture*> TextureMap;
	TextureMap m_textures;
	SDL_Renderer* m_renderer;
    static bool m_initialized;
};

#endif /** __YSPRITE_SHEET_MANAGER__ **/