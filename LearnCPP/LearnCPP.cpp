// LearnCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UniversalFuc.h"
#include "UniversialInclude.h"
#include "Drills.h"

int externalVar;
constexpr double pi = 22 / 7;

int main()
{	
	double d = 2.5;
	int i = 2;
	double d2 = d / i; // double/ int = double/(double(int)), so d2 = 1.25 
	int i2 = d / i; // i2 is an int, so if int = double, int = int(double), so i2 = 1
	int i3( d / i ); // error: double -> int conversion may narrow

	d2 = d / i;
	i2 = d / i;

	io::printWithEndl(i);
	io::printWithEndl(i2);
	io::printWithEndl(i3);
	io::printWithEndl(d2);

	//add some converter
	double cdegree = io::GetUerInput<double>("please tell me what is the degree out there in celsius degrees: ");
	double fdegree = CelsiusToFahrenHeight(cdegree);
	io::printWithEndl(fdegree, "SO you mean it is ", " Fahrenheits on the out side");
	io::printWithEndl("I am expecting to see this ");
	io::printWithEndl("So I create a new branch and trying to use it now");
	io::printWithEndl("please make this work");
	int ggag = 11;
	std::string gaga= "I need to see it";
	std::string low = "how low is it?"
	return 0;
}

