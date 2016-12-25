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

enum class ELengthType
{
	mm = 0,
	cm,
	dm,
	m,
	km,
	inch,
	foot
};

//enmum value to string method for ELength Type
std::string ElengthTypeToString(ELengthType InType);

class unitInt
{
protected:
	double amount;
	std::string unit;
public:
	void setAmount(double inAmount)
	{
		amount = inAmount;
	}
	virtual void setUnit(std::string inUnit)
	{
		unit = inUnit;
	}
	unitInt()
		:unitInt(0, "noType")
	{
	
	}
	unitInt(double inAmount, std::string InUnit)
		:amount(inAmount), unit(InUnit)
	{

	}
	~unitInt()
	{

	}
	double getAmount()
	{
		return amount;
	}
	std::string getUnit()
	{
		return unit;
	}
	friend std::ostream& operator<<(std::ostream& out, unitInt& rhs);
};

class LengthUnit : public unitInt
{
public:
	LengthUnit(double inAmount, ELengthType inUnitType)
		:unitInt::unitInt(inAmount, ElengthTypeToString(inUnitType))
	{

	}
};