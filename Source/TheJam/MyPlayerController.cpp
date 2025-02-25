#include "MyPlayerController.h"

#include "EngineUtils.h"
#include "EnhancedInputComponent.h"
#include "MultiplayerController.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void AMyPlayerController::OnHostGame()
{
	if(UMultiplayerController* GI = Cast<UMultiplayerController>(GetGameInstance()))
    {
        GI->HostGame();
    }
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Host Game Pressed!"));
	}
}

void AMyPlayerController::OnJoinGame()
{
	if(UMultiplayerController* GI = Cast<UMultiplayerController>(GetGameInstance()))
	{
		GI->JoinGame("127.0.0.1");
	}
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("Join Game Pressed!"));
	}
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Cast to EnhancedInputComponent
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (HostGame)
		{
			// `ETriggerEvent::Triggered` fires **every frame** while the input is held
			// `ETriggerEvent::Started` Fires **once** when input first meets activation criteria
			// `ETriggerEvent::Completed` Fires **once when input is released** (useful for actions like charging attacks)
			EnhancedInput->BindAction(HostGame, ETriggerEvent::Started, this, &AMyPlayerController::OnHostGame);
		}

		if (JoinGame)
		{
			EnhancedInput->BindAction(JoinGame, ETriggerEvent::Started, this, &AMyPlayerController::OnJoinGame);
		}
	}
}
