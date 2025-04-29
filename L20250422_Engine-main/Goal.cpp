#include "Goal.h"

AGoal::AGoal()
{
	Color.r = 255;
	Color.g = 255;
	Color.b = 255;
	Color.a = 0;
}
AGoal::AGoal(const FVector2D& InVector)
{
	Color.r = 255;
	Color.g = 255;
	Color.b = 255;
	Color.a = 0;
	Location = InVector;

}
AGoal::~AGoal()
{ 
}