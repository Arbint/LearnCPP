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
	try {
		/*void(*GameToPlay)() = NameScoreRecorder;
		PlayBox(GameToPlay);
		*/

		std::cout << std::sqrt(3) * 6 << std::endl;
		std::cout << GetHexagonArea(2) << std::endl;
		return 0;
		}
	

	//Error Catching Blocks:
	catch (BadArea)
	{
		std::cout << "the area calculation is having bad input somewhere." << std::endl;
	}
	catch (...)
	{

	}
}
