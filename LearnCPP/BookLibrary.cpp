#include "stdafx.h"
#include "BookLibrary.h"
#include "Book.h"
#include "Patron.h"

struct Transaction
{
	Book book;
	Patron patron;
	Date date;

	Transaction(Book inBook, Patron inPatron, Date inDate)
		:book{ inBook }, patron(inPatron), date{ inDate }
	{

	}
};


BookLibrary::BookLibrary()
{
}


BookLibrary::~BookLibrary()
{
}

void BookLibrary::AddBook(Book bookToAdd)
{
	books.push_back(bookToAdd);
}

void BookLibrary::AddPatron(Patron patronToAdd)
{
	patrons.push_back(patronToAdd);
}

void BookLibrary::checkOutBook(Book& bookToCheckOut, Patron& PatronCheckingIt, Date date)
{
	if (isBookAvaliable(bookToCheckOut))
	{
		removeElementFromVect(books, bookToCheckOut);
		AddTransaction(bookToCheckOut, PatronCheckingIt, date);
	}
}

std::vector<Patron> BookLibrary::getPatronOwesFee()
{
	std::vector<Patron> patronOwesFee;
	for (Patron& item : patrons)
	{
		if (item.isOwingLibraryFee())
		{
			patronOwesFee.push_back(item);
		}
	}
	return patronOwesFee;
}

bool BookLibrary::isBookAvaliable(Book& bookToCheck)
{
	if (VectorHasElement(books, bookToCheck))
	{
		return true;
	}
	return false;
}

bool BookLibrary::isPatronRegistered(Patron& patronToCheck)
{
	if (VectorHasElement(patrons, patronToCheck))
	{
		return true;
	}
	return false;
}

bool BookLibrary::isPatronOwesFee(Patron& patronToCheck)
{
	return patronToCheck.isOwingLibraryFee();
}

void BookLibrary::AddTransaction(Book& book, Patron& patron, Date& Date)
{
	Transaction newTransAction{book, patron, Date};
	transactions.push_back(newTransAction);
}

