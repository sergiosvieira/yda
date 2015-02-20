/** \addtogroup YDA
 *  @{
 */

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

#ifndef __YVECTOR__
#define __YVECTOR__
//! A vector class.
/*!
  A vector is an important abstract concept used in games. Its can be used to compound object movement and other stuffs.
*/

class YVector
{
public:
    //! Vector constructor two with arguments
    YVector(float a_x,
            float a_y):
    m_x(a_x),
    m_y(a_y),
    m_z(0.f){};
	//! Vector constructor three with arguments
	YVector(float a_x,
		    float a_y,
            float a_z):
			m_x(a_x),
			m_y(a_y),
            m_z(a_z){};
	//! Vector constructor without arguments
	YVector():
			m_x(0.f),
			m_y(0.f),
            m_z(0.f){};
	//! Vector: + operator override
	YVector operator+(const YVector& a_vector) const;
	//! Vector: - operator override
	YVector operator-(const YVector& a_vector) const;
	//! Scalar: * operator override
	YVector operator*(float a_value) const;
	//! Scalar: / operator override
	YVector operator/(float a_value) const;
	//! The length of the vector could be used to compare distance between game objects
	/*!
	  \return the length of the vector
	*/
	int length() const;
	//! The square length of the vector could be used to compare distance between game objects (optimized way)
	/*!
	  \return the square length of the vector
	*/
	int lengthSqrt() const;
	//! Related to the vector components
	/*!
	  \return the x component of the vector
	*/
	float x() const;
	/*!
	  \return the y component of the vector
	*/
	float y() const;
    /*!
      \return the z component of the vector
    */
    float z() const;
protected:
	float m_x; //! x component of the vector
	float m_y; //! y component of the vector
    float m_z; //! z component of the vector
};

#endif /** __YVECTOR__ **/

/** @}*/