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
	out >> inAmount >> inUnit;
	rhs.setAmount(inAmount);
	rhs.setUnit(inUnit);
	return out;
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
