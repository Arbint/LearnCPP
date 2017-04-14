#include "stdafx.h"
#include "Book.h"
#include "CustomTypes.h"
#include "Patron.h"

Book::~Book()
{
}

void Book::setISBN(string newISBN)
{
	if (!isISBNValid(newISBN))
	{
		throw BookInvalid{ "Trying to change Wrong ISBN Format" };
	}
	ISBN = newISBN;
}

bool Book::isISBNValid(string ISBNToCheck)
{
	if (ISBNToCheck.size() != 4)
	{
		cout << "not valid 01" << endl;
		return false;
	}
	for (int i = 0; i <= 2; ++i)
	{
		if (!isCharNumber(ISBNToCheck[i]))
		{
			cout << "not valid 02" << endl;
			return false;
		}
	}
	if ((!isCharLetter(ISBNToCheck[3])) && (!isCharNumber(ISBNToCheck[3])))
	{
		cout << "not valid 03" << endl;
		return false;
	}

	return true;
}

bool Book::operator!=(const Book& rhs)
{
	if (*this == rhs)
	{
		return false;
	}
	return true;
}

bool Book::operator==(const Book& rhs)
{
	if (ISBN == rhs.getISBN())
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(ostream& os, Book& rhs)
{
	os << "Title: " << rhs.getTitile() << "\n";
	os << "Author: " << rhs.getAuthor() << "\n";
	os << "ISBN: " << rhs.getISBN();
	return os;
}

