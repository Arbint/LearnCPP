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
	std::string gaga = "gaga";
	int x;
	std::cin >> x;
	char xToChar = x;
	
	gaga += x;
	io::printWithEndl(xToChar);
	io::printWithEndl(gaga);
	io::printWithEndl("wht");
	return 0;
}

