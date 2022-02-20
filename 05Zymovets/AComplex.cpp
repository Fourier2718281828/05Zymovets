#include "AComplex.h"
#include "TComplex.h"
#include <cmath>

int AComplex::freeId = 0;

AComplex::AComplex(const double re, const double im)
	: _id(++freeId), _re(re), _im(im)
{
	return;
}

AComplex::AComplex(const AComplex& c)
	: _id(++freeId), _re(c.re()), _im(c.im())
{
	return;
}

AComplex::AComplex(const TComplex& c)
	: _id(++freeId), _re(c.r() * cos(c.arg())), _im(c.r() * sin(c.arg()))
{
	return;
}

//ostream& operator<<(ostream& o, const AComplex& c)
//{
//	return o << '<' << c.re() << ", " << c.im() << '>' << '[' << "id" << c.id() << ']';
//}
