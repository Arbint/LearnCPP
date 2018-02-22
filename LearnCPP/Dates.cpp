#include "stdafx.h"
#include "Dates.h"


Dates::Dates(int year, Monthes month, int day)
{
	if (!isValid())
	{
		throw invalid("invalid date");
	}
}

Dates::~Dates()
{
}

bool Dates::isValid()
{
	if (year < YearMin || year > YearMax)
	{
		return false;
	}
	return true;
}
