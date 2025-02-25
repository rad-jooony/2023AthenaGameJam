

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "EnhancedInputSubsystems.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THEJAM_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Input Actions
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* HostGame;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JoinGame;
	
	void OnHostGame();
	void OnJoinGame();

protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
};
