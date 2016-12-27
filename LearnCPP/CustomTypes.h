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

//en mum value to string method for ELength Type
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
public:
	friend std::istream& operator>>(std::istream& out, unitInt& rhs);
};

class LengthUnit : public unitInt
{
public:
	LengthUnit(double inAmount, ELengthType inUnitType)
		:unitInt::unitInt(inAmount, ElengthTypeToString(inUnitType))
	{

	}
};

class MyFunctorClass 
{
private:
	int Value;
public:
	MyFunctorClass(int inVlaue) : Value(inVlaue) {}
	int operator()(int inInt) { return Value + inInt; };
};

class Message
{
public:
	Message(std::string inString) :stringHeader(inString) {}
	std::string getHeader(const std::string& header_name) const { return stringHeader; }
private:
	std::string stringHeader;

	//other methods...
	friend std::ostream& operator<<(std::ostream& outStream, const Message& rhs);
};

//this is an functor that can be used to sort stuff
class MessageSorter
{
public:
	//talk the field to sort by in the constructor
	MessageSorter(const std::string& infield) : field(infield) {}
	bool operator()(const Message& lhs, const Message& rhs)
	{
		return lhs.getHeader(field) < rhs.getHeader(field);
	}
private:
	std::string field;
};