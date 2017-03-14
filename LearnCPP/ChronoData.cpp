#include "stdafx.h"
#include "ChronoData.h"

DataStructure::ChronoData::ChronoData()
{
	
}

DataStructure::ChronoData::~ChronoData()
{

}

DataStructure::ChronoData::ChronoData(int inYear, Month inMonth, int inDay)
	:year{ inYear }, month{ inMonth }, day{inDay}
{
	if (!isDataValid(year,month,day))
	{
		throw Invalid{};
	}
}

int DataStructure::ChronoData::getDay() const
{
	return day;
}

Month DataStructure::ChronoData::getMonth() const
{
	return month;
}

int DataStructure::ChronoData::getYear() const
{
	return year;
}



void DataStructure::ChronoData::add_day(int daysToAdd)
{

	for (int x = 1; x <= daysToAdd; ++x)
	{
		add_One_day();
	}
}

void DataStructure::ChronoData::add_month(int MonthToAdd)
{
	for (int x = 1; x <= MonthToAdd; ++x)
	{
		add_One_Month();
	}
}

void DataStructure::ChronoData::add_year(int YearToAdd)
{
	if (month == Month::feb && day == 29 && !leapYear(year + YearToAdd))
	{
		month = Month::mar;
		day = 1;
	}
	year += YearToAdd;
}

const DataStructure::ChronoData& DataStructure::ChronoData::staticClass()
{
	static DataStructure::ChronoData data;
	return data;
}

void DataStructure::ChronoData::add_One_day()
{
	int maxDay = 31;
	switch (month)
	{

	case Month::feb:
		maxDay = 28;
		break;

	case Month::apr:
	case Month::jun:
	case Month::sep:
	case Month::nov:
		maxDay = 30;
		break;
	default:
		break;
	}

	if (day + 1 <= maxDay)
	{
		day = day + 1;
	}
	else
	{
		add_month(1);
		day = 1;
	}
}

void DataStructure::ChronoData::add_One_Month()
{
	if (month == Month::dec)
	{
		month = Month::jan;
		add_year(1);
	}
	else
	{
		int nextMonth = int(month) + 1;
		month = Month(nextMonth);
	}
}

bool DataStructure::isDataValid(int year, Month month, int day)
{
	if (day < 0)
	{
		return false;
	}
	if (int(month) < 0 || int(month) > 12)
	{
		return false;
	}
	
	int days_in_month = 31;
	switch (month)
	{
	
	case Month::feb:
		days_in_month = (leapYear(year) ? 29 : 28);
		break;

	case Month::apr: case Month::jun: case Month::sep: case Month::nov:
		days_in_month = 30;
		break;
	default:
		break;
	}

	if (days_in_month < day)
	{
		return false;
	}
	return true;
}



bool DataStructure::leapYear(int y)
{
	return false;
}

std::ostream& DataStructure::operator<<(ostream& os, const ChronoData& inData)
{
	os << inData.getDay() << "/" << int(inData.getMonth()) << "/" << inData.getYear();
	return os;
}

std::istream& DataStructure::operator >> (istream& is, ChronoData& inData)
{
	int y,m,d;
	char char1, char2;
	is >> d >> char1 >> m >> char2 >> y;
	if (char1 != '/' || char2 != '/')
	{
		is.clear(ios_base::failbit);//set the fail bit??
	}
	inData = DataStructure::ChronoData{y,Month(m),d};
	return is;
}

bool DataStructure::operator!=(const ChronoData& lhs, const ChronoData& rhs)
{
	if (lhs == rhs)
	{
		return false;
	}
	return true;
}

bool DataStructure::operator==(const ChronoData& lhs, const ChronoData& rhs)
{
	if (lhs.getDay() == rhs.getDay() && lhs.getMonth() == rhs.getMonth() && lhs.getYear() == rhs.getYear())
	{
		return true;
	}
	return false;
}

