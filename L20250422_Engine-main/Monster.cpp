#include "Monster.h"
#include<cstdlib>
#include<ctime>

AMonster::AMonster()
{
	Shape = 'M';
	RenderOrder = 6;
}
AMonster::AMonster(const FVector2D& InVector)
{
	Shape = 'M';
	Location = InVector;
	RenderOrder = 6;
}
AMonster::~AMonster()
{

}

void AMonster::Tick()
{
	//std::srand((unsigned int)std::time(NULL));

	//int Next = rand();

	//switch (Next % 4)
	//{
	//	case 0:
	//		AddActorWorldOffset(FVector2D(0, -1));
	//		break;
	//	case 1:
	//		AddActorWorldOffset(FVector2D(0, 1));
	//		break;
	//	case 2:
	//		AddActorWorldOffset(FVector2D(-1, 0));
	//		break;
	//	case 3:
	//		AddActorWorldOffset(FVector2D(1, 0));
	//		break;
	//}
}