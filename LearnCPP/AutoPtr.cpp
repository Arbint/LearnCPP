#include "stdafx.h"
#include "AutoPtr.h"
#include <iostream>
TestDynamicAllowcatingClass::TestDynamicAllowcatingClass()
{
	std::cout << "Resource Acquired\n";
}

TestDynamicAllowcatingClass::~TestDynamicAllowcatingClass()
{
	std::cout << "Resource Destroyed\n";
}

void TestDynamicAllowcatingClass::print()
{
	std::cout << "Hello!" << std::endl;
}

void DemoRValueReference()
{
	int x = 5;
	int &lref = x;
	int &&rref = 5;
}

Fraction::Fraction(int numerator /*= 0*/, int denominator /*= 1*/)
	:m_numerator(numerator), m_denominator(denominator)
{
	
}

std::ostream& operator<<(std::ostream& out, const Fraction &f1)
{
	out << f1.m_numerator << "/" << f1.m_denominator;
	return out;
}
