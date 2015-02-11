#include "YPoint.h"

void YPoint::addVector(YVector& a_vector)
{
	m_x += a_vector.x();
	m_y += a_vector.y();
}