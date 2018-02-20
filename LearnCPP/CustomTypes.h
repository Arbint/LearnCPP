
#pragma once
#include "UniversialInclude.h"
#include <functional>

class Book;

enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


Month operator++(Month& m);
ostream& operator<<(ostream& os, Month& m);

//plain Enum:
enum EPlainMonth
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

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

class Token
{
public:
	char kind;
	double value;
	std::string name;
	Token(){}
	Token(char inKind, double inValue)
		:kind(inKind), value(inValue){}
	Token(char inKind)
		:kind(inKind){}
	Token(char inKind, std::string inName)
		:kind{ inKind }, name{ inName } {}
};

class Token_Stream {
public:
	//user interface
	Token_Stream()
	{
	}//make a token_stream that reads from cin
	Token get();
	void putback(Token t);

private:
	//implementation details
	//Not directly accessible to user of Token_stream
	bool full{ false };
	Token buffer;

};

class Name_Score
{
public:
	Name_Score(std::string inName, double inScore)
		:Name(inName), Score(inScore)
	{
	}
	
public:
	void print();

	std::string Name;
	double Score;

};

enum class EWordType
{
	Conjunction,
	Noun,
	Verb,
	The,
	Mark,
	unknown
};

class Variable 
{
public:
	std::string name;
	double value;
	Variable(std::string inName, double inValue)
		:name(inName), value(inValue) {}
};

class Varlib
{
public:
	std::vector<Variable> rawLib;
	double getValue(std::string name);
	void setValue(std::string name, double newValue);
	bool isDeclared(std::string name);
	double defineName(std::string newName, double newVal);
};

struct Point
{
	double x;
	double y;
	constexpr Point(double inX, double inY)
		: x(inX),y(inY)
	{

	}
};

class Year;

class Date
{
	//to be used as exception
	class InValid {};


public:
	Date(int inYear, Month inMonth, int inDay)
		:year(inYear), month(inMonth), day(inDay)
	{
		if (!is_valid())
		{
			throw InValid{};
		}
	}
	Date(int inYear)
		:year{inYear}
	{

	}
	Date()
		:year{ StaticClass().GetYear() },
		month{ StaticClass().GetMounth() },
		day{ StaticClass().getDay() }
	{

	}

	int GetYear() const
	{
		return year;
	}

	Month GetMounth() const
	{
		return month;
	}
	int getDay() const
	{
		return day;
	}
	bool is_valid();

	const Date& StaticClass();
private:
	int year{2001};
	Month month{Month::jan};
	int day{1};

};

ostream& operator<<(ostream& os, Date& date);

class Year
{
	static const int minYear = 1800;
	static const int maxYear = 2200;
public:
	class Invalid{};
	Year(int inYear)
		: year(inYear)
	{
		if (inYear < minYear || inYear > maxYear)
		{
			throw Invalid{};
		}
	}
	int getYear()
	{
		return year;
	}
private:
	int year;
};

class NameAgePair
{
public:
	NameAgePair(string inName, int inAge)
		:name{ inName }, age{inAge}
	{

	}
	string getName() const {
		return name;
	}
	int getAge() const {
		return age;
	}

	void setName(string& inName)
	{
		name = inName;
	}
	void setAge(int inAge)
	{
		age = inAge;
	}

//Operator Overrides:
	bool operator==(NameAgePair& rhs);
	bool operator!=(NameAgePair& rhs);
private:
	string name;
	int age;
};
ostream& operator<<(ostream& os, NameAgePair& nameAgePair);

class NamePairs
{
public:
	NamePairs();
	void readNames();
	void readAges();
	void printNameAgeInfo();

	//getters:
	std::vector<std::string> getNames() const;

	std::vector<int> getAges() const;

	std::vector<NameAgePair> getNameAgePairs() const;

	void sortInfo(std::function<bool(NameAgePair lsh, NameAgePair rhs)> waysToSort = [](NameAgePair lhs, NameAgePair rhs) {return lhs.getName() < rhs.getName(); });

	//Operator Overloads:
	bool operator==(NamePairs& rhs);
	bool operator!=(NamePairs& lhs);

private:
	std::vector<NameAgePair> nameAgePairs = {};
};
ostream& operator<<(ostream& os, NamePairs namePair);

enum class Days
{
	Mon = 1,
	Tue,
	Wed,
	Thur,
	Fri,
	Sat,
	Sun
};

Days operator++(Days& day);
std::ostream& operator<<(std::ostream& os, Days day);
std::string DaysToString(Days& inDay);