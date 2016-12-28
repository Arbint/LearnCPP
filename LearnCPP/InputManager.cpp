#include "stdafx.h"
#include "InputManager.h"


InputManager::InputManager()
{
}


void InputManager::listenToKeys()
{
	while (true)
	{
		for (auto iter = keyBinds.begin(), end =keyBinds.end(); iter < end; ++iter)
		{
			if (isKeyDown((*iter)->Key) && !(*iter)->prevkeyStatus)
			{
				(*iter)->Func();
				(*iter)->prevkeyStatus = true;
			}
			if (!isKeyDown((*iter)->Key))
			{
				(*iter)->prevkeyStatus = false;
			}
		}
	}
}

void InputManager::AddKeyListening(std::shared_ptr<keyBind>& inKeyBind)
{
	keyBinds.push_back(inKeyBind);
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
