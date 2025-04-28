#include "Engine.h"
#include "World.h"
#include "Input.h"
#include "Renderer.h"

UEngine* UEngine::Instance = nullptr;

UEngine::UEngine()
{
	World = nullptr;
	InputDevice = nullptr;
}
UEngine::~UEngine()
{
	Terminate();
}

void UEngine::Initialize(const std::string& fileName)
{
	World = new UWorld();
	InputDevice = new UInput();
	World->Load(fileName);

	URenderer::GetInstance();
}

void UEngine::Run()
{
	InputDevice->Tick();
}

void UEngine::Terminate()
{
	if (InputDevice)
	{
		delete InputDevice;
		InputDevice = nullptr;
	}

	if (World)
	{
		delete World;
		World = nullptr;
	}
}

UEngine* UEngine::GetInstance()
{
	if (!Instance)
	{
		Instance = new UEngine();
	}
	return Instance;
}

void UEngine::Input()
{

}

void UEngine::Tick()
{

}

void UEngine::Render()
{

}
