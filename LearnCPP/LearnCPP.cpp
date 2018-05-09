// LearnCPP.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "UniversialInclude.h"
#include "UniversalFuc.h"
#include "Drills.h"
#include "trigger.h"
#include "InputManager.h"
#include "ChronoData.h"
#include "Book.h"
#include "Dates.h"


int main()
{
	try
	{
		std::ifstream ist{"temps.txt"};
		if (!ist)
		{
			std::cout << "no exist" << std::endl;
		}
		std::vector<Reading> temps;
		int hour;
		double temperature;
		while (ist>>hour>>temperature)
		{
			temps.push_back(Reading{hour, temperature});
		}
		for (Reading temPair : temps)
		{
			std::cout << temPair << std::endl;
		}
	}
	catch(Dates::invalid invaidMessage)
	{
		std::cout<<invaidMessage.what()<<std::endl;
	}  
}
