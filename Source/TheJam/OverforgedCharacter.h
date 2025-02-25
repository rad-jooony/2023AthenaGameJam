#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OverforgedCharacter.generated.h"

UCLASS()
class THEJAM_API AOverforgedCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOverforgedCharacter();

	// Replicated Variables 
	UPROPERTY(ReplicatedUsing = OnRep_Health)
	int Health;
	
	// RPC for server
	UFUNCTION(Server, Reliable)
	void Server_SampleAction();

	// Replication method
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Replication callback
	UFUNCTION()
	void OnRep_Health();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
