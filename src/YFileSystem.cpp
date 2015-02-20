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

#include "YFileSystem.h"

/** 
	StackOverflow 
	=============
	- http://stackoverflow.com/questions/143174/how-do-i-get-the-directory-that-a-program-is-running-from 
**/

#include <stdio.h>  /* defines FILENAME_MAX */

#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

/** YDA **/
#include "YSTL.h"

/** C++ **/
#include <sstream>

const char* YFileSystem::kSeparator =
#ifdef _WIN32
    "\\";
#else
    "/";
#endif

std::string YFileSystem::currentDir(Error* a_error)
{
    char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
    	if (a_error != nullptr)
    	{
    		*a_error = GET_CURRENT_DIR_ERROR;
    	}
    }

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	return std::string(cCurrentPath);
}

std::string YFileSystem::fullPathName(VectorConstChar&& a_subdirectories,
                                      const char* a_filename)
{
    Error error = NONE;
    std::stringstream ss;
    std::string cDir = currentDir(&error);
    
    if (error == NONE)
    {
        ss << cDir;
        
        for (const char* sub: a_subdirectories)
        {
            ss << kSeparator;
            ss << sub;
        }
        
        ss << kSeparator << a_filename;
    }
    
    return ss.str();
}