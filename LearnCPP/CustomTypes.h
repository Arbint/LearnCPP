
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

enum RockPaperScissors
{
	ERPS_Rock = 1,
	ERPS_Paper = 2,
	ERPS_Scissors = 3
};

enum EWinLose
{
	EWL_Win = 1,
	EWL_Lose = 2,
	EWL_Even = 3
};

template<typename T>
struct EquationResult
{
	std::vector<T> results;
	bool bIsValid;

	//check if the result is valid;
	bool Successed()
	{
		return bIsValid;
	}
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
	void convertTo(std::string newUnit, double raito);
	std::string getUnit()
	{
		return unit;
	}
	void SetAmountAndUnit(double newAmount, std::string NewUnit);
public:
	bool operator>(unitInt& rhs);
	bool operator<(unitInt& rhs);
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

template<class TOne, class TTwo>
class Typepairs
{
public:
	TOne _TOne;
	TTwo _TTwo;	
	Typepairs(TOne inTOne, TTwo inTTow)
		:_TOne{ inTOne }, _TTwo{inTTow}
	{
		
	}

};

template<typename TypeOne, typename TypeTwo>
class Library
{
public:
	std::vector<Typepairs<TypeOne, TypeTwo>> typePaires;
	Library(std::vector<Typepairs<TypeOne, TypeTwo>> inPairs)
		: typePaires{inPairs}
	{
	}

	TypeTwo get(TypeOne inKey)
	{
		for (Typepairs<TypeOne, TypeTwo> pairIter : typePaires)
		{
			if (pairIter._TOne == inKey)
			{
				return pairIter._TTwo;
			}
		}
		return typePaires[0]._TTwo;
	}
	TypeOne get(TypeTwo inKey)
	{
		for (Typepairs<TypeOne, TypeTwo> pairIter : typePaires)
		{
			if (pairIter._TTwo== inKey)
			{
				return pairIter._TOne;
			}
		}
		return typePaires[0]._TOne;
	}

	std::vector<TypeTwo> getMulti(TypeOne inKey)
	{
		std::vector<TypeTwo> returnValues;
		for (Typepairs<TypeOne, TypeTwo> pairIter : typePaires)
		{
			if (pairIter._TOne == inKey)
			{
				returnValues.push_back(pairIter._TTwo);
			}
		}
		return returnValues;
	}

	std::vector<TypeOne> getMulti(TypeTwo inKey)
	{
		std::vector<TypeOne> returnValues;
		for (Typepairs<TypeOne, TypeTwo> pairIter : typePaires)
		{
			if (pairIter._TTwo == inKey)
			{
				returnValues.push_back(pairIter._TOne);
			}
		}
		return returnValues;
	}

	bool Check(TypeOne inKey)
	{
		for (Typepairs<TypeOne, TypeTwo> pairIter : typePaires)
		{
			if (pairIter._TOne == inKey)
			{
				return true;
			}
		}
		return false;
	}
	bool Check(TypeTwo inKey)
	{
		for (Typepairs<TypeOne, TypeTwo> pairIter : typePaires)
		{
			if (pairIter._TTwo == inKey)
			{
				return true;
			}
		}
		return false;
	}
};

class BadRange {
	std::string _ErrorMessage;
public:
	BadRange(std::string InMessage)
		:_ErrorMessage(InMessage)
	{

	}
	BadRange() = delete;
	std::string what()
	{
		return _ErrorMessage;
	}
};

class Temperature : public unitInt
{

public:
	Temperature(int Amount, std::string Unit)
		:unitInt(Amount, Unit)
	{

	}
	~Temperature()
	{
	}
};

class WrongArg {
	std::string _info;
public:
	WrongArg(std::string inInfo)
		:_info(inInfo)
	{

	}
	std::string what()
	{
		return _info;
	}

};