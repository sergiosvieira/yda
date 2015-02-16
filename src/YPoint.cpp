#include "YPoint.h"

/** YDA **/
#include "YVector.h"


YPoint YPoint::add(YVector& a_vector) const
{
	return YPoint(m_x + a_vector.x(),
                  m_y + a_vector.y(),
                  m_z + a_vector.z());
}

float YPoint::x() const
{
	return m_x;
}

float YPoint::y() const
{
	return m_y;
}

float YPoint::z() const
{
    return m_z;
}