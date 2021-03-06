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
      \param std::string& - Result dir
      \param Error*
    */
	static void currentDir(std::string& a_dir,
                         Error* a_error = nullptr);
    //! Create full path string based on subdirectories and file name
    /*!
      \param std::string& - Result full path
      \param std::vector<const char*>& - Subdirectories
      \param const char* - File name
    */
    static void fullPathName(std::string& a_fullPath,
                             VectorConstChar&& a_subdirectories,
                             const std::string& a_filename);
    static const std::string kSeparator;
private:
    static void updateError(Error* a_error, Error a_errorValue);
};

#endif /** __YFILE_SYSTEM__ **/

/** @}*/
