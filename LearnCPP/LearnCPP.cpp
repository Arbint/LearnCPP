// LearnCPP.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "UniversialInclude.h"
#include "UniversalFuc.h"
#include "Drills.h"
#include "Notes.h"
#include "trigger.h"
#include "InputManager.h"
#include "my.h"
#include "ChronoData.h"
#include "Book.h"

extern int fooTest = 0;


extern vector<string> monthLib{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main()
{
	try
	{
	
	}
	catch (runtime_error& error)
	{
		std::cerr << error.what() << std::endl;
	}
	catch (BadRange& error)
	{
		std::cerr << "Runtime Error: " << error.what() << std::endl;
	}
	catch (BookInvalid& error)
	{
		std::cerr << "Runtime Error: " << error.what()<< std::endl;
	}
	catch(...)
	{
		std::cerr << "Unknown error happens." << std::endl;
	}
}
