#include <iostream>
#include <cmath>
#include "TComplex.h"
#include "AComplex.h"
using std::cout;
using std::endl;

int TComplex::freeId = 0;

TComplex::TComplex(const double r, const double arg)
	: _id(++freeId), _r(r), _arg(arg)
{
#ifndef NDEBUG
	cout << "--TComplex" << *this << " was created." << endl;
#endif // !NDEBUG

	return;
}

TComplex::TComplex(const TComplex& c)
	: _id(++freeId), _r(c.r()), _arg(c.arg())
{
#ifndef NDEBUG
	cout << "--TComplex" << *this << " was copied." << endl;
#endif // !NDEBUG

	return;
}

TComplex::operator AComplex() const
{
#ifndef NDEBUG
	cout << "--TComplex " << *this << " was converted to AComplex. CONSTRUCTION AFTER CONVERSION:" << endl;
#endif // !NDEBUG
	return AComplex(re(), im());
}

TComplex& TComplex::operator=(const AComplex& c)&
{
	r() = c.abs();
	arg() = c.arg();
	return *this;
}

TComplex& TComplex::operator+=(const TComplex& c)
{
	return *this = AComplex(*this) += c;
}

TComplex& TComplex::operator-=(const TComplex& c)
{
	return *this = AComplex(*this) -= c;
}

ostream& operator<<(ostream& o, const TComplex& c)
{
	return o << '{' << c.r() << ", " << c.arg() << '}' << '[' << "id" << c.id() << ']';
}