#ifndef __YANIMATED__
#define __YANIMATED__

typedef struct YFrame
{
	int current;
	int first;
	int last;
	int width;
	int height;
	int fps;
	YFrame(){};
	YFrame(int a_current,
		   int a_first,
		   int a_last,
		   int a_width,
		   int a_height,
		   int a_fps):
		   current(a_current),
		   first(a_first),
		   last(a_last),
		   width(a_width),
		   height(a_height),
		   fps(a_fps){};
} YFrame;

#endif /** __YANIMATED__ **/