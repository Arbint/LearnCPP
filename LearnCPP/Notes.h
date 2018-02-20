#pragma once
#include "UniversialInclude.h"
#include "customTypes.h"
#include "UniversalFuc.h"
//create a lambda feels just like a function pointer with it's body provided while creating it.
void createLambda()
{
	auto func = []() {cout << "hello world!"; };
	func();
}


//useage of Lambda:

std::vector<std::string> gaga = { "wocao.org", "malgb", ".org", "cao ni ma. org" };
AdressBook global_Adress_book{ gaga };
std::vector<std::string> findAddressesFormOrgs()
{
	std::string name;
	std::cin >> name;
	return global_Adress_book.findMatchingAddresses([&](const std::string& addr) {return addr.find(name) != std::string::npos; });
}

void usageOfLambda()
{

	std::vector<std::string> gaga = { "wocao.org", "malgb", ".org", "cao ni ma. org" };
	AdressBook global_Adress_book{ gaga };


}


Message a{ "gaga" };
Message b{ "yaya" };
//a lambda with empty capture list will behaves like a old school fuction, and can be pointed 
//by a function pointer
int(*func)() = []()-> int {return 1; };

//std::function in <functional> will be able to represent functors, lambda, and function ptrs:

//functor:
MessageSorter sorter{ "happy" };
std::function<bool(const Message&, const Message&)> functorRep = std::ref(sorter);

//member function:
//the const is need when there is const in memberOfMessageSorter
std::function<bool(const MessageSorter&, int)> memberRep = &MessageSorter::memberOfMessageSorter;

//member variable:
std::function<int(const MessageSorter&)> m_VarRep = &MessageSorter::_x;

// lambdas:
std::function<bool(const std::string&)> lambdaRep = [](const std::string& gaga) {if (gaga == "happy") { std::cout << "it's happy" << std::endl; return true; }return false; };

//function pointers:
std::function<int(char)> getintFormCharacters = getIntFromChar;

void tryRepresents()
{
	functorRep(a, b);
	sorter.setX(12);
	memberRep(sorter, 1);
	std::cout << m_VarRep(sorter) << std::endl;;
	lambdaRep("happy");
}

/************************************************************************/
/* Chapter 5                                                            */
/************************************************************************/

//Error Reporting using return error value:
//ask user for a yes or no answer
//return 'b' to indicated a bad answer
char AskUser(std::string question)
{
	std::cout << question << "?(yes or no)\n";
	string answer = " ";
	cin >> answer;
	if (answer == "y" || answer == "yes") return 'y';
	if (answer == "n" || answer == "no") return 'n';
	return 'b';
}
//return  -1 to indicate a bad argument
int CalculateArea(int length, int width)
{
	if (length <=0 || width <=0)
	{
		return -1;
	}
	return length * width;
}

int FramedArea(int length, int width)
{
	return CalculateArea(length - 2, width - 2);
}


//Error Reporting using Exceptions:
class BadArea {}; //A type specifically for reporting errors from AreaWithException()

//calculate area of a rectangle;
//throw a BadArea exception in case of a bad argument
int AreaWithException(int length, int width)
{
	if (length <= 0 || width <= 0)
	{
		throw BadArea{};
	}
	return length*width;
}

//so now, what we can do is try catch like this:
void tryCatchException()
{
	
	try
	{
		int x = -1;
		int y = 2;
		int z = 4;
		//...
		int area1 = AreaWithException(x, y);
		int area2 = FramedArea(1, z);
		int area3 = FramedArea(y, z);
		double ratio = area1 / area3;
	}
	catch (BadArea badAreaCatched)
	{
		//this is to get rid of the none referenced variable warning when compiling
		badAreaCatched = BadArea();
		std::cout << "you got bad input for area" << std::endl;
		//do something

	}
}


//Out of range error:
int outOfRangeError()
{
	try
	{
		vector<int> v;
		for (int x; cin >> x;)
		{
			v.push_back(x);
		}
		for (int i = 0; i <= v.size(); ++i)
		{
			cout << "v[" << i << "] ==" << v[i] << std::endl;
		}
	}
	catch (out_of_range)
	{
		cerr << "Opps! Ranage Error\n";
		return 1;
	}
	catch (...)
	{
		cerr << "Exception: something went wrong\n";
		return 2;
	}
	return 0;
}


//Bad input Errors
int badInputErrors()
{
	try
	{
		double d = 0;
		std::cin >> d;
		if (!cin)
		{
			throw(runtime_error("this is getting out of hand"));
		}

	}
	catch (runtime_error& error)
	{
		std::cerr << error.what() << std::endl;
		return 2;
	}
	return 2;
}

void NarrowTest()
{
	 
}


/************************************************************************/
/*Chapter 8                                                             */
/************************************************************************/
//a declaration is a statement that introduces a name into a scope,
//it basically defines how something can be used.
void declaration()
{
	int a = 7;
	const double cd = 8.7;
}

