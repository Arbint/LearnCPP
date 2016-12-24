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