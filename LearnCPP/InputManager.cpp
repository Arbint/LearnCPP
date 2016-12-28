#include "stdafx.h"
#include "InputManager.h"


InputManager::InputManager()
{
}


void InputManager::listenToKeys()
{
	bool bIsPreviousKeyDown = false;
	while (true)
	{
		if (isKeyDown(VK_ESCAPE) && !bIsPreviousKeyDown)
		{
			std::cout << "you pressed escape" << std::endl;
			bIsPreviousKeyDown = true;
		}
		if (!isKeyDown(VK_ESCAPE))		
		{
			bIsPreviousKeyDown = false;
		}
	}
}

bool InputManager::isKeyDown(int vKey)
{
	if (GetAsyncKeyState(vKey))
	{
		return true;
	}
	return false;
}



InputManager::~InputManager()
{

}
