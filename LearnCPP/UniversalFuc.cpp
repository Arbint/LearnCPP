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

double CelsiusToFahrenHeight(double CelsiusDegree)
{

	return 9.0 / 5 * CelsiusDegree + 32;
}

char getCharFromInt(int inInt)
{
	if (inInt >= 0 && inInt < 256)
	{
		char outChar = inInt;
		return outChar;
	}
	else
	{
		std::cout << "error, out of range, returning the last one" << std::endl;
		return 127;
	}
}

int getIntFromChar(char inChar)
{
	int outInt = inChar;
	return outInt;
}

void insertLine(int lineAmount /*= 1*/)
{
	for (int i = 0; i < lineAmount; ++i)
	{
		std::cout << '\n';
	}
}

void replaceWord(std::string& StringToAlter, std::vector<string>& WordsToReplace, std::string wordToReplaceWith)
{
	for (auto iter : WordsToReplace)
	{
		while (StringToAlter.find(iter) != std::string::npos)
		{
			std::size_t FrontLeakEndIndex = StringToAlter.find(iter) - 1;
			std::size_t  BackLeakStartIndex = FrontLeakEndIndex + iter.size() + 1;
			std::size_t  BackleakEndIndex = StringToAlter.size() - 1;
			std::string FrontLeak = "";
			std::string BackLeak = "";
			if (FrontLeakEndIndex >= 0)
			{
				for (int i = 0; i <= (int)FrontLeakEndIndex; ++i)
				{
					FrontLeak += StringToAlter[i];
				}
			}
			if (BackleakEndIndex - BackLeakStartIndex >= 0)
			{
				for (int i = (int)BackLeakStartIndex; i <= (int)BackleakEndIndex; ++i)
				{
					BackLeak += StringToAlter[i];
				}
			}
			StringToAlter = FrontLeak + wordToReplaceWith + BackLeak;
		}
	}
}

void flushAndResetBuffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool isSingleDigit(double testedNumber)
{
	int intyfi = static_cast<int>(testedNumber) ;
	double doublefi = intyfi;
	if (testedNumber == doublefi && testedNumber < 10 && testedNumber > -10)
	{
		return true;
	}
	return false;
}

int getBiggestInt()
{
	
	int biggestNumberSoFar = 2;
	for (int i = 1; biggestNumberSoFar > 0; ++i)
	{
		biggestNumberSoFar = static_cast<int>(pow(2, i));
	}
	return biggestNumberSoFar - 1;
}

int getSmallestInt()
{
	return getBiggestInt() + 1;
}

int getANumberBasedOnCurentTime()
{
	std::time_t time = std::time(0);
	return static_cast<int>(time);
}

std::tm getCurrentTime()
{
	//create a struct of type tm.
	std::tm currentTime;

	//get the raw time from the system, time in seconds since 1900
	std::time_t rawTime = std::time(0);

	//transfer the time in rawTime to currentTime
	localtime_s(&currentTime, &rawTime);

	return currentTime;
}

void printTime(std::tm timeToPrint, std::string info)
{
	std::cout << info << std::endl;
	std::cout << timeToPrint.tm_year + 1900 << "/"
		<< timeToPrint.tm_mon + 1 << "/"
		<< timeToPrint.tm_mday
		<< " " << timeToPrint.tm_hour
		<< ":" << timeToPrint.tm_min
		<< ":" << timeToPrint.tm_sec
		<< std::endl;
}


