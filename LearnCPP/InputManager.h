#pragma once
#include "UniversialInclude.h"
#include "CustomTypes.h"
class InputManager
{
public:
	InputManager();
	virtual void listenToKeys();
	void AddKeyListening(std::shared_ptr<keyBind>& inKeyBind);
	bool isKeyDown(int vKey);
	~InputManager();
private:
	std::vector<std::shared_ptr<keyBind>> keyBinds;
};

