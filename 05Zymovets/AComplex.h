#pragma once
#include <ostream>
using std::ostream;

class TComplex;

class AComplex
{
public:
	AComplex(const double re = 1, const double im = 0);
	AComplex(const AComplex&);
	AComplex(const TComplex&);
	~AComplex() {}
	//operator TComplex() const;
	AComplex& operator= (const TComplex& c)&;
	inline AComplex& operator= (const AComplex& c)& { re() = c.re(); im() = c.im(); return *this; }
	inline double& re()& { return _re; }
	inline double& im()& { return _im; }
	inline double re() const& { return _re; }
	inline double im() const& { return _im; }
	inline int id() const& { return _id; }
	inline AComplex& operator+=(const AComplex& c) { re() += c.re(); im() += c.im(); return *this; }
	inline AComplex& operator-=(const AComplex& c) { re() -= c.re(); im() -= c.im(); return *this; }
	AComplex& operator*=(const AComplex& c);
	AComplex& operator/=(const AComplex& c);
private:
	double _re, _im;
	const int _id;
	static int freeId;
};
//inline AComplex& operator+=(AComplex& t, const AComplex& c) { t.re() += c.re(); t.im() += c.im(); return t; }
//inline AComplex& operator-=(AComplex& t, const AComplex& c) { t.re() -= c.re(); t.im() -= c.im(); return t; }

inline const AComplex operator+(const AComplex& a, const AComplex& b) { return AComplex(a.re() + b.re(), a.im() + b.im()); }
inline const AComplex operator-(const AComplex& a, const AComplex& b) { return AComplex(a.re() - b.re(), a.im() - b.im()); }

ostream& operator<<(ostream&, const AComplex&);