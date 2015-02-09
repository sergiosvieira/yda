#include "YFileSystem.h"

/** 
	StackOverflow 
	=============
	- http://stackoverflow.com/questions/143174/how-do-i-get-the-directory-that-a-program-is-running-from 
**/

#include <stdio.h>  /* defines FILENAME_MAX */

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

std::string YFileSystem::getCurrentDir(Error* a_error)
{

    
    char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
    	if (a_error != NULL)
    	{
    		*a_error = GET_CURRENT_DIR_ERROR;
    	}
    }

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	return std::string(cCurrentPath);
}