#pragma once
#include <ostream>
using std::ostream;
class TComplex;

class AComplex
{
public:
	class DivisionByZero {};
	AComplex(const double re = 1, const double im = 0);
	AComplex(const AComplex&);
	AComplex(const TComplex&);
	inline AComplex& operator= (const AComplex& c)& { _re = c.re(); _im = c.im(); return *this; }
	inline double& re()& { return _re; }
	inline double& im()& { return _im; }
	inline double re() const& { return _re; }
	inline double im() const& { return _im; }
	inline int id() const& { return _id; }
	inline AComplex& operator+=(const AComplex& c) { re() += c.re(); im() += im(); return *this; }
	inline AComplex& operator-=(const AComplex& c) { re() -= c.re(); im() -= im(); return *this; }
	//inline AComplex& operator*=(const AComplex& c) { return *this = AComplex(TComplex(*this) *= TComplex(c)); }
	//inline AComplex& operator/=(const AComplex& c) { return *this = AComplex(TComplex(*this) /= TComplex(c)); }

private:
	double _re, _im;
	const int _id;
	static int freeId;
};

inline const AComplex operator+(AComplex a, const AComplex& b) { return a += b; }
inline const AComplex operator-(AComplex a, const AComplex& b) { return a -= b; }

//ostream& operator<<(ostream& o, const AComplex& c);