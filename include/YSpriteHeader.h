/** \addtogroup YDA
 *  @{
 */

#ifndef __YSPRITE_HEADER__
#define __YSPRITE_HEADER__

#include "YSize.h"

/*!
  Store animation frame indexes
*/
typedef struct YFrame
{
	//! Default Constructor
	YFrame(): current(0),
			  first(0),
              last(0),
              size(0, 0)
    {};
	//! Constructor with parameters
	/*!
	  \param Current animation frame index
	  \param First animation frame index
	  \param Last animation frame index
	*/
	YFrame(int a_current,
		   int a_first,
           int a_last,
           const YSize<int>& a_size):
		   current(a_current),
		   first(a_first),
           last(a_last),
           size(a_size)
    {};
	int current; //! Current frame index
	int first; //! First frame index
    int last; //! Last frame index
    YSize<int> size; //! Frame size
} YFrame;

#endif /** __YSPRITE_HEADER__ **/

/** @}*/
