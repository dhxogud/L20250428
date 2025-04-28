#include "Windows.h"

#include "Engine.h"

int main()
{
	GEngine->Initiailze();
	GEngine->Run();

	//OS Buffer
	// ���� ���۸� ���
	// Render Ŭ������ �� �Լ� ���� ������
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