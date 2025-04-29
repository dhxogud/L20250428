#include "Player.h"
#include "Input.h"
#include "Engine.h"

APlayer::APlayer()
{

}
APlayer::APlayer(const FVector2D& InVector)
{

	Location = InVector;

}
APlayer::~APlayer()
{

}

void APlayer::Tick()
{
	switch (GEngine->Event.key.key)
	{
	case SDLK_W:
	case SDLK_UP:
		AddActorWorldOffset(FVector2D(0, -1));
		break;
	case SDLK_S:
	case SDLK_DOWN:
		AddActorWorldOffset(FVector2D(0, 1));
		break;
	case SDLK_F:
	case SDLK_RIGHT:
		AddActorWorldOffset(FVector2D(1, 0));
		break;
	case SDLK_A:
	case SDLK_LEFT:
		AddActorWorldOffset(FVector2D(-1, 0));
		break;
	}
}
