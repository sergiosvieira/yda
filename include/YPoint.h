#ifndef __YPOINT__
#define __YPOINT__

/** YDA **/
#include "YVector.h"

/*!
  A point is a abstract concept used in games to represents a game object positioning
*/
class YPoint
{
public:
	//!	Constructor with arguments
	YPoint(float a_x,
		   float a_y):
		   m_x(a_x),
		   m_y(a_y){};
	//! Constructor without arguments
	YPoint():
		   m_x(0.f),
		   m_y(0.f){};
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
	//! Creates a new point added to a vector using operator overriding
	/*!
	  \return a new YPoint
	*/
	YPoint operator+(YVector& a_vector) const;
protected:
	float m_x; //! x component of the point
	float m_y; //! y component of the pont
};

#endif /** __YPOINT__ **/