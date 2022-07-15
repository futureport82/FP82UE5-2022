// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackTrigger.h"

// Sets default values
ATrackTrigger::ATrackTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATrackTrigger::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if(Track)
	{ 
		SetActorLocation(Track->Spline->GetLocationAtDistanceAlongSpline(TrackPosition,ESplineCoordinateSpace::World));
		SetActorRotation(Track->Spline->GetRotationAtDistanceAlongSpline(TrackPosition, ESplineCoordinateSpace::World));
	}
}

// Called when the game starts or when spawned
void ATrackTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrackTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

