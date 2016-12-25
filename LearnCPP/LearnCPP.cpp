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

	std::vector<int> intNumbers;
	io::getMultiUserInputs<int>("please give me two integers: ", intNumbers, 2);
	printVector(intNumbers);
	if (intNumbers[0] > intNumbers[1])
	{
		io::printWithEndl(intNumbers[0], "The bigger number is: ");
	}
	else
	{
		io::printWithEndl(intNumbers[1], "The bigger number is: ");
	}

	return 0;
}

