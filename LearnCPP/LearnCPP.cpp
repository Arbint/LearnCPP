// LearnCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UniversalFuc.h"
#include "UniversialInclude.h"
#include "Drills.h"



int main()
{	
	vector<Message> messages;
	Message gaga{ "gaga" };
	Message gg{ "wht" };
	Message Apple{"apple"};
	messages.push_back(gaga);
	messages.push_back(gg);
	messages.push_back(Apple);
	//read in messages;
	MessageSorter comparator{"gaga"};
	sort(messages.begin(), messages.end(), comparator);
	
	printVector(messages);

	return 0;
}

