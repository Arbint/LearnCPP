#pragma once
#include "UniversialInclude.h"
#include "CustomTypes.h"
namespace DataStructure
{
	//Date Data Structure class
	class ChronoData
	{
	public:
		class Invalid {};

		ChronoData(int inYear, Month inMonth, int inDay);
		ChronoData();// default constructor
		~ChronoData();
		//non-modifying operations:
		int getDay() const;
		Month getMonth() const;
		int getYear() const;

		//modifying operation:
		void add_day(int daysToAdd);
		void add_month(int MonthToAdd);
		void add_year(int YearToAdd);

		const ChronoData& staticClass();

	private:
		int year{2001};
		Month month{Month::jan};
		int day{1};
		void add_One_day();
		void add_One_Month();

	};
	

	//Helper functions:
	bool isDataValid(int year, Month month, int day);
	
	bool leapYear(int y);
	bool operator==(const ChronoData& lhs, const ChronoData& rhs);
	bool operator!=(const ChronoData& lhs, const ChronoData& rhs);

	ostream& operator<<(ostream& os, const ChronoData& inData);
	istream& operator>>(istream& is, ChronoData& inData);
	//...
}