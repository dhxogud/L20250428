#include "Input.h"
#include "Windows.h"

int UInput::KeyCode; 
const bool* UInput::KeyStates;

UInput::UInput()
{
	KeyStates = SDL_GetKeyboardState(&NumKeys);
}

UInput::~UInput()
{
}

void UInput::Tick()
{
	//if (_kbhit())
	//{
	//	KeyCode = _getch();
	//}
	//else
	//{
	//	KeyCode = 0;
	//}
}