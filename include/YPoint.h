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