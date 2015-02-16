#ifndef __YANIMATED__
#define __YANIMATED__

/*!
  Store animation frame indexes
*/
typedef struct YFrame
{
	//! Default Constructor
	YFrame(): current(0),
			  first(0),
			  last(0){};
	//! Constructor with parameters
	/*!
	  \param Current animation frame index
	  \param First animation frame index
	  \param Last animation frame index
	*/
	YFrame(int a_current,
		   int a_first,
		   int a_last):
		   current(a_current),
		   first(a_first),
		   last(a_last){};
	int current; //! Current frame index
	int first; //! First frame index
	int last; //! Last frame index		   
} YFrame;

#endif /** __YANIMATED__ **/