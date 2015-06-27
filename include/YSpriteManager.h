/** \addtogroup YDA
 *  @{
 */

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
 AUTHORS OR COPYRIG
 HT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __YSPRITE_MANAGER__
#define __YSPRITE_MANAGER__

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
    YSpriteManager(SDL_Renderer& a_renderer);
	~YSpriteManager();
	Error add(std::string a_key,
			   std::string a_filename);
	Error remove(std::string a_key);
	SDL_Texture* findByName(std::string a_key);
    static SDL_Texture* loadTexture(SDL_Renderer& a_renderer,
									const char* a_filename,
									Error* a_error = nullptr);
private:
	typedef std::map<std::string, SDL_Texture*> TextureMap;
	TextureMap m_textures;
    SDL_Renderer& m_renderer;
    static bool m_initialized;
    static void updateError(Error* a_error, Error a_errorValue);
};

#endif /** __YSPRITE_MANAGER__ **/

/** @}*/
