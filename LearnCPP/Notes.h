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