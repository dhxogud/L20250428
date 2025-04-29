#pragma once
#include <Windows.h>
#include "Vector2D.h"
#include "SDL3/SDL.h"

class AActor;

class URenderer
{
protected:
	URenderer();
	virtual ~URenderer();
	static URenderer* Instance;

	HANDLE ScreenHandles[2];
	int CurrentScreenIndex = 0;

public:
	static URenderer* GetInstance();

	SDL_Renderer* Renderer;
	void Clear();	// ȭ�� �����
	//void Render(const FVector2D& Loaction, char Shape); // ȭ�鿡 ������ ���ְ�
	void Render(const AActor* RenderObject);
	void Present();	// ȭ�� ������ == Handle ��ü
};

