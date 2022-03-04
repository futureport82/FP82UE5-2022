// Fill out your copyright notice in the Description page of Project Settings.


#include "RideVehicle.h"

// Sets default values
ARideVehicle::ARideVehicle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;

	RideVehicleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RideMesh"));
	//RideVehicleMesh->AttachTo(RootComponent);
	RideVehicleMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

void ARideVehicle::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);


	if (CurrentTrack)
	{
		CurrentTrack->GetLocationAndRotationOnDistance(TargetLocation, TargetRotation, CurrentDistanceOnTrack);

		SetActorLocationAndRotation(TargetLocation, TargetRotation);
	}

}

// Called when the game starts or when spawned
void ARideVehicle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARideVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TargetRotation.Pitch = 0;

	if (SmoothRotation)
	{
		CurrentRotation = FMath::Lerp(CurrentRotation, TargetRotation, DeltaTime * SmoothRotationAmt);
		SetActorRelativeRotation(CurrentRotation);
	}

	else
	{
		SetActorRelativeRotation(TargetRotation);
	}
}

void ARideVehicle::UpdateSmoothRotation(FRotator NewSmoothRotation)
{
	TargetRotation = NewSmoothRotation;
}

