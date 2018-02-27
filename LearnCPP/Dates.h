#pragma once
#include "UniversialInclude.h"

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
	//TODO: Finish Implementing Adding day month and year
	void addDay();
	void addMonth();
	void addYear();
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