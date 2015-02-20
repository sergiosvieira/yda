#ifndef __YMAIN__
#define __YMAIN__

/** C++ **/
#include <functional>

/** SDL **/
#include <SDL.h>

/** Forwarding **/
class YObjectManager;

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
          YObjectManager* a_objectManager,
          Error* a_error = nullptr);
    ~YMain();
    void start(int a_maxFrameRate = 25,
               int a_skipFrames = 5);
    SDL_Renderer* SDLRenderer();
protected:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    YObjectManager* m_objectManager;
private:
};

#endif /** __YMAIN__ **/
