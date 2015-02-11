#include "YPoint.h"

YPoint YPoint::operator+(YVector& a_vector) const
{
	return YPoint(m_x + a_vector.x(), m_y + a_vector.y());
}

float YPoint::x() const
{
	return m_x;
}

float YPoint::y() const
{
	return m_y;
}