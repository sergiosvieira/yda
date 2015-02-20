/****************************************************************************
 Copyright (c) 2015 Sérgio Vieira - sergiosvieira@gmail.com
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "YVector.h"

/** C++ **/
#include <cmath>

YVector YVector::operator+(const YVector& a_vector) const
{
	return YVector(m_x + a_vector.m_x, 
				   m_y + a_vector.m_y,
                   m_z + a_vector.m_z);
}

YVector YVector::operator-(const YVector& a_vector) const
{
	return YVector(m_x - a_vector.m_x, 
				   m_y - a_vector.m_y,
                   m_z - a_vector.m_z);
}

YVector YVector::operator*(float a_value) const
{
	return YVector(m_x * a_value,
				   m_y * a_value,
                   m_z * a_value);
}

YVector YVector::operator/(float a_value) const
{
	return YVector(m_x / a_value,
				   m_y / a_value,
                   m_z / a_value);
}

int YVector::length() const
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

int YVector::lengthSqrt() const
{
	return m_x * m_x + m_y * m_y + m_z * m_z;
}

float YVector::x() const
{
	return m_x;
}

float YVector::y() const
{
	return m_y;
}

float YVector::z() const
{
    return m_z;
}