//a declaration that also fully specifies the entity declared is called a definition:
//example:
void definition()
{
	int a = 7;
}

double sqrt(double)
{
	return 0;
}
//you can do definition only once, but you can declare stuff many times


//A reference is a construct that allows a user to declare a new name for 
//an object, for example, int& is a reference to an int, so we can write:
void reference()
{
	int i = 7;
	int& r = i;
	r = 9;
	i = 10;
	std::cout << r << " " << i << std::endl;
}

//constant key word:
//This file explains how const works.
//
//The following declarations are identical :
//const char* p;
//char const* p;
//
//Both declare a pointer to a constant character.The second is slightly
//better in the sense that the declaration can be read from right - to - left:
//"p is a pointer to a const char".Read as such, it is easy to see that
//the line *p = 'c'; will not compile.
//
//The following declaration :
//char* const p;
//
//declares p to be a constant pointer to a character.That is :
//p = "foo"; // Does not compile
//*p = 'f'; // Compiles!
//
//And thus :
//const char* const p;
//char const* const p;
//
//both declare p to be a constant pointer to a constant character, and
//so none of the following lines of code compile :
//p = "foo";
//*p = 'f';
//
//
//Now throw another pointer into the mix :
//const char** p;
//char const** p;
//
//These are equivalent and declare p to be a pointer to a pointer to a
//constant character.That is :
//p = ptr - to - ptr - to - char; // Compiles
//*p = ptr - to - char; // Compiles
//**p = 'f'; // Does not compile
//
//Or how about creative placement of const:
//char* const* p;
//
//This declares p to be a pointer to a constant pointer to a character.
//That is :
//p = ptr - to - constptr - to - char; // Compiles
//*p = ptr - to - char; // Does not compile
//*p = constptr - to - char; // Does not compile
//**p = 'f'; // Compiles
//
//And the ever - popular:
//char** const p;
//
//Which declares p to be a constant pointer to a pointer to a character.
//Or:
//p = ptr - to - ptr - to - char; // Does not compile
//p = constptr - to - ptr - to - char; // Does not compile
//*p = ptr - to - char; // Compiles
//**p = 'f'; // Compiles
//
//And now we get just plain const happy :
//const char* const* p;
//
//p is a pointer to a constant pointer to a constant character.The only
//thing you can do with this one(besides remove the code and rewrite) is:
//p = ptr - to - constptr - to - constchar;
//
//const char** const p;
//p is a constant pointer to a pointer to a constant character.The only
//thing you can do with this is:
//*p = ptr - to - constchar;
//
//And this beast:
//const char* const* const p;
//
//Well, it won't pass code review since nobody will understand it, but at
//any rate... We've achieved maximum constant-ness with this line. You
//can't do anything at all with p, what it points to, what that points to,
//or what "what that" points to.You can print it.That's about it.
//
//
//Ho - ho, and the fun is just beginning.Now throw in REFERENCES!
//
//const char& p;
//char const& p;
//
//These both declare p to be a reference to a constant character.That is,
//p cannot change.
//
//char& const p;
//const char& const p;
//char const& const p;
//char*& const p;
//const char*& const p;
//const char* const& const p;
//
//These all generate compiler errors, because there is no such thing as
//a constant reference I guess.
//
//const char*& p;
//char const*& p;
//
//p is a reference to a pointer to a constant character.One can change p,
//but not *p.
//
//char* const& p;
//
//p is a reference to a constant pointer to a character.
//
//const char* const& p;
//
//p is a reference to a constant pointer to a constant character.
//
//const char&* p;
//char const&* p;
//char& const* p;
//char&* const p;
//const char& const* p;
//const char&* const p;
//const char& const* const p;
//
//Fortunately pointers to references are not allowed.The above declarations
//are illegal.The programmer who attempts to use the above declarations
//should be fired anyway.
//
//
//As for mutable and const member functions.
//Here's an example:
//
//1
//2
//3
//4
//5
//6
//7
//8
//class Foo {
//public:
//	void DoSomething() const;
//private:
//	int someData;
//	char moreData;
//	float yetMoreData;
//};
//
//
//Note the "const" after DoSomething().This means that DoSomething() is a const member function.This says that DoSomething() will not modify any of its own data members when it executes.Why is saying this useful ? Because it is a contract to Foo's user. Let's extend the example :
//
//1
//2
//3
//4
//5
//6
//7
//8
//9
//10
//11
//12
//class Foo {
//public:
//	void DoSomething() const;
//	void WorkHard();
//	void PrintMe() const
//	{
//		cout << someData << ", " << moreData << ", " << yetMoreData << endl;
//	}
//
//private:
//	int someData;
//	char moreData;
//	float yetMoreData;
//};
//
//
//(I've omitted things like constructors, etc, to distill the code to its bare essence)
//	Suppose you have a variable of type Foo, and that Foo's data members were
//	actually initialized to something useful :
//
//1
//2
//3
//4
//5
//Foo f;   // Let's say someData = 42, moreData = 'X', and yetMoreData = 3.14.
//
//f.PrintMe();  // Prints 42, X, 3.14
//f.DoSomething();
//f.PrintMe();  // Better print 42, X, and 3.14 
//
//
//Why do I say that the second call to PrintMe() better print the same values as
//the first call ? How can I even know as a user of Foo, since I can't see what
//DoSomething() does ? Because DoSomething() is a const member function.It is
//a contract to me, the user, that says that DoSomething() will not modify any of its
//(non - mutable, but more on that later) data members.
//
//Now notice that WorkHard() is not declared as a const member function.So :
//
//	1
//	2
//	3
//	4
//	5
//	Foo f;   // Let's say someData = 42, moreData = 'X', and yetMoreData = 3.14.
//
//f.PrintMe();  // Prints 42, X, 3.14
//f.WorkHard();
//f.PrintMe();  // What will this print? 
//
//
//Because WorkHard() is not declared const, it means that WorkHard() might modify one or more of the data members.Hopefully the description of the function tells me exactly what it does.For example "multiplies someData by 2, increments moreData and wraps
//at 'Z' back to 'A'.Does not modify yetMoreData." Unfortunately, in practice, too many developers don't document well and don't follow const-correctness, and all too often it actually becomes hard to know whether a member function will modify state or not without looking at the implementation of the function (sometimes it is not obvious).
//
//The point is... declaring a member function const is part of the API that you are giving to the programmer who will use your code.
//
//Now, on to mutable.First, a classroom example, and then I'll give you a real-world example of where I used mutable in my code (I cannot publish the code here, but I will explain why I needed/wanted to use mutable).
//
//So const is part of the API of the class to the programmer, to guarantee that the object won't "change state" across calls to the function. Sometimes, your object might have some very internal data that your user couldn't possibly care about.For example, let's say you have a class that can send messages on a socket.
//
//1
//2
//3
//4
//5
//6
//7
//class MySocket {
//public:
//	// ...
//	int Send(const char* data, int length) const;
//private:
//	int sock;       // The file descriptor used to send data
//};
//
//
//I declared Send() to be const, because it doesn't change any data members (sock).
//
//Now, suppose for whatever reason I, the programmer of Socket, want to copy the
//user's data into an internal cache in the class. Let's also say that my user cannot possibly care about what is in the internal cache.
//
//1
//2
//3
//4
//5
//6
//7
//8
//class MySocket {
//public:
//	// ...
//	int Send(const char* data, int length) const;
//private:
//	int sock;       // The file descriptor used to send data
//	mutable char cache[4096];   // Ok, yes, hard-coded constant is hideous.  anyway.      
//};
//
//
//So now Send() wants to copy the user's data into the cache, but it can't because
//Send() is a const member function.So I make my cache mutable, and now Send()
//can do this.
//
//Why, you ask, don't I just make Send() non-const and forget the mutable? Possibly two reasons. First, if there is a lot of code using Socket already, it might be impractical for me to change Send() this way without causing a lot of compile errors (because my users might have been relying on Send() being const when they wrote their const-correct code). Second, as I stipulated earlier, my users can't possibly care that the cache changed when Send() was called.
//
//Now for the example of how I used mutable.
//
//I had a class that implemented a table control for our user interface.My table allows users to change the text in cells, or change the fonts in cells, etc.One of my goals in developing this class was to have my table class automatically compute the row heights and column widths necessary to be able to draw the cell text without clipping.Consequently, every time the user changes the font or changes text, I have to recompute the entire table size.This is a fairly expensive operation, and I did not want to incur that penalty.
//
//Now my class also has a Size() method -- declared const --that returns the actual height and width in pixels of the table.Obviously Size() doesn't change the fonts or colors or spacing or text or anything that the user cares about, so that's why it's const.
//
//So how did I optimize my size calculations ? I decided that my table class will keep two additional data members -- one for the row heights and one for the column widths.These members are calculated by the Size() method and stored internally in the object.
//So my class looks something like :
//
//[code]
//class Table {
//public:
//	size Size() const;
//private:
//	int columns;
//	int rows;
//	CellData tableData[50][50]; // Data for each cell, such as text, font, color, etc.
//	mutable int rowHeights[50]; // I'm simplifying here... I never use arrays
//	mutable int colWidths[50]; // but that is another story.
//};
//
//Yes, there were other ways to do this.But I chose this way as the most readable / maintainable method for future programmers.
//
//So to make the long story short, here's a brief summary:
//0) See my above documentation on interpreting const when used to modify
//variables.
//1) const can be used to guarantee to your users that a member function
//will not modify the object in any way the user could possibly care about.
//2) The problems with not being const - correct are :
//a) in many cases your users won't know if the member function modifies
//state or you, as the programmer of the class, just were being sloppy and
//forgot to declare the function const;
//b) it makes writing const - correct code that uses your code almost impossible.
//3) Sometimes(VERY RARELY) you might have a data member that your users
//can't possibly care about, and you need to modify it inside a const member
//function.This is when you declare the data member mutable.

