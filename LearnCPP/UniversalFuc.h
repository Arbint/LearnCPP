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
void printVector(std::vector<T>& VectorToPrint)
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

int getBiggestInt();

using namespace io;
