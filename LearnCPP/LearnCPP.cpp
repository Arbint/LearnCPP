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
	try
	{
		int x = -1;
		int y = 2;
		int z = 4;
		//...
		int area1 = AreaWithException(x, y);
		int area2 = FramedArea(1, z);
		int area3 = FramedArea(y, z);
		double ratio = area1 / area3;
	}
	catch (BadArea Area)
	{
		std::cout << "Oops, bad arguments to area()\n";
	}
	return 0;

}
