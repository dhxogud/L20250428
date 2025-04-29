#include "World.h"
#include "Actor.h"

#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Floor.h"
#include "Goal.h"
#include "Renderer.h"

UWorld::UWorld()
{

}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	URenderer::GetInstance()->Clear();
    //system("cls");
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
	URenderer::GetInstance()->Present();
}

void UWorld::Load(std::string filename)
{
	std::ifstream MapFile(filename);
	int Y = 0;

	while (!MapFile.eof())
	{
		int X = 0;
		char Buffer[200] = { 0, };
		MapFile.getline(Buffer, 100);
		for (X = 0; X < strlen(Buffer); ++X)
		{
			SpawnActor(new AFloor(FVector2D(X, Y)));
			if (Buffer[X] == '*')
			{
				SpawnActor(new AWall(FVector2D(X, Y)));
			}
			else if (Buffer[X] == 'G')
			{
				SpawnActor(new AGoal(FVector2D(X, Y)));
			}
			else if (Buffer[X] == 'P')
			{
				SpawnActor(new APlayer(FVector2D(X, Y)));
			}
			else if (Buffer[X] == 'M')
			{
				SpawnActor(new AMonster(FVector2D(X, Y)));
			}
		}
		Y++;
	}

	MapFile.close();

	//sort
	// 내가쓴거 버블솔트 정렬 구현
	/*for (int i = 0; i < Actors.size() - 1; i++)
	{
		for (int j = i; j < Actors.size(); j++)
		{
			if (Actors[i]->RenderOrder < Actors[j]->RenderOrder)
			{
				AActor* Temp = Actors[i];
				Actors[i] = Actors[j];
				Actors[j] = Temp;
			}
		}
	}*/

	//static으로 CompartTo 구현 (AActors.cpp  에 구현되어 있다.)
	//std::sort(Actors.begin(), Actors.end(), AActor::CompareTo);

	////lambda 함수 구현
	//std::sort(Actors.begin(), Actors.end(), [](const AActor* A, AActor* B) {
	//	return A->RenderOrder > B->RenderOrder;
	//});
}

void UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);
}

void UWorld::DestoryActor(AActor* DestroyedActor)
{
	Actors.erase(find(Actors.begin(), Actors.end(), DestroyedActor));
}

std::vector<AActor*>& UWorld::GetAllActors()
{
	return Actors;
}