#include "stdafx.h"
#include "UniversalFuc.h"

int io::printWithEndl(int thingToPrint)
{
	std::cout << thingToPrint << std::endl;
	return thingToPrint;
}

bool io::isBufferClean()
{
	if ((std::cin.rdbuf()->in_avail() - 1) == 0)
	{
		return true;
	}
	return false;
}

std::string io::printWithEndl(std::string thingToPrint)
{
	std::cout << thingToPrint << std::endl;
	return thingToPrint;
}

void AddNewLineToString(std::string& stringToAlter, std::string stringToAdd/*=" "*/)
{
	stringToAlter += "\n";
	if (stringToAdd != " ")
	{
		stringToAlter += stringToAdd;
	}
}

void AddNewLinesToString(std::string & stringToAlter, int numberOfNewLines)
{
	for (int i = 1; i <= numberOfNewLines; ++i)
	{
		stringToAlter += '\n';
	}
}

bool isIntOdd(int inInt)
{
	if (inInt%2 == 1)
	{
		return true;
	}
	return false;
}
