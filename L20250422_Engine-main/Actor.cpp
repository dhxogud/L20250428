#include "Windows.h"
#include "Actor.h"


AActor::AActor()
{
	Shape = ' ';
	RenderOrder = 0;
}
AActor::AActor(const FVector2D& InVector)
{
	Shape = ' ';
	Location = InVector;
	RenderOrder = 0;
}

AActor::~AActor()
{
}

void AActor::AddActorWorldOffset(FVector2D offset)
{
	Location.X += offset.X;
	Location.Y += offset.Y;
}

void AActor::Tick()
{
}

void AActor::Render()
{
	COORD Position = { static_cast<SHORT>(Location.X), (SHORT)Location.Y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);

	std::cout << Shape;
}

bool AActor::CompareTo(const AActor* A, const AActor* B)
{
	return (A->RenderOrder > B->RenderOrder);
}