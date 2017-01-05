#pragma once
#include "UniversialInclude.h"


namespace io {
	template<typename T>
	T GetUerInput(std::string info = "", std::string errorIfWrongType = "You didn't give me what I am asking for..\n Please Try Again:")
	{
		std::cout << info << "\n";
		T input;
		std::cin >> input;
		if (std::cin.fail())
		{
			//clear the input
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			input = GetUerInput<T>(errorIfWrongType);
		}
		return input;
	}

	int printWithEndl(int thingToPrint);

	std::string printWithEndl(std::string thingToPrint);

	template<typename T>
	T printWithEndl(T thingToPrint, std::string preinfo = "", std::string postInfo = "")
	{ 
		std::cout << preinfo << thingToPrint << postInfo << "\n";
		return thingToPrint;
	}

	// get multiple input form user
	//* std::string info - the text to ask for, use "" if you don't need any query
	//* std:vector<T>& outContainer - the container that will eventually be filled with user inputs.
	//* int NumberRequested = -1 - how many do you want to get, if -1 or default value, then read as much as there are in the std::cin
	template<typename T>
	void getMultiUserInputs(std::string info, std::vector<T>& outContainer, int NumberRequested = -1)
	{
		std::cout << info << std::endl;
		std::cout << "(put space between items)" << std::endl;
		T itemOne;
		std::cin >> itemOne;
		outContainer.push_back(itemOne);
		if (NumberRequested <= 0)
		{
			while (!isBufferClean())
			{
				std::cin >> itemOne;
				outContainer.push_back(itemOne);
			}

		}
		else
		{
			for (int iter = 0; iter < NumberRequested - 1; ++iter)
			{
				if (isBufferClean())
				{
					std::cout << "need more input: " << std::endl;
				}
				std::cin >> itemOne;
				outContainer.push_back(itemOne);
			}
		}
	}
	bool isBufferClean();


	template<typename TypeOne, typename TypeTwo>
	void getMultipleImputOfTwoDifferentTypes(std::vector<TypeOne>& VectorOne, std::vector<TypeTwo>& VectorTwo, std::string info, unsigned int numberRequest = 0)
	{
		std::cout << info << std::endl;
		TypeOne TypeOneInput;
		TypeTwo TypeTwoInput;
		if (numberRequest == 0)
		{
			while (!isBufferClean())
			{
				std::cin >> TypeOneInput >> TypeTwoInput;
				while (std::cin.fail())
				{
					std::cout << "You are not typing in the right format,please try again " << std::endl;
					flushAndResetBuffer();
					std::cin >> TypeOneInput >> TypeTwoInput;
				}
				VectorOne.push_back(TypeOneInput);
				VectorTwo.push_back(TypeTwoInput);
			}

		}
		else if (numberRequest > 0)
		{
			for (unsigned int number = 1; number <= numberRequest; ++number)
			{
				std::cin >> TypeOneInput >> TypeTwoInput;
				while (std::cin.fail())
				{
					std::cout << "you are not typing in the right format, please try again " << std::endl;
					flushAndResetBuffer();
					std::cin >> TypeOneInput >> TypeTwoInput;
				}
				VectorOne.push_back(TypeOneInput);
				VectorTwo.push_back(TypeTwoInput);
				if (number == numberRequest)
				{
					break;
				}
				if (isBufferClean())
				{
					std::cout << "more input are needed: " << std::endl;
				}
			}
			flushAndResetBuffer();
		}
	}
}

//add a new line to a string, " " means adding only a new line with no letters. or just 
//leave it as default value if you intend to do so;
void AddNewLineToString(std::string& stringToAlter, std::string stringToAdd = " ");
void AddNewLinesToString(std::string& stringToAlter, int numberOfNewLines = 1);

bool isIntOdd(int inInt);

//template methods
template<typename NumberType, typename ReturnType>
ReturnType calculateValues(NumberType num1, NumberType num2, EMath mathMethod)
{
	switch (mathMethod)
	{
	case EMath::add:
		return num1 + num2;
		break;
	case EMath::subtract:
		return num1 - num2;
		break;
	case EMath::divide:
		return num1 / num2;
		break;
	case EMath::multiply:
		return num1 * num2;
		break;
	case EMath::power:
		return std::pow(num1, num2);
		break;
	case EMath::average:
		return (num1 + num2) / 2;
	default:
		return 0;
		break;
	}
}

double CelsiusToFahrenHeight(double CelsiusDegree);

template<typename T>
void arrangeNumbers(std::vector<T>& numbers)
{
	for (auto iter = numbers.begin(); iter != numbers.end(); ++iter)
	{
		T leftExtreme = *iter;
		for (auto i = iter + 1; i != numbers.end(); ++i)
		{
			if (leftExtreme > *i)
			{
				leftExtreme = *i;
				*i = *iter;
				*iter = leftExtreme;
			}
		}
	}
}

