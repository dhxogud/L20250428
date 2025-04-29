#include "Engine.h"
#include "World.h"
#include "Input.h"

UEngine* UEngine::Instance = nullptr;

UEngine::UEngine() //: World(nullptr)
{
	World = nullptr;
	InputDevice = nullptr;
	Window = nullptr;
	IsRunning = true;
}

UEngine::~UEngine()
{
	Terminate();
}

void UEngine::Initiailze(std::string filename)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	Window = SDL_CreateWindow("Sample", 800, 600, SDL_WINDOW_OPENGL);

	InputDevice = new UInput();
	World = new UWorld();
	World->Load(filename);

}

void UEngine::Run()
{
	while (IsRunning)
	{
		switch (Event.type)
		{
			case SDL_EVENT_QUIT:
				IsRunning = false;
				break;
		}
		SDL_PollEvent(&Event);
		Input();
		Tick();
		Render();
	}
}

void UEngine::Terminate()
{
	if (World)
	{
		delete World;
		World = nullptr;
	}

	if (InputDevice)
	{
		delete InputDevice;
		InputDevice = nullptr;
	}

	SDL_DestroyWindow(Window);
	SDL_Quit();
}

void UEngine::Input()
{
	InputDevice->Tick();
	//Engine has a Input
	//키보드, 마우스, 조이스틱, 터치, 자이로 센스
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}
