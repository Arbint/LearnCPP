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

std::vector<std::string> monthLib{"Jan"};
int fooTest = 1;
int main()
{
	try
	{
		Dates BirthDay{};
	}
	catch(Dates::invalid invaidMessage)
	{
		std::cout<<invaidMessage.what()<<std::endl;
	}

}
