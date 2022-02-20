#include "TComplex.h"
#include "AComplex.h"
#include <cmath>

int TComplex::freeId = 0;

TComplex::TComplex(const double r, const double arg)
	: _id(++freeId), _r(r), _arg(arg)
{
	return;
}

TComplex::TComplex(const TComplex& c)
	: _id(++freeId), _r(c.r()), _arg(c.arg())
{
	return;
}

TComplex::TComplex(const AComplex& c)
	: _id(++freeId), _r(sqrt(c.re()*c.re() + c.im()*c.im())), _arg(atan2(c.re(), c.im()))
{
	return;
}

//ostream& operator<<(ostream& o, const TComplex& c)
//{
//	return o << '{' << c.r() << ", " << c.arg() << '}' << '[' << "id" << c.id() << ']';
//}
