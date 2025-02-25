

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MultiplayerController.generated.h"

/**
 * 
 */
UCLASS()
class THEJAM_API UMultiplayerController : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec) // noah here - research Exec keyword in this context
	void HostGame();

	UFUNCTION(Exec)
	void JoinGame(const FString& Address);
};
