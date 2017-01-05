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
std::function<int(MessageSorter const&)> m_VarRep = &MessageSorter::_x;

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
