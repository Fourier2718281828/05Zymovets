#pragma once
class AComplex;

class TComplex
{
public:
	class DivisionByZero{};
	TComplex(const double r = 1, const double arg = 0);
	TComplex(const TComplex&);
	TComplex(const AComplex&);
	inline TComplex& operator=(const TComplex& c)& { r() = c.r(); arg() = c.arg(); return *this; }
	inline double& r()& { return _r; }
	inline double& arg()& { return _arg; }
	inline double r() const& { return _r; }
	inline double arg() const& { return _arg; }
	inline int id() const& { return _id; }
	inline TComplex& operator*=(const TComplex& c) { r() *= c.r(); arg() += arg(); return *this; }
	inline TComplex& operator/=(const TComplex& c) 
	{
		if (c.r() == 0) throw DivisionByZero();
		r() /= c.r(); 
		arg() -= arg(); 
		return *this; 
	}
private:
	double _r, _arg;
	const int _id;
	static int freeId;
};

inline const TComplex operator*(TComplex a, const TComplex& b) { return a *= b; }
inline const TComplex operator/(TComplex a, const TComplex& b) { return a /= b; }

//ostream& operator<<(ostream& o, const TComplex& c);