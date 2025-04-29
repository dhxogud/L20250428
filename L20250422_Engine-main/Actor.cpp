#include "Windows.h"
#include "Actor.h"
#include "Renderer.h"
#include "SDL3/SDL.h"

AActor::AActor()
{
	ColorKey = {255, 255, 255, 255};
}
AActor::AActor(const FVector2D& InVector)
{
	ColorKey = { 255, 255, 255, 255 };
	Location = InVector;
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

void AActor::Load()
{
	if (TextureFileName.size() > 0)
	{
		std::string Temp = "./data/" + TextureFileName;
		Surface = SDL_LoadBMP(Temp.c_str());
		const SDL_PixelFormatDetails* PixelDetails =
			SDL_GetPixelFormatDetails(Surface->format);

		SDL_SetSurfaceColorKey(Surface, true, 
			SDL_MapRGB(PixelDetails, nullptr, ColorKey.r, ColorKey.g, ColorKey.a ));
		//VRAM : CPU가 GPU에게 일거리 줄때 공간
		Texture = SDL_CreateTextureFromSurface(URenderer::GetInstance()->Renderer, Surface);
	}
}