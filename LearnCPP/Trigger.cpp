#include "stdafx.h"
#include "Trigger.h"


Trigger::Trigger()
{
}


Trigger::Trigger(std::string inTriggerString):triggerString(inTriggerString)
{

}

Trigger::~Trigger()
{
}


void Trigger::triggerDynamic()
{
	for (std::function<void()> tirggerFunIter : _triggerFucs)
	{
		tirggerFunIter();
	}
}

void Trigger::triggered()
{
	std::cout << triggerString << std::endl;
}

void Trigger::AddDynamic(std::function<void()> inDynamic)
{
	_triggerFucs.push_back(inDynamic);
}
