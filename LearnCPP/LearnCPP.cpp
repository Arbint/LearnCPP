// LearnCPP.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "UniversialInclude.h"
#include "UniversalFuc.h"
#include "Drills.h"
#include "trigger.h"
#include "InputManager.h"
#include "my.h"
#include "ChronoData.h"
#include "Book.h"
#include "Dates.h"
#include "CustomTypes.h"
std::vector<std::string> monthLib{"Jan"};
int fooTest = 1;


int main()
{
	std::cout << "Please enter input file name: ";
	string iname;
	std::cin >> iname;
	ifstream ist{iname};
	if (!ist)
	{
		std::cout << "cannot open input files: " << iname << std::endl;
	}
	else
	{
		std::string oname;
		std::cout << "Please enter name of output file: ";
		cin >> oname;
		ofstream ost{ oname };
		vector<Reading> temps;
		int hour;
		double temperature;
		while (ist >> hour >> temperature)
		{
			temps.push_back(Reading{ hour, temperature });
		}
		for (int i=0; i < temps.size(); ++i)
		{
			ost << '(' << temps[i].hour << ',' << temps[i].tempearture << ")\n";
		}
	}
}
