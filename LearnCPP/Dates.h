#pragma once
#include "UniversialInclude.h"

enum class Monthes {
	Jan = 1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

class Dates
{
public:
	Dates(int year, Monthes month, int day);
	Dates() :year(2001), month(Monthes::Jan), day(1) {}
	~Dates();
	int Year() { return year; }
private:
	int year;
	Monthes month;
	int day;
	static constexpr int YearMin = 1800;
	static constexpr int YearMax = 2200;

	bool isValid();

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