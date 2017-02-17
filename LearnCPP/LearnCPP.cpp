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
		std::vector<int> VectorLarger;
		std::vector<int> VectorSmaller;
		io::getMultiUserInputs<int>("give me some thing for larger: ", VectorLarger);
		io::getMultiUserInputs<int>("give me some thing for larger: ", VectorSmaller);
		std::cout << "switching" << std::endl;
		largerSmaller(VectorLarger, VectorSmaller);
		printVector(VectorLarger);
		printVector(VectorSmaller);
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
