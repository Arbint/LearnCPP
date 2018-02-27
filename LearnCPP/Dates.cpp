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

int Dates::GetDaysInMonth()
{
	return getMonthDayAmount();
}

void Dates::addDay()
{
	int DaysInMonth = getMonthDayAmount();

}

void Dates::addMonth()
{
	int monthNum = GetMonthNum();
	if (monthNum == 12)
	{
		month = Monthes::Jan;
		addYear();
	}
	else
	{
		int nextMonth = monthNum + 1;
		month = static_cast<Monthes>(nextMonth);
	}
}

void Dates::addYear()
{
	++year;
}

bool Dates::isValid()
{
	if (year < YearMin || year > YearMax)
	{
		return false;
	}
	return true;
}

bool Dates::isLeapYear()
{
	if (year%4 == 0)
	{
		return true;
	}
	return false;
}

int Dates::getMonthDayAmount()
{
	int days = 31;
	switch (month)
	{
	case Monthes::Jan: case Monthes::mar: 
	case Monthes::may: case Monthes::jul: 
	case Monthes::aug: case Monthes::oct:
	case Monthes::dec:
		break;
	case Monthes::feb:
		if (isLeapYear())
		{
			days = 29;
		}
		else
		{
			days = 28;
		}
		break;
	default:
		days = 30;
		break;
	}
	return days;
}

int Dates::GetMonthNum()
{
	int monthNum = static_cast<int>(month);
	return monthNum;
}
