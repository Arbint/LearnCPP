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
int main()
{
	FactoryMethodClass* FMC_One = FactoryMethodClass::GetInstance();
	FMC_One->Set("jt", 29);
	
	FactoryMethodClass* FMC_Two = FactoryMethodClass::GetInstance();
	FMC_Two->Set("Matt", 25);
	
	FMC_One->Print();
	FMC_Two->Print();

	delete FMC_One;
}

