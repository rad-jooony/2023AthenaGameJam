


#include "OverforgedCharacter.h"

#include "Net/UnrealNetwork.h"


// Sets default values
AOverforgedCharacter::AOverforgedCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOverforgedCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AOverforgedCharacter::OnRep_Health()
{
	// Update UI or effects here
}


void AOverforgedCharacter::Server_SampleAction_Implementation()
{
	// Server-side implementation
}

void AOverforgedCharacter::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AOverforgedCharacter, Health);
}



// Called every frame
void AOverforgedCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AOverforgedCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

