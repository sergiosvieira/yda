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

#ifndef __YPOINT__
#define __YPOINT__

#include "YVector.h"

/*!
  A point is a abstract concept used in games to represents a game object positioning
*/
template <class T>
class YPoint
{
public:
	//!	Constructor with two arguments
    YPoint(T a_x,
           T a_y,
           T a_z):
		   m_x(a_x),
           m_y(a_y),
           m_z(a_z){};
    //!	Constructor with two arguments
    YPoint(T a_x,
           T a_y):
           m_x(a_x),
           m_y(a_y),
           m_z(0){};
    //! Point component
	/*!
	  \return x component of the point
	*/
    T x() const
    {
        return m_x;
    }
	//! Point component
	/*!
	  \return y component of the point
	*/
    T y() const
    {
        return m_y;
    }
    //! Point component
    /*!
      \return z component of the point
    */
    T z() const
    {
        return m_z;
    }
    //! Setting x component
    /*!
      \param T
    */
    void x(T a_x)
    {
        m_x = a_x;
    }
    //! Setting y component
    /*!
     \param T
     */
    void y(T a_y)
    {
        m_y = a_y;
    }
    //! Setting z component
    /*!
     \param T
     */
    void z(T a_z)
    {
        m_z = a_z;
    }
    //! Creates a new point added to a vector using operator overriding
	/*!
	  \return a new YPoint
	*/
    YPoint<T> add(YVector& a_vector) const
    {
        return YPoint<T>(m_x + (T)a_vector.x(),
                         m_y + (T)a_vector.y(),
                         m_z + (T)a_vector.z());

    }
protected:
    T m_x; //! x component of the point
    T m_y; //! y component of the pont
    T m_z; //! z component of the point
};

#endif /** __YPOINT__ **/

/** @}*/