template<typename T>
void printVector(std::vector<T>& VectorToPrint, int bWithSpecificIndexes = false, std::vector<int> indexes = std::vector<int>())
{
	if (!bWithSpecificIndexes)
	{
		for (T iter : VectorToPrint)
		{
			std::cout << iter << " ";
		}
		std::cout << '\n';
		//alternative using iterators.
		if (false)
		{
			for (auto iter = VectorToPrint.begin(); iter != VectorToPrint.end(); ++iter)
			{
				std::cout << *iter << " ";
			}
			std::cout << '\n';
		}
	}
	else
	{
		for (int indexIter : indexes)
		{
			std::cout << VectorToPrint[indexIter] << std::endl;
		}
	}
	
}

template<typename T>
T square(T inRoot)
{
	return inRoot * inRoot;
}

char getCharFromInt(int inInt);
int getIntFromChar(char inChar);

template<typename T>
void sortVector(std::vector<T>& outVector, std::function<bool(T&, T&)> SortFuc = [](T& VarOne, T& VarTwo)->bool {return VarOne < VarTwo; }, std::size_t sortStart = 0, std::size_t sortEnd = 0)
{
	if (sortStart == 0 && sortEnd == 0)
	{
		std::sort(outVector.begin(), outVector.end(), SortFuc);
		return;
	}
	if ( sortStart < 0 || sortStart >= sortEnd || sortEnd > (outVector.size() - 1))
	{
		std::cout << "range are not right, no sort performed" << std::endl;
		return;
	}
	sort(outVector.begin() + sortStart, outVector.begin() + sortEnd, SortFuc);
}

template<typename T>
void sortVectorFromSmallToBig(std::vector<T>& outVector, std::size_t sortStart = 0, std::size_t sortEnd = 0, bool SmallToBig = true)
{
	if (SmallToBig)
	{
		sortVector<T>(outVector, [](T& VarOne, T& VarTwo)->bool {return VarOne < VarTwo; }, sortStart, sortEnd);
	}
	else
	{
		sortVector<T>(outVector, [](T& VarOne, T& VarTwo)->bool {return VarOne > VarTwo; }, sortStart, sortEnd);
	}
}

void insertLine(int lineAmount = 1);

void replaceWord(std::string& StringToAlter, std::vector<string>& WordsToReplace, std::string wordToReplaceWith);

void flushAndResetBuffer();

bool isSingleDigit(double testedNumber);

template<typename T>
std::vector<int> getIndexOfElementValue(std::vector<T> VectorToSerch, T element)
{
	std::vector<int> returnIndexs;
	for (int index = 0; index < VectorToSerch.size(); ++index)
	{
		if (VectorToSerch[index] == element)
		{
			returnIndexs.push_back(index);
		}
	}
	return returnIndexs;
}

//get the biggest number int type can possible hold
int getBiggestInt();
//get the smallest number int type can possible hold
int getSmallestInt();

int getANumberBasedOnCurentTime();


/*get the current time in the type of std::tm, which you can further
On use it's members to get specific part of the time, like year, month etc.
print it use printTime()
*/
std::tm getCurrentTime();

//print the current time, you can get the current time use getCurrentTime()
void printTime(std::tm timeToPrint, std::string info = "The time and date is: ");


//Get current time in seconds since 1900
template<typename T>
T randomNmuberBasedOnCurrentTime(T rangMin, T RangeMax)
{
	int randomSeed = getANumberBasedOnCurentTime();
	std::srand(randomSeed);

	return rangMin + (T)rand() % (RangeMax + 1 - rangMin);
	
}


/*
* Do a count down in seconds
*
* CountDownTime - the length of the count down
*/
void DoCountDown(int CountDownTime);

//check if a number is a prime number
bool IsPrimeNumber(int tryNumber);

/*find all the prime numbers between rangeStart and rangeEnd(include both)
and return a vector of them.
*/
std::vector<int> GetPrimeNumberBetween(int rangeStart, int rangeEnd);
std::vector<int> GetPrimeNumberFromOneTo(int EndNumber);

template<typename T>
void DeleteElementsInVectorHasValue(std::vector<T>& outVector, T& value)
{
	outVector.erase(std::remove(outVector.begin(), outVector.end(), value), outVector.end());
}

template<typename T>
void DeleteElementsInVectorHasValues(std::vector<T>& outVector, std::vector<T>& valuesToDelete)
{
	for (T iter : valuesToDelete)
	{
		DeleteElementsInVectorHasValue(outVector, iter);
	}
}

template<typename T>
bool VectorHasElement(std::vector<T> VectorToCheck, T ElementToCheekFor)
{
	return (std::find(VectorToCheck.begin(), VectorToCheck.end(), ElementToCheekFor) != VectorToCheck.end());
}

std::vector<int> GetTheFirstNPrimes(int n);

std::vector<int> FindMode(std::vector<int> vectorToExam);

using namespace io;
