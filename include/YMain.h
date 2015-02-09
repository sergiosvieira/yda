#ifndef __YMAIN__
#define __YMAIN__

/** C++ **/
#include <functional>

/** SDL **/
#include <SDL.h>

class YMain
{
public:
	typedef enum
	{
		NONE,
		CREATING_ERROR,
		RENDERING_ERROR
	} kError;
	YMain(const char* a_title,
		  int a_width,
		  int a_height,
		  kError* a_error = NULL);
	~YMain();
	void start(std::function<void()>* a_update,
               std::function<void(SDL_Renderer*)>* a_render,
               int a_maxFrameRate,
               int a_skipFrames);
protected:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
private:
};

#endif /** __YMAIN__ **/
