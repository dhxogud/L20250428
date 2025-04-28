#pragma once
class URenderer
{
private:
	static URenderer* Instance;

public:
	URenderer();
	~URenderer();
	static URenderer* GetInstance();

};

URenderer* URenderer::Instance;
