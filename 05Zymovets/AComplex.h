#pragma once
#include <ostream>
using std::ostream;

class TComplex;

class AComplex
{
public:
	AComplex(const double re = 1, const double im = 0);
	AComplex(const AComplex&);
	~AComplex() {}
	operator TComplex()  const;
	AComplex& operator= (const TComplex& c)&; //TO OPTIMIZE *= and /=
	inline AComplex& operator= (const AComplex& c)& { re() = c.re(); im() = c.im(); return *this;	}
	inline int     id()  const						{ return _id;									}
	inline double  abs() const						{ return sqrt(re() * re() + im() * im());		}
	inline double  arg() const						{ return atan2(im(), re());						}
	inline double  re()  const						{ return _re;									}
	inline double  im()  const						{ return _im;									}
	inline double& re()								{ return _re;									}
	inline double& im()								{ return _im;									}
	inline AComplex& operator+=(const AComplex& c)  { re() += c.re(); im() += c.im(); return *this; }
	inline AComplex& operator-=(const AComplex& c)  { re() -= c.re(); im() -= c.im(); return *this; }
	AComplex& operator*=(const AComplex& c);
	AComplex& operator/=(const AComplex& c);
private:
	double _re, _im;
	const int _id;
	static int freeId;
};

inline const AComplex operator+(AComplex a, const AComplex& b) { return a += b; }
inline const AComplex operator-(AComplex a, const AComplex& b) { return a -= b; }

ostream& operator<<(ostream&, const AComplex&);