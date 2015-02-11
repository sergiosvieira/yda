#ifndef __YVECTOR__
#define __YVECTOR__

class YVector
{
public:
	YVector(float a_x,
		    float a_y):
			m_x(a_x),
			m_y(a_y){};
	YVector():
			m_x(0.f),
			m_y(0.f){};
	YVector operator+(const YVector& a_vector) const;
	YVector operator-(const YVector& a_vector) const;
	YVector operator*(float a_value) const;
	YVector operator/(float a_value) const;
	int length() const;
	int lengthSqrt() const;
	float x();
	float y();
protected:
	float m_x;
	float m_y;
};

#endif /** __YVECTOR__ **/