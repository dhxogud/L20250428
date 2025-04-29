#include "Windows.h"
#include "Actor.h"
#include "Renderer.h"
#include "SDL3/SDL.h"

AActor::AActor()
{
	//Shape = ' ';
	RenderOrder = 0;
	if (TextureFileName.size() > 0)
	{
		std::string Temp = "./data/" + TextureFileName;
		Surface = SDL_LoadBMP(Temp.c_str());
		//VRAM : CPU가 GPU에게 일거리 줄때 공간
		Texture = SDL_CreateTextureFromSurface(URenderer::GetInstance()->Renderer, Surface);
	}
	
}
AActor::AActor(const FVector2D& InVector)
{
	//Shape = ' ';
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
	URenderer::GetInstance()->Render(this);
}

bool AActor::CompareTo(const AActor* A, const AActor* B)
{
	return (A->RenderOrder > B->RenderOrder);
}