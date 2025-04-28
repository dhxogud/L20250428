#include "Windows.h"
#include "Actor.h"
#include "Renderer.h"

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
	URenderer::GetInstance()->Render(Location, Shape);
}

bool AActor::CompareTo(const AActor* A, const AActor* B)
{
	return (A->RenderOrder > B->RenderOrder);
}