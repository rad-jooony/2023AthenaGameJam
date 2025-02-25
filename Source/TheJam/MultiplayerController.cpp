#include "MultiplayerController.h"

void UMultiplayerController::HostGame()
{
	GetWorld()->ServerTravel("/Game/Core/Levels/TestLevel?listen");
}

void UMultiplayerController::JoinGame(const FString& Address)
{
	if(APlayerController* PC = GetFirstLocalPlayerController())
	{
		PC->ClientTravel(Address, TRAVEL_Absolute);
	}
}
