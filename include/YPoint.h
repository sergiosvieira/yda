#ifndef __YPOINT__
#define __YPOINT__

/** YDA **/
#include "YVector.h"

class YPoint
{
public:
	YPoint(float a_x,
		   float a_y):
		   m_x(a_x),
		   m_y(a_y){};
	YPoint():
		   m_x(0.f),
		   m_y(0.f){};
	void addVector(YVector& a_vector);
protected:
	float m_x;
	float m_y;
};

#endif /** __YPOINT__ **/