#include "YVector.h"

/** C++ **/
#include <cmath>

YVector YVector::operator+(const YVector& a_vector) const
{
	return YVector(m_x + a_vector.m_x, 
				   m_y + a_vector.m_y);
}

YVector YVector::operator-(const YVector& a_vector) const
{
	return YVector(m_x - a_vector.m_x, 
				   m_y - a_vector.m_y);
}

YVector YVector::operator*(float a_value) const
{
	return YVector(m_x * a_value,
				   m_y * a_value);
}

YVector YVector::operator/(float a_value) const
{
	return YVector(m_x / a_value,
				   m_y / a_value);
}

int YVector::length() const
{
	return sqrt(m_x * m_x + m_y * m_y);
}

int YVector::lengthSqrt() const
{
	return m_x * m_x + m_y * m_y;
}

float YVector::x()
{
	return m_x;
}

float YVector::y()
{
	return m_y;
}
