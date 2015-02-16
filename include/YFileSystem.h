#ifndef __YFILE_SYSTEM__
#define __YFILE_SYSTEM__

/** C++ **/
#include <string>

class YFileSystem
{
public:
	typedef enum
	{
		NONE,
		GET_CURRENT_DIR_ERROR
	} Error;
	static std::string getCurrentDir(Error* a_error = NULL);
    static const char* kSeparator;
};

#endif /** __YFILE_SYSTEM__ **/