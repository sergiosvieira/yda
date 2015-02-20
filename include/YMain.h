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
