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