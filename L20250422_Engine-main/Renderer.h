#pragma once
#include <Windows.h>
#include "Vector2D.h"

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

	void Clear();	// ȭ�� �����
	void Render(const FVector2D& Loaction, char Shape); // ȭ�鿡 ������ ���ְ�
	void Present();	// ȭ�� ������ == Handle ��ü
};

