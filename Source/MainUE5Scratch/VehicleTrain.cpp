// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleTrain.h"

// Sets default values
AVehicleTrain::AVehicleTrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVehicleTrain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehicleTrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int i = 0; i < RideVehicles.Num(); i++)
	{
		if (VariableDistanceBetweenCars.Num() > 0)
			vehicleDistanceOnTrack = CurrentDistanceOnTrack - (i * VariableDistanceBetweenCars[i]);
		
		else
			vehicleDistanceOnTrack = CurrentDistanceOnTrack - (i * DistanceBetweenCars);
		

		if(vehicleDistanceOnTrack < 0)
			vehicleDistanceOnTrack += CurrentTrack->Spline->GetSplineLength();

		RideVehicles[i]->SetActorLocation(CurrentTrack->Spline->GetLocationAtDistanceAlongSpline(vehicleDistanceOnTrack, ESplineCoordinateSpace::World));
		RideVehicles[i]->UpdateSmoothRotation(CurrentTrack->Spline->GetRotationAtDistanceAlongSpline(vehicleDistanceOnTrack + 100, ESplineCoordinateSpace::World));
	}

	CurrentDistanceOnTrack += (CurrentSpeed * DeltaTime);

	//If we are past the end of the track, loop to beginning (When speed is positive)
	if(CurrentDistanceOnTrack >= CurrentTrack->Spline->GetSplineLength() && CurrentSpeed > 0)
		CurrentDistanceOnTrack = 0;

	//If we are past the end of the track, loop to beginning (When speed is negative)
	if(CurrentDistanceOnTrack <= 0 && CurrentSpeed < 0)
		CurrentDistanceOnTrack = CurrentTrack->Spline->GetSplineLength();
	
}

void AVehicleTrain::StartTrain(ATrackBase* NewTrack, float StartingTrackPosition, float StartingDistanceBetweenVehicles)
{
	CurrentTrack = NewTrack;
	CurrentDistanceOnTrack = StartingTrackPosition;
	DistanceBetweenCars = StartingDistanceBetweenVehicles;
	CurrentMode = ETrainMode::Travel;
}
