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

void YPoint::x(float a_x)
{
    m_x = a_x;
}

void YPoint::y(float a_y)
{
    m_y = a_y;
}

void YPoint::z(float a_z)
{
    m_z = a_z;
}
