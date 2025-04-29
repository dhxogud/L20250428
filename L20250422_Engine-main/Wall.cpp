#include "Wall.h"

AWall::AWall()
{
	Color.r = 255;
	Color.g = 255;
	Color.b = 0;
	Color.a = 0;
}

AWall::AWall(const FVector2D& InVector)
{
	Location = InVector;
	Color.r = 255;
	Color.g = 255;
	Color.b = 0;
	Color.a = 0;
}
AWall::~AWall()
{
}
