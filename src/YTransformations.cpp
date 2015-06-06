#include "YTransformations.h"

#include <cmath>

void YTransformations::transformPointBetweenRects(YPoint<int> &a_destinyPoint,
                                                  const YPoint<int> &a_sourcePoint,
                                                  const YRect<int> &a_sourceRect,
                                                  const YRect<int> &a_destinyRect)
{
    float ratioX = ((float)a_sourcePoint.x() - (float)a_sourceRect.left()) / (float)a_sourceRect.size.width;
    float ratioY = -((float)a_sourcePoint.y() - (float)a_sourceRect.top()) / (float)a_sourceRect.size.height;

    a_destinyPoint.x(a_destinyRect.left() + a_destinyRect.size.width * ratioX);
    a_destinyPoint.y(a_destinyRect.top() + a_destinyRect.size.height * ratioY);
}

void YTransformations::translate(YPoint<int> &a_translatedPoint,
                                 const YPoint<int> &a_originalPoint,
                                 const YPoint<int> &a_increment)
{
    a_translatedPoint.x(a_originalPoint.x() + a_increment.x());
    a_translatedPoint.y(a_originalPoint.y() + a_increment.y());
}

void YTransformations::scale(YPoint<int> &a_scaledPoint,
                             const YPoint<int> &a_originalPoint,
                             const YPoint<float> &a_scalarPoint)
{
    a_scaledPoint.x((int)(a_originalPoint.x() * a_scalarPoint.x()));
    a_scaledPoint.y((int)(a_originalPoint.y() * a_scalarPoint.y()));
}

void YTransformations::rotate(YPoint<int> &a_rotatedPoint,
                              const YPoint<int> &a_originalPoint,
                              float a_degree)
{
    float aux = a_degree * 3.14159265 / 180.f;

    a_rotatedPoint.x(cos(aux) * a_originalPoint.x() - sin(aux) * a_originalPoint.y());
    a_rotatedPoint.y(sin(aux) * a_originalPoint.x() + cos(aux) * a_originalPoint.y());
}
