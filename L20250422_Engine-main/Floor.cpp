#include "Floor.h"

AFloor::AFloor()
{
	Color.r = 255;
	Color.g = 255;
	Color.b = 255;
	Color.a = 0;
}
AFloor::AFloor(const FVector2D& InVector)
{
	Location = InVector;
	Color.r = 255;
	Color.g = 255;
	Color.b = 255;
	Color.a = 0;
}
AFloor::~AFloor()
{
}