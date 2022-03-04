// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrackBase.h"
#include "RideVehicle.generated.h"

UENUM(BlueprintType)
enum class EVehicleMode : uint8
{
	Idle,
	Running,
	Stopped,
	EndOfTrack,
	Station,
	None
};

UCLASS()
class MAINUE5SCRATCH_API ARideVehicle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARideVehicle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	USceneComponent* SceneComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	ATrackBase* CurrentTrack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	UStaticMeshComponent* RideVehicleMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float CurrentDistanceOnTrack = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	bool SmoothRotation = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float SmoothRotationAmt = 3.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	FRotator TargetRotation;

	FRotator CurrentRotation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	EVehicleMode CurrentMode = EVehicleMode::Idle;

	FVector TargetLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	UCurveFloat* AccelerationCurve;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float MaxAcceleration = 0.9807f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float MaxSpeedPerMetersSecond = 1.8288f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float AccelerationStartTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float CurrentAccelerationTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float AccelerationTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float CurrentSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	float TargetSpeed;

	UFUNCTION(BlueprintCallable, Category = "Helpers")
		void UpdateSmoothRotation(FRotator NewSmoothRotation);



};
