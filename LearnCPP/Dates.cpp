#include "stdafx.h"
#include "Dates.h"


Dates::Dates(int inYear, Monthes inMonth, int inDay):year(inYear), month(inMonth), day(inDay)
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
	if (day == DaysInMonth)
	{
		addMonth();
		day = 1;
	}
	else
	{
		++day;
	}
}

void Dates::addDay(int daysToAdd)
{
	for (int i = 0; i < daysToAdd; ++i)
	{
		addDay();
	}
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

void Dates::addMonth(int MonthToAdd)
{
	for (int i = 0; i < MonthToAdd; ++i)
	{
		addMonth();
	}
}
void Dates::addYear(int YearsToAdd)
{
	for (int i = 0; i < YearsToAdd; ++i)
	{
		addYear();
	}
}

void Dates::addYear()
{
	++year;
}

int Dates::GetMonthAsNum()
{
	return static_cast<int>(month);
}

std::string Dates::GetMonthAsString()
{
	return std::to_string(GetMonthAsNum());
}

bool Dates::isValid()
{
	if (year < YearMin || year > YearMax)
	{
		return false;
	}else if (day > getMonthDayAmount()|| day < 1)
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

std::ostream& operator<<(std::ostream& os, Dates& inDate)
{
	string day = intToString(inDate.getDay());
	string month = intToString(inDate.GetMonthAsNum());
	string year = intToString(inDate.getYear());
	string dateString = month + "/" + day + "/" + year;
	os << dateString;
	return os;
}