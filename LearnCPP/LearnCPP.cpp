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
	/*void(*GameToPlay)() = NameScoreRecorder;
	PlayBox(GameToPlay);
	*/
	try {
		int cTempreature = io::GetUerInput<int>("Please give me the temperature in Celsius:");
		std::cout << "it is " << ctok(cTempreature) << " Kalvin out side";
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
