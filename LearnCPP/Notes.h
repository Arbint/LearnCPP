#pragma once
#include "UniversialInclude.h"


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