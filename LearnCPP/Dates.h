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

	void addDay(int daysToAdd);
	void addMonth(int MonthToAdd);
	void addYear(int YearsToAdd);

	//Getters
	int getYear() const { return year; }
	Monthes GetMonth() const{ return month; }
	int GetMonthAsNum() const;
	string GetMonthAsString() const;
	int GetDaysInMonth() const;
	int getDay() const{ return day; }

private:
	int year;
	Monthes month;
	int day;
	static constexpr int YearMin = 1800;
	static constexpr int YearMax = 2200;

	bool isValid() const;
	bool isLeapYear() const;
	int getMonthDayAmount() const;
	int GetMonthNum() const;
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
std::istream& operator>>(istream& is, Date& inDate);
std::ostream& operator<<(std::ostream& os, Dates& inDate);