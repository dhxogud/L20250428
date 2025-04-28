#pragma once
#include "Actor.h"

class AMonster : public AActor
{
public:
	AMonster();
	AMonster(const FVector2D& InVector);
	virtual ~AMonster();

	virtual void Tick() override;
};