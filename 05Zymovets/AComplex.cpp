#include <iostream>
#include <cmath>
#include "AComplex.h"
#include "TComplex.h"
using std::cout;
using std::endl;

int AComplex::freeId = 0;

AComplex::AComplex(const double re, const double im)
	: _id(++freeId), _re(re), _im(im)
{
#ifndef NDEBUG
	cout << "--AComplex" << *this << " was created." << endl;
#endif // !NDEBUG

	return;
}

AComplex::AComplex(const AComplex& c)
	: _id(++freeId), _re(c.re()), _im(c.im())
{
#ifndef NDEBUG
	cout << "--AComplex" << *this << " was copied." << endl;
#endif // !NDEBUG

	return;
}

AComplex::AComplex(const TComplex& c)
	: _id(++freeId), _re(c.r() * cos(c.arg())), _im(c.r() * sin(c.arg()))
{
#ifndef NDEBUG
	cout << "--TComplex" << c << " was converted to AComplex" << *this << endl;
#endif // !NDEBUG

	return;
}

//AComplex::operator TComplex() const
//{
//	return TComplex(sqrt(re() * re() + im() * im()), atan2(im(), re()));
//}

AComplex& AComplex::operator=(const TComplex& c)&
{
	re() = c.r() * cos(c.arg()); 
	im() = c.r() * sin(c.arg()); 
	return *this;
}

AComplex& AComplex::operator*=(const AComplex& c)
{
	return *this = TComplex(*this) *= c;
}

AComplex& AComplex::operator/=(const AComplex& c)
{
	return *this = TComplex(*this) /= c;
}

ostream& operator<<(ostream& o, const AComplex& c)
{
	return o << '<' << c.re() << ", " << c.im() << '>' << '[' << "id" << c.id() << ']';
}