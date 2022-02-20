#include <iostream>
#include "AComplex.h"
#include "TComplex.h"
using std::cout;
using std::endl;

//1. When we do a * b for AComplex, the result is TComplex. Shoud we implement 
//utilities in AComplex that would convert the result to the right type?
//2. What operations should be present?
//3. Should there be 4 operations +=, -=... in each class? Or additive -- in AComplex whereas multiplicative -- in TComplex?

int main(void)
{
	AComplex a1(1, 1), a2(0, 1), a(a1);
	TComplex t1(1, 3.14159), t2(1, 0), t(a1);
	cout << "<> - AComplex, {} - TComplex" << endl;
	cout << "#AComplex" << endl;
	cout << "a1 = " << a1 << endl;
	cout << "a2 = " << a2 << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "a1 + a2 = " << a1 + a2 << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "a1 - a2 = " << a1 - a2 << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "a1 * a2 = " << a1 * a2 << " (TComplex result!)" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "a1 / a2 = " << a1 / a2 << " (TComplex result!)" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "#TComplex" << endl;
	cout << "t1 = " << t1 << endl;
	cout << "t2 = " << t2 << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "t1 + t2 = " << t1 + t2 << " (AComplex result!)" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "t1 - t2 = " << t1 - t2 << " (AComplex result!)" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "t1 * t2 = " << t1 * t2 << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "t1 / t2 = " << t1 / t2 << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "#Both AComplex & TComlex" << endl;
	cout << "a = " << a << endl;
	cout << "t = " << t << endl;
	cout << "a + t = " << a + t << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "t + a = " << t + a << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "a - t = " << a - t << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "t - a = " << t - a << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "a * t = " << a * t << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "t * a = " << t * a << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "a / t = " << a / t << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "t / a = " << t / a << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	return 0;
} 