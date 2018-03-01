#pragma once
#include "UniversialInclude.h"
#include "UniversalFuc.h"

enum class Monthes {
	Jan = 1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

class Dates
{
public:
	Dates(int inYear, Monthes inMonth, int inDay);
	Dates() :year(2001), month(Monthes::Jan), day(1) {}
	~Dates();
	int Year() { return year; }
	//TODO: Test Func, Delete
	int GetDaysInMonth();
	void addDay(int daysToAdd);
	void addMonth(int MonthToAdd);
	void addYear(int YearsToAdd);
	int getYear() { return year; }
	Monthes GetMonth() { return month; }
	int GetMonthAsNum();
	string GetMonthAsString();
	int getDay() { return day; }

private:
	int year;
	Monthes month;
	int day;
	static constexpr int YearMin = 1800;
	static constexpr int YearMax = 2200;

	bool isValid();
	bool isLeapYear();
	int getMonthDayAmount();
	int GetMonthNum();
	void addDay();
	void addMonth();
	void addYear();
// error handling
public:
	class invalid {
	public:
		invalid(std::string message):errorMessage(message)
		{}
		std::string what() { return errorMessage; }
	private:
		std::string errorMessage;
	};
};

std::ostream& operator<<(std::ostream& os, Dates& inDate);