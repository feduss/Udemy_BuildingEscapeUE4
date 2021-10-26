// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:

	void MoveDoor(float DeltaTime, FRotator TargetRotator);

	FRotator TargetActorRotatorOpen;
	FRotator TargetActorRotatorClose;

	UPROPERTY(EditAnywhere)
	float OpenAngle = -90.0f;

	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
	float DoorClosingDelay = 2.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpensTheDoor;
	
		
};