#pragma once
#include <string>

class UInput;
class UWorld;

class UEngine
{
private:
	UEngine();
	~UEngine();
	static UEngine* Instance;

public:
	void Initialize(const std::string& fileName = "map");
	void Run();
	void Terminate();
	static UEngine* GetInstance();

private:
	void Input();
	void Tick();
	void Render();

	UInput* InputDevice;
	UWorld* World;
};

#define	GEngine	UEngine::GetInstance();
