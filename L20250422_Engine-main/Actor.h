#pragma once
#include <iostream>
#include "Vector2D.h"
#include "SDL3/SDL.h"
#include <string>


class AActor
{
public:
	AActor();
	AActor(const FVector2D& InVector);
	virtual ~AActor();

	void AddActorWorldOffset(FVector2D offset);
	FVector2D Location;

	virtual void Tick();
	virtual void Render();
	virtual void Load();

	static bool CompareTo(const AActor* A, const AActor* B);

	SDL_Color Color;
	SDL_Color ColorKey;

	std::string TextureFileName;
	SDL_Surface* Surface;
	SDL_Texture* Texture;
};

//class ActorCompareTo
//{
//public:
//	bool CompareTo(const AActor* A, const AActor* B)
//	{
//		return (A->RenderOrder > B->RenderOrder);
//	}
//};

//Actor has a Fvector2D
