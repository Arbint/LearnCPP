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
	string getUserName()
	{
		return userName;
	}
	int getLibraryCardNumer()
	{
		return libraryCardNumber;
	}
	int getLibraryFee()
	{
		return libraryFee;
	}
	bool isOwingLibraryFee()
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
};

