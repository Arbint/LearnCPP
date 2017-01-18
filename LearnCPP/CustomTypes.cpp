#include "stdafx.h"
#include "CustomTypes.h"

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
	if (inUnit == "m" || inUnit == "cm" || inUnit == "inch" || inUnit == "foot")
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
