#pragma once
#include "UniversialInclude.h"
class Trigger
{
public:
	Trigger();
	Trigger(std::string inTriggerString);
	~Trigger();
	
	void triggerDynamic();
	void triggered();
	void AddDynamic(std::function<void()> inDynamic);
private:
	std::vector<std::function<void()>> _triggerFucs;
	std::string triggerString;
};

