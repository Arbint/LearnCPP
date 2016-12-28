#pragma once
#include "UniversialInclude.h"
class InputManager
{
public:
	InputManager();
	virtual void listenToKeys();
	bool isKeyDown(int vKey);
	~InputManager();
	
};

