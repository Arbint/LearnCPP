#pragma once
#include "UniversialInclude.h"
void writeLetter();

double milesToKilometer(double inMiles);

void MileToKilometerConverter();

void compareValues(int x, int y);

void getNumberAndDecideOddOrEven();

void getLiteralNumAndPrintDigit();

void calculateTwoValues();

void HowMuchMoneyDoYouHave();












//template implementations


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
	for (auto it = VectorToPrint.begin(); it != VectorToPrint.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}
