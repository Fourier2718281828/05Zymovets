#include <iostream>
#include "AComplex.h"
#include "TComplex.h"
using std::cout;
using std::endl;

int main(void)
{
	AComplex a(0.707106781187, 0.707106781187);
	a = AComplex(TComplex(a) * TComplex(1, 0.785398163397));
	a = AComplex() + AComplex(0, 1);
	cout << a.re() << ',' << a.im()/*(TComplex(a) *= TComplex(1, 0.785398163397))*/ << endl;
	return 0;
}