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
    } Error;
    typedef std::function<void(SDL_Event*, float)> FunctionUpdate;
    typedef std::function<void(SDL_Renderer*)> FunctionRender;
    YMain(const char* a_title,
          int a_width,
          int a_height,
          Error* a_error = nullptr);
    ~YMain();
    void start(FunctionUpdate* a_update,
               FunctionRender* a_render,
               int a_maxFrameRate,
               int a_skipFrames);
    SDL_Renderer* renderer();
protected:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
private:
};

#endif /** __YMAIN__ **/
