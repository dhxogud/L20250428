#pragma once
#include <conio.h>
#include "Engine.h"


class UInput
{
public:
	UInput();
	virtual ~UInput();

	void Tick();

	static int KeyCode;

	int NumKeys = 0;
	static const bool* KeyStates;
private:
};



