#pragma once
#include "UniversalFuc.h"
#include "UniversialInclude.h"

enum class EBookGenre
{
	Fiction = 1,
	Nonfiction,
	Periodical,
	Biography,
	Children,
	None
};

class BookInvalid
{
public:
	BookInvalid(string message) : invalidMessage{ message } {}
	string what()
	{
		return invalidMessage;
	}
private:
	string invalidMessage;
};

class Book
{
public:
	//error throw class:


	Book()
		:Book("000A", "Untitled", "NoBody", "0000000x0",EBookGenre::None,false)
	{

	}
	Book(string inISBN, string inTitle, string inAuthor, string inCopyRightData, EBookGenre inGenre, bool inbIsCheckedOut)
		:ISBN{ inISBN }, title{ inTitle }, author{ inAuthor }, copyRightData{ inCopyRightData }, Genre{inGenre}, bIsCheckedOut {
		inbIsCheckedOut
	}
	{
		if (!isISBNValid(ISBN))
		{
			throw BookInvalid{"ISBN Wrong Format"};
		}
	}
	~Book();

	//Getters:
	string getISBN()
	{
		return ISBN;
	}
	string getTitile()
	{
		return title;
	}
	string getAuthor()
	{
		return author;
	}
	string getCopyRightData()
	{
		return copyRightData;
	}
	bool IsCheckedOut()
	{
		return bIsCheckedOut;
	}
	EBookGenre GetBookGenre()
	{
		return Genre;
	}

	//setters:
	void setISBN(string newISBN);
	void setTitle(string newTitle)
	{
		title = newTitle;
	}
	void setAuthor(string newAuthor)
	{
		author = newAuthor;
	}
	void setCopyRightData(string newCopyRightData)
	{
		copyRightData = newCopyRightData;
	}
	void setCheckOutStats(bool bCheckedOut)
	{
		bIsCheckedOut = bCheckedOut;
	}
	void setBookGenre(EBookGenre newGenre)
	{
		Genre = newGenre;
	}

	//operator overrides:
	bool operator==(Book& rhs);
	bool operator!=(Book& rhs);


private:
	string ISBN;
	string title;
	string author;
	string copyRightData;
	bool bIsCheckedOut;
	EBookGenre Genre;

	bool isISBNValid(string ISBNToCheck);
	
};

//osOverride:
ostream& operator<<(ostream& os, Book& rhs);