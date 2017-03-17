#include "stdafx.h"
#include "Patron.h"
#include "Book.h"

Patron::Patron()
{
}


Patron::Patron(string inUserName, int inLibraryCardNumber, int inLibrarayFee)
	:userName{ inUserName }, libraryCardNumber{ inLibraryCardNumber }, libraryFee{ inLibrarayFee }
{

}

Patron::~Patron()
{
}

void Patron::setUserName(string newUserName)
{
	userName = newUserName;
}

void Patron::setLibrarayCardNumber(int newLibrarayCardNum)
{
	libraryCardNumber = newLibrarayCardNum;
}

void Patron::setLibrarayFee(int newLibrarayFee)
{
	libraryFee = newLibrarayFee;
}

void Patron::setOweLibraryFee(bool newFeeStats)
{
	bIsOweLibraryFee = newFeeStats;
}
