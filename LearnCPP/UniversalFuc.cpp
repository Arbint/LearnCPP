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

void DoCountDown(int CountDownTime)
{
	int CountStartTime = getANumberBasedOnCurentTime();
	int TimeToStop = CountStartTime + CountDownTime;
	
	int loopTime = getANumberBasedOnCurentTime();
	int lastLoopTime = loopTime;
	while ( loopTime - 1 != TimeToStop)
	{
		loopTime = getANumberBasedOnCurentTime();
		if (lastLoopTime != loopTime)
		{
			std::cout << CountDownTime - (loopTime - CountStartTime) + 1 << std::endl;
			lastLoopTime = loopTime;
		}
	}
}

bool IsPrimeNumber(int tryNumber)
{
	if (tryNumber <= 1)
	{
		return false;
	}
	for (int i = 2; i < tryNumber; ++i)
	{
		if (tryNumber%i == 0)
		{
			return false;
		}
	}
	return true;
}

std::vector<int> GetPrimeNumberBetween(int rangeStart, int rangeEnd)
{
	std::vector<int> primeNumbers;
	for (int current = rangeStart; current <= rangeEnd; ++current)
	{
		if (IsPrimeNumber(current))
		{
			primeNumbers.push_back(current);
		}
	}
	return primeNumbers;
}

std::vector<int> GetPrimeNumberFromOneTo(int EndNumber)
{
	//create a vector of number from 2 to endNumber 
	std::vector<int> primeNumbers;
	for (int i = 2; i <= EndNumber; ++i)
	{
		primeNumbers.push_back(i);
	}
	
	//we start from the first
	int DeleteBaseStartIndex = 0;
	
	//try to delete elements that are not prime numbers by using the Sieve of Eratosthenes method
	while (true)
	{
		//record the size of the primeNumbers at the beginning of the loop;
		std::size_t primeVectorSize = primeNumbers.size();
		
		//create a loopNonePrimeNumbers and populate it start from the first number that is a mutiples of the first premie number in the primeNumbers, next loop in this while loop
		//we will do the second;
		std::vector<int> loopNonePrimeNumbers;
		for (int loopbaseNum = primeNumbers[DeleteBaseStartIndex]*2; loopbaseNum <= EndNumber; loopbaseNum += primeNumbers[DeleteBaseStartIndex])
		{
			loopNonePrimeNumbers.push_back(loopbaseNum);
		}
		
		//remove all element in loopNonePrimeNumbers from primeNumbers.
		DeleteElementsInVectorHasValues(primeNumbers, loopNonePrimeNumbers);
		//increment the index so next time we populate the loopNonePrimeNumbers with the second primeNumber in primeNumber and store all it's multiples.
		++DeleteBaseStartIndex;
		
		//if after removal, nothing is removed, then we should have element all the non-prime numbers. break the loop
		if (primeVectorSize == primeNumbers.size())
		{
			break;
		}
	}
	return primeNumbers;
}

std::vector<int> GetTheFirstNPrimes(int n)
{
	std::vector<int> primeNumbers;
	std::size_t numberOfPrimesNeeded = static_cast<std::size_t>(n);
	for (int TryNumber = 2; (primeNumbers.size() != numberOfPrimesNeeded); ++TryNumber)
	{
		if (IsPrimeNumber(TryNumber))
		{
			primeNumbers.push_back(TryNumber);
		}
	}
	return primeNumbers;
}

std::vector<int> FindMode(std::vector<int> vectorToExam)
{

	std::vector<int> modeNumbers{vectorToExam[0]};

	int highestNum = vectorToExam[0];
	int highestNumRepeatation = 1;

	//compare every element with all the element in the vectorToExam
	for (int number : vectorToExam)
	{
		
		//if they are the same, then there is one more repeat, we start from 0 so when it compares to it self, it added one.
		int repeation = 0;
		for (int OtherNumber : vectorToExam)
		{
			if (number == OtherNumber)
			{
				repeation += 1;
			}
		}

		//after finding out how many element in vectotExam has the same value of number. compare it with the highestNumberRepeatation
		
		// if they are the same, then we got one more mode number
		if (repeation == highestNumRepeatation && !VectorHasElement(modeNumbers, number))
		{
			modeNumbers.push_back(number);
		}else if (repeation > highestNumRepeatation)//it the new repeation is bigger, all previous mode should not be mode any more, this one will be the mode.
		{
			modeNumbers.clear();
			modeNumbers.push_back(number);
			highestNumRepeatation = repeation;
		}
	}
	return modeNumbers;
}

