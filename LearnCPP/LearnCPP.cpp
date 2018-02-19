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

enum class Days 
{
	Mon = 1,
	Tue,
	Wed,
	Thur,
	Fri,
	Sat,
	Sun
};

std::vector<std::string> monthLib{"Jan"};
int fooTest = 1;
int main()
{
	int castedInt = static_cast<int>(Days(1));
	std::cout << castedInt;
}
