#include "stdafx.h"
#include "FactoryMethodClass.h"
#include <iostream>

void FactoryMethodClass::Print()
{
	std::cout <<"name: " << _m_Name << std::endl;
	std::cout <<"age: "<< _m_age << std::endl;
}

void FactoryMethodClass::Set(std::string name, int age)
{
	_m_age = age;
	_m_Name = name;
}

FactoryMethodClass::FactoryMethodClass()
{
}


FactoryMethodClass::FactoryMethodClass(std::string name, int age)
	:_m_age(age), _m_Name(name)
{

}

FactoryMethodClass::~FactoryMethodClass()
{
}

FactoryMethodClass* FactoryMethodClass::GetInstance()
{
	static FactoryMethodClass* CDO = new FactoryMethodClass();
	return CDO;
}
