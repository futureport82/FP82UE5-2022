// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RideVehicle.h"
#include "TrackBase.h"
#include "VehicleTrain.generated.h"

UENUM(BlueprintType)
enum class ETrainMode : uint8
{
	None,
	Idle,
	Travel,
	Loading,
	DoorOpen,
	DoorClose,
	SpeedScalar,
	Stop
};


UCLASS()
class MAINUE5SCRATCH_API AVehicleTrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehicleTrain();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	int32 CarAmount = 5;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float DistanceBetweenCars = 317.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	TArray<float> VariableDistanceBetweenCars;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	ATrackBase* CurrentTrack;

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<ARideVehicle> RideVehicleClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	TArray<ARideVehicle*> RideVehicles;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float CurrentDistanceOnTrack = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float CurrentSpeed = -312.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float MaxSpeed = -312.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float MinSpeed = -100.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	ETrainMode CurrentMode = ETrainMode::Idle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float MonorailSpacerSize = 200.f;

	float vehicleDistanceOnTrack = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "SetUp")
	void StartTrain(ATrackBase* NewTrack, float StartingTrackPosition, float StartingDistanceBetweenVehicles);
};
