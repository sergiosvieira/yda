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

/** Forwarding class **/
class YVector;

/*!
  A point is a abstract concept used in games to represents a game object positioning
*/
class YPoint
{
public:
	//!	Constructor with two arguments
	YPoint(float a_x,
		   float a_y):
		   m_x(a_x),
		   m_y(a_y),
           m_z(0.f){};
    //! Constructor with three arguments
    YPoint(float a_x,
           float a_y,
           float a_z):
           m_x(a_x),
           m_y(a_y),
           m_z(a_z){};
    //! Constructor without arguments
	YPoint(): m_x(0.f),
              m_y(0.f),
              m_z(0.f){};
	//! Point component
	/*!
	  \return x component of the point
	*/
	float x() const;
	//! Point component
	/*!
	  \return y component of the point
	*/
	float y() const;
    //! Point component
    /*!
     \return z component of the point
     */
    float z() const;
    //! Setting x component
    /*!
      \param float
    */
    void x(float x);
    //! Setting x component
    /*!
     \param float
     */
    void y(float x);
    //! Setting x component
    /*!
     \param float
     */
    void z(float x);
	//! Creates a new point added to a vector using operator overriding
	/*!
	  \return a new YPoint
	*/
	YPoint add(YVector& a_vector) const;
protected:
	float m_x; //! x component of the point
	float m_y; //! y component of the pont
    float m_z; //! z component of the point
};

#endif /** __YPOINT__ **/

/** @}*/