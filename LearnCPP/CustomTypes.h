#pragma once
#include "UniversialInclude.h"
enum class EMath
{
	add,
	subtract,
	multiply,
	divide,
	average,
	power
};

enum class ELiteralNum
{
	one,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
};

class unitInt
{
private:
	int amount;
	std::string unit;
public:
	void setAmount(int inAmount)
	{
		amount = inAmount;
	}
	void setUnit(std::string inUnit)
	{
		unit = inUnit;
	}
	unitInt()
		:unitInt(0, "noType")
	{
	
	}
	unitInt( int inAmount, std::string InUnit)
		:amount(inAmount), unit(InUnit)
	{

	}
	~unitInt()
	{

	}
	int getAmount()
	{
		return amount;
	}
	std::string getUnit()
	{
		return unit;
	}
	friend std::ostream& operator<<(std::ostream& out, unitInt& rhs);
};
