#include "Windows.h"

#include "Engine.h"

int main()
{
	GEngine->Initiailze();
	GEngine->Run();

	//OS Buffer
	// 이중 버퍼링 방식
	// Render 클래스가 이 함수 갖고 수행함
	HANDLE ScreenHandles[2];

	ScreenHandles[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenHandles[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	int ScreenIndex = 0;

	while (true)
	{
		SetConsoleCursorPosition(ScreenHandles[ScreenIndex], COORD{ 10, 10 });

		WriteConsole(ScreenHandles[ScreenIndex], "P", 1, NULL, NULL);

		SetConsoleActiveScreenBuffer(ScreenHandles[ScreenIndex]);

		ScreenIndex++;
		ScreenIndex %= 2;
	}

	return 0;
}