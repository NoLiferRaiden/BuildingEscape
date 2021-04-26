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
	void OpenDoor(float& DeltaTime);
	void CloseDoor(float& DeltaTime);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	
	float InitialYaw;
	float CurrentYaw;
	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnyWhere)
	float DoorCloseDelay = 2.f;

	UPROPERTY(EditAnyWhere)
	float DoorOpenSpeed = .8f;

	UPROPERTY(EditAnyWhere)
	float DoorCloseSpeed = 1.f;

	UPROPERTY(EditAnywhere);
	float OpenAngle = 90.0f;

	UPROPERTY(EditAnyWhere)
	ATriggerVolume* PressuePlate;
	
	UPROPERTY(EditAnyWhere)
	AActor* ActorThatOpens;

	UPROPERTY(EditAnyWhere)
	AActor* ComponentInScene;
	

};
