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
		std::cout << "Please enter input file name: ";
		string inName;
		cin >> inName;
		ifstream ist{inName};
		if (!ist)
		{
			error("Can't open file");
		}
	}
	catch(Dates::invalid invaidMessage)
	{
		std::cout<<invaidMessage.what()<<std::endl;
	}
}
