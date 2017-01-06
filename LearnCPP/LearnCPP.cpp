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
	try{
		double d = 0;
		std::cin >> d;
		if (!std::cin)
		{
			error("ok, I cannot find any double to read");
		}
		
	}
	catch (runtime_error& e)
	{
		std::cerr <<"Runtime error: " << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "Unknown Exception" << std::endl;
	}
	error("gaga");

	return 0;
}
