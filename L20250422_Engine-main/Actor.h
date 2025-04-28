#pragma once
#include <iostream>
#include "Vector2D.h"

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

	char Shape;
	int RenderOrder;
	static bool CompareTo(const AActor* A, const AActor* B);
};

class ActorCompareTo
{
public:
	bool CompareTo(const AActor* A, const AActor* B)
	{
		return (A->RenderOrder > B->RenderOrder);
	}
};

//Actor has a Fvector2D
