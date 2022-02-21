#include <iostream>
#include <cmath>
#include "TComplex.h"
#include "AComplex.h"
using std::cout;
using std::endl;
//************************************************************
// Реалізувати два варіанти класу комплексних чисел :
//1) AComplex комплексні числа в алгебричній формі;
//
//2) TComplex комплексні числа в тригонометричній формі.
//
//Адитивні операції визначити і реалізувати в алгебричній 
// формі, мультипликативні - в тригонометричній.
//
//Виконати тестування реалізованих класів, відслідковуючи 
//створення об'єктів і перетворення типів зокрема при 
//застосуванні арифметичних операцій до виразів змішаних 
//типів, використовуючи аргументами операцій дійсні числа, 
//комплексні числа в алгебричній  або тригонометричній формі, 
//Developed by Ruslan Zymovets (IPZ, group 1)
//on February 21
//Version 1.0
//************************************************************

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