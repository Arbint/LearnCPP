#pragma once
#include <string>
class FactoryMethodClass
{
public:
	void Print();
	void Set(std::string name, int age);
public:
	FactoryMethodClass();
	FactoryMethodClass(std::string name, int age);
	~FactoryMethodClass();
	static FactoryMethodClass* GetInstance();
private:
	std::string _m_Name;
	int _m_age;
};

