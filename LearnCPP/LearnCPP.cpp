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
		std::vector<std::string> Strings;
		std::ifstream stringFile{"Jingtian Li US Travel Plan.docx"};
		FillVector<string>(stringFile, Strings, '/');
		printVector<std::string>(Strings);
	}
	catch(Dates::invalid invaidMessage)
	{
		std::cout<<invaidMessage.what()<<std::endl;
	}  
}
