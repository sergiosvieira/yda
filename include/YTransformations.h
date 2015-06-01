#ifndef __YTRANSFORMATIONS__
#define __YTRANSFORMATIONS__

#include "YRect.h"

class YTransformations
{
public:
    static void transformPointBetweenRects(YPoint<int> &a_destinyPoint,
                                           const YPoint<int> &a_sourcePoint,
                                           const YRect<int> &a_sourceRect,
                                           const YRect<int> &a_destinyRect);
    static void translate(YPoint<int>& a_translatedPoint,
                          const YPoint<int>& a_originalPoint,
                          const YPoint<int>& a_increment);
    static void scale(YPoint<int>& a_scaledPoint,
                      const YPoint<int>& a_originalPoint,
                      const YPoint<float>& a_scalarPoint);
    static void rotate(YPoint<int>& a_rotatedPoint,
                       const YPoint<int>& a_originalPoint,
                       float a_degree);
};

#endif /** __YTRANSFORMATIONS__ **/
