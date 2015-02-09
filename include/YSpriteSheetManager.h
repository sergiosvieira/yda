#ifndef __YSPRITE_SHEET_MANAGER__
#define __YSPRITE_SHEET_MANAGER__

/** C++ **/
#include <string>
#include <map>

/** SDL2 **/
#include <SDL.h>
#include <SDL_image.h>

class YSpriteSheetManager
{
public:
	typedef enum
	{
		NONE,
		LOADING_ERROR,
		CREATING_TEXTURE_ERROR,
		TEXTURE_NOT_FOUND
	} kError;
	YSpriteSheetManager(SDL_Renderer* a_renderer);
	~YSpriteSheetManager();
	kError add(std::string a_key,
			   std::string a_filename);
	kError remove(std::string a_key);
	SDL_Texture* findByName(std::string a_key);
private:
	typedef std::map<std::string, SDL_Texture*> TextureMap;
	TextureMap m_textures;
	SDL_Renderer* m_renderer;
	bool m_loaded;
};

#endif /** __YSPRITE_SHEET_MANAGER__ **/