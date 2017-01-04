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
	void(*GameToPlay)() = GetPrimNumberBetween;
	PlayBox(GameToPlay);

	return 0;

}

