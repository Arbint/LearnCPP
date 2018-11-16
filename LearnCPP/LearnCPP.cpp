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
#include "FactoryMethodClass.h"
#include "AutoPtr.h"



Auto_ptr4<Resource> generateResource()
{
	Auto_ptr4<Resource> res(new Resource);
	return res; // this return value will invoke the move constructor
}

int main()
{
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the copy assignment

	return 0;
}
