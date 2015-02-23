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

//! Main game entry
/*!
  This is the main class used to produce games with YDA Framework. 
  - Firstly, you will needs to create a YObjectManager to store, update and render all
  game obhects.
  - After that, you will creates a YMain object passing game title, window width and 
  height and the created YObjectManager
  - Finally, you will creates a YSpriteSheet object to load all game's images.

  To start the game just use the "start" method on YMain object
*/
class YMain
{
public:
  //! Default Main class errors
    typedef enum
    {
        NONE,
        CREATING_ERROR,
        RENDERING_ERROR
    } Error;
    typedef std::function<void(SDL_Event*, float)> FunctionUpdate;
    typedef std::function<void(SDL_Renderer*)> FunctionRender;
    //! Default Constructor
    /*!
      \param const char* - Window's title
      \param int - Window's width,
      \param int - Window's height
      \param YObjectManager*
      \param Error*
    */
    YMain(const char* a_title,
          int a_width,
          int a_height,
          YObjectManager* a_objectManager,
          Error* a_error = nullptr);
    //! Default desructor
    ~YMain();
    //! Method to starting the game
    /*!
      \param int - Max game frame rate (default value 25)
      \param int - Max game skip frames (default value 5)
    */ 
    void start(int a_maxFrameRate = 25,
               int a_skipFrames = 5);
    /*!
      \return SDL_Renderer*
    */
    SDL_Renderer* SDLRenderer();
    /*!
      \param SDL_Texture* - Bacground texture
    */
    void textureBackground(SDL_Texture* a_texture);
    //! Getting window width
    /*!
      \return int - Window's width
    */
    int width() const;
    //! Getting window height
    /*!
      \return int - Window's height
    */
    int height() const;
protected:
    SDL_Window* m_window;//! Main window
    SDL_Renderer* m_renderer;//! Game renderer
    YObjectManager* m_objectManager;//! Game object manager
    SDL_Texture* m_texture;//! Main window texture
    int m_width; //! Window's width
    int m_height; //! Window's height
private:
};

#endif /** __YMAIN__ **/

/** @}*/