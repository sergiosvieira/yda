#ifndef __YRECT__
#define __YRECT__

#include "YPoint.h"
#include "YSize.h"

typedef struct YRect
{
    YPoint position;
    YSize size;
    YRect(const YPoint& a_position,
          const YSize& a_size):
          position(a_position),
          size(a_size)
    {}
    float top() const
    {
        return position.x();
    }
    float left() const
    {
        return position.y();
    }
    float bottom() const
    {
        return top() + (float)size.height;
    }
    float right() const
    {
        return left() + (float)size.width;
    }
} YRect;

#endif /** __YRECT__ **/
