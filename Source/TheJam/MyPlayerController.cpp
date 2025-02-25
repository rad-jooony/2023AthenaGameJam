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
	
	if (IsLocalController())
	{
		ENetMode NetMode = GEngine->GetNetMode(GetWorld());
		FString NetModeString;

		switch (NetMode)
		{
		case NM_Standalone:
			NetModeString = TEXT("Standalone");
			break;
		case NM_ListenServer:
			NetModeString = TEXT("ListenServer");
			break;
		case NM_DedicatedServer:
			NetModeString = TEXT("DedicatedServer");
			break;
		case NM_Client:
			NetModeString = TEXT("Client");
			break;
		default:
			NetModeString = TEXT("Unknown");
			break;
		}

		UE_LOG(LogTemp, Warning, TEXT("[%s] Host Game Pressed!"), *NetModeString);
	}
}

void AMyPlayerController::OnJoinGame()
{
	if(UMultiplayerController* GI = Cast<UMultiplayerController>(GetGameInstance()))
	{
		GI->JoinGame("127.0.0.1");
	}

	if (IsLocalController())
	{
		ENetMode NetMode = GEngine->GetNetMode(GetWorld());
		FString NetModeString;

		switch (NetMode)
		{
		case NM_Standalone:
			NetModeString = TEXT("Standalone");
			break;
		case NM_ListenServer:
			NetModeString = TEXT("ListenServer");
			break;
		case NM_DedicatedServer:
			NetModeString = TEXT("DedicatedServer");
			break;
		case NM_Client:
			NetModeString = TEXT("Client");
			break;
		default:
			NetModeString = TEXT("Unknown");
			break;
		}

		UE_LOG(LogTemp, Warning, TEXT("[%s] Join Game Pressed!"), *NetModeString);
	}
}
			

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController())
	{
		TArray<AActor*> FoundCameras;
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("SharedCamera"), FoundCameras);
		if (FoundCameras.Num() > 0)
		{
			if (ACameraActor* SharedCamera = Cast<ACameraActor>(FoundCameras[0]))
			{
				SetViewTarget(SharedCamera);
			}
		}
	}
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
	