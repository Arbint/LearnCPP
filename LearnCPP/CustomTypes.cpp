#include "stdafx.h"
#include "UniversalFuc.h"
#include "CustomTypes.h"
#include "Constants.h"

std::ostream& operator<<(std::ostream& out, unitInt& rhs)
{
	std::string unit = rhs.getUnit();
	if (rhs.getAmount() > 1)
	{
		unit += "s";
	}
	out << rhs.getAmount() << " " << unit;
	return out;
}

std::ostream& operator<<(std::ostream& outStream, const Message& rhs)
{
	std::string outString = rhs.getHeader("what ever");
	outStream << outString;
	return outStream;
}

std::istream& operator >> (std::istream& out, unitInt& rhs)
{
	double inAmount;
	std::string inUnit;
	WrongInputRedoLabel:out >> inAmount >> inUnit;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "wrong input format, please use amount unit format, like 12 cm" << std::endl;
		goto WrongInputRedoLabel;
	}
	//need for the readlengthInMultiUnit() drill to work, thinkg of making a new class for it
	if (inUnit == "m" || inUnit == "cm" || inUnit == "inch" || inUnit == "foot" || inUnit == "C" || inUnit == "K")
	{
		rhs.setAmount(inAmount);
		rhs.setUnit(inUnit);
		return out;
	}
	else
	{
		std::cout << "cannot support the format, please re enter" << std::endl;
		goto WrongInputRedoLabel;
	}
}

std::string ElengthTypeToString(ELengthType InType)
{
	switch (InType)
	{
	case ELengthType::mm:
		return "mm";
		break;
	case ELengthType::cm:
		return "cm";
		break;
	case ELengthType::dm:
		return "dm";
		break;
	case ELengthType::m:
		return "m";
		break;
	case ELengthType::km:
		return "km";
		break;
	case ELengthType::inch:
		return "inch";
		break;
	case ELengthType::foot:
		return "foot";
		break;
	default:
		return "unknown Type";
		break;
	}
}

bool MessageSorter::memberOfMessageSorter(int x) const
{
	std::cout << x - _x << std::endl;
	return true;
}

void MessageSorter::setX(int inX)
{
	_x = inX;
}

EmailProcessor::EmailProcessor()
{

}

EmailProcessor::EmailProcessor(std::vector<std::string>& inVector)
	:messages(inVector)
{

}

void EmailProcessor::receiveMessage(const std::string& message)
{
	messages.push_back(message);
	_handler_func(message);
}

void EmailProcessor::setHandlerFunc(std::function<void(const std::string&)> in_handler_fun)
{
	_handler_func = in_handler_fun;
}

std::vector<std::string>& EmailProcessor::getMessages()
{
	return messages;
}

void MessageSizeStore::checkMessage(const std::string& msg)
{
	const std::size_t size = msg.size();

	if (size > _max_size)
	{
		_max_size = size;
	}
}

std::size_t MessageSizeStore::getSize()
{
	return _max_size;
}

void unitInt::convertTo(std::string newUnit, double raito)
{
	setUnit(newUnit);
	setAmount(amount * raito);
}

void unitInt::SetAmountAndUnit(double newAmount, std::string NewUnit)
{
	amount = newAmount;
	unit = NewUnit;
}

bool unitInt::operator>(unitInt& rhs)
{
	return amount > rhs.getAmount();
}

bool unitInt::operator<(unitInt& rhs)
{
	return amount < rhs.getAmount();
}

Token Token_Stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char getAnInput;
	std::cin >> getAnInput;
	switch (getAnInput)
	{

	//if the cin letter is directives or operators, return a token built from that
	case ';'://for printing
	case 'q'://for quitting
	case '(': case ')': case '+': case '-': case '*': case '/': case '%': case '=':
		return Token{ getAnInput }; // let each character represent itself

	//if the cin letter is a number or a decimal, put the number back and red it as a double
	//return a Token built from that
	case '.':
	case '0': case '1': case '2': case '3': case '4': case '5':
	case '6': case '7': case '8': case '9':
	{
		cin.putback(getAnInput);
		double getADouble;
		std::cin >> getADouble;
		return Token{ NumberType, getADouble };//we use char '8' as a numerical type
	}

	default:
		if (isalpha(getAnInput))
		{
			std::cin.putback(getAnInput);
			std::string getString;
			std::cin >> getString;
			if (getString == declkey)
			{
				return Token(let, 0);
			}
			return Token{ name, getString };
		}
		error("Bad Token");
		break;
	}
}

void Token_Stream::putback(Token t)
{
	if (full)
	{
		error("putback() into a full buffer");
	}
	buffer = t;
	full = true;
}

void Name_Score::print()
{
	std::cout << Name << " " << Score << std::endl;
}

double Varlib::getValue(std::string name)
{
	for (const Variable& VariableItem : rawLib)
	{
		if (VariableItem.name == name)
		{
			return VariableItem.value;
		}
		error("getValue: undefined variable: " + name);
	}
}

void Varlib::setValue(std::string name, double newValue)
{
	for (Variable& VariableItem : rawLib)
	{
		if (VariableItem.name == name)
		{
			VariableItem.value = newValue;
			return;
		}
	}
	error("setValue: undefined variable: " + name);
}

bool Varlib::isDeclared(std::string name)
{
	for (const Variable& variableItem : rawLib)
	{
		if (variableItem.name == name)
		{
			return true;
		}
	}
	return false;
}

double Varlib::defineName(std::string newName, double newVal)
{
	if (isDeclared(newName))
	{
		error("defineName: " + newName + " already defined");
	}
	rawLib.push_back(Variable(newName, newVal));
	return newVal;
}

