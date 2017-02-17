// LearnCPP.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "UniversialInclude.h"
#include "UniversalFuc.h"
#include "Drills.h"
#include "Notes.h"
#include "trigger.h"
#include "InputManager.h"

int main()
{
	try
	{	
		int y = UnnamedArgsCanBeIgnored(1, 2);
	}
	catch (runtime_error& error)
	{
		std::cerr << error.what() << std::endl;
	}
	catch (BadRange& error)
	{
		std::cerr << "Runtime Error: " << error.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "Unknown error happens." << std::endl;
	}
}
