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
	void Clear();	// 화면 지우고
	//void Render(const FVector2D& Loaction, char Shape); // 화면에 랜더링 해주고
	void Render(const AActor* RenderObject);
	void Present();	// 화면 뒤집기 == Handle 교체
};

