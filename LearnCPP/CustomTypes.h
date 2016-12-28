
#pragma once
#include "UniversialInclude.h"
#include <functional>
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
		std::cout << field << std::endl;
		return lhs.getHeader(field) < rhs.getHeader(field);
	}
	bool memberOfMessageSorter (int x) const;
	void setX(int inX);
private:
	std::string field;
public:
	int _x;
};

class AdressBook 
{
public:
	//using a template allows us to ignore the differences between functors, function pointers
	//add lambda
	AdressBook(std::vector<std::string> inVector) :_addresses(inVector) {}
	template<typename Func>
	std::vector<std::string> findMatchingAddresses(Func func)
	{
		std::vector<std::string> results;
		for (auto iter = _addresses.begin(); iter != _addresses.end(); ++iter)
		{
			//call the function passed into findMatchAddresses and see if it matches:
			if (func(*iter))
			{
				results.push_back(*iter);
			}
		}
		return results;
	}

private:
	std::vector<std::string> _addresses;
};

class EmailProcessor
{
public:
	EmailProcessor();
	EmailProcessor(std::vector<std::string>& invector);
	void receiveMessage(const std::string& message);
	void setHandlerFunc(std::function<void(const std::string&)> in_handler_fun);
	std::vector<std::string>& getMessages();
private:
	std::vector<std::string> messages;
	std::function<void(const std::string&)> _handler_func;
};

class MessageSizeStore
{
public:
	MessageSizeStore() : _max_size(0) {}
	void checkMessage(const std::string& msg);
	std::size_t getSize();
private:
	std::size_t _max_size;
};

class keyBind
{
public:
	keyBind(int inKey, std::function<void()> inFunc)
	:Key(inKey), Func(inFunc), prevkeyStatus(false)
	{

	}
	int Key;
	std::function<void()> Func;
	bool prevkeyStatus;
};