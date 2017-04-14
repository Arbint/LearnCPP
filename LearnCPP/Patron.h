#pragma once
#include "UniversalFuc.h"
#include "UniversialInclude.h"
class Book;
class Patron
{
public:
	Patron();
	Patron(string inUserName, int inLibraryCardNumber, int inLibrarayFee);
	~Patron();

	//getters:
	string getUserName() const
	{
		return userName;
	}
	int getLibraryCardNumer() const
	{
		return libraryCardNumber;
	}
	int getLibraryFee() const
	{
		return libraryFee;
	}
	bool isOwingLibraryFee() const
	{
		return bIsOweLibraryFee;
	}

	//setters:
	void setUserName(string newUserName);
	void setLibrarayCardNumber(int newLibrarayCardNum);
	void setLibrarayFee(int newLibrarayFee);
	void setOweLibraryFee(bool newFeeStats);

private:
	string userName;
	int libraryCardNumber;
	int libraryFee;
	bool bIsOweLibraryFee;
	
public:
	//operator overload
	bool operator==(const Patron& lhs);
	bool operator!=(const Patron& rhs);
};

