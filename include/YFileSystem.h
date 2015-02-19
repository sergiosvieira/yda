#ifndef __YFILE_SYSTEM__
#define __YFILE_SYSTEM__

/** YDA **/
#include "YSTL.h"

/** C++ **/
#include <string>

/** STL **/
#include <vector>

class YFileSystem
{
public:
    //! Default errors
	typedef enum
	{
		NONE,
		GET_CURRENT_DIR_ERROR
	} Error;
    //! Getting current directory
    /*!
      \param Error*
    */
	static std::string currentDir(Error* a_error = nullptr);
    //! Create full path string based on subdirectories and file name
    /*!
      \param std::vector<const char*>&& - Subdirectories
      \param const char* - File name
    */
    static std::string fullPathName(VectorConstChar&& a_subdirectories,
                                    const char* a_filename);
    static const char* kSeparator;
};

#endif /** __YFILE_SYSTEM__ **/