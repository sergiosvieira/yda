#ifndef __YRECT__
#define __YRECT__

#include "YPoint.h"
#include "YSize.h"

template <typename T>
struct YRect
{
    YPoint<T> position;
    YSize<T> size;
    YRect(): position(YPoint<T>(0, 0)),
             size(YSize<T>(0, 0))
    {}

    YRect(const YPoint<T>& a_position,
          const YSize<T>& a_size):
          position(a_position),
          size(a_size)
    {}
    T top() const
    {
        return position.x();
    }
    T left() const
    {
        return position.y();
    }
    T bottom() const
    {
        return top() + size.height;
    }
    T right() const
    {
        return left() + size.width;
    }
};

#endif /** __YRECT__ **/
