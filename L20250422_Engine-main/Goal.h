#pragma once
#include "Actor.h"

class AGoal : public AActor
{
public:
	AGoal();
	AGoal(const FVector2D& InVector);
	virtual ~AGoal();
};

