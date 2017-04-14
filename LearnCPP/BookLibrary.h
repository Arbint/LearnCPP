#pragma once
#include "UniversialInclude.h"

//Forward declarations
class Book;
class Patron;
class Date;
struct Transaction;

class BookLibrary
{
public:
	BookLibrary();
	~BookLibrary();

//API
	void AddBook(Book bookToAdd);
	void AddPatron(Patron patronToAdd);
	void checkOutBook(Book& bookToCheckOut, Patron& PatronCheckingIt, Date date);
	std::vector<Patron> getPatronOwesFee();

private:
	std::vector<Book> books;
	std::vector<Patron> patrons;
	std::vector<Transaction> transactions;

private:
	bool isBookAvaliable(Book& bookToCheck);
	bool isPatronRegistered(Patron& patronToCheck);
	bool isPatronOwesFee(Patron& patronToCheck);
	void AddTransaction(Book& book, Patron& patron, Date& Date);

};

