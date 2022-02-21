#pragma once
#include<ostream>
using std::ostream;

class AComplex;

class TComplex
{
public:
	class DivisionByZero{};
	TComplex(const double r = 1, const double arg = 0);
	TComplex(const TComplex&);
	~TComplex() {}
	operator AComplex() const;
	TComplex& operator=(const AComplex&) &; //TO OPTIMIZE += AND -=
	inline TComplex& operator=(const TComplex& c) & { r() = c.r(); arg() = c.arg(); return *this;	}
	inline int	   id()  const					    { return _id;									}
	inline double  re()  const						{ return r() * cos(arg());						}
	inline double  im()  const						{ return r() * sin(arg());						}
	inline double  r()	 const						{ return _r;									}
	inline double  arg() const						{ return _arg;									}
	inline double& r()								{ return _r;									}
	inline double& arg()							{ return _arg;								    }
	inline TComplex& operator*=(const TComplex& c)  { r() *= c.r(); arg() += c.arg(); return *this; }
	inline TComplex& operator/=(const TComplex& c) 
	{
		if (c.r() == 0) throw DivisionByZero();
		r() /= c.r(); 
		arg() -= c.arg(); 
		return *this; 
	}
	TComplex& operator+=(const TComplex& c);
	TComplex& operator-=(const TComplex& c);
private:
	double _r, _arg;
	const int _id;
	static int freeId;
};

inline const TComplex operator*(TComplex a, const TComplex& b) { return a *= b; }
inline const TComplex operator/(TComplex a, const TComplex& b) 
{
	if (b.r() == 0) throw TComplex::DivisionByZero();
	return a /= b; 
}

ostream& operator<<(ostream& o, const TComplex& c);