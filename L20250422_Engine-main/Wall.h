#pragma once
#include "Actor.h"

class AWall : public AActor
{
public:
	AWall();
	AWall(const FVector2D& InVector);
	virtual ~AWall();
};

