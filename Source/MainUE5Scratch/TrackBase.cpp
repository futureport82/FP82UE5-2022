// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackBase.h"

// Sets default values
ATrackBase::ATrackBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SceneComponent;

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	//Spline->AttachTo(RootComponent);
	Spline->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	Spline->SetRelativeLocationAndRotation(FVector(0, 0, 0), FRotator(0, 0, 0));
}

void ATrackBase::OnConstruction(const FTransform& Transform)
{
	TArray<UActorComponent*> comps = GetComponentsByClass(USplineMeshComponent::StaticClass());

	for (int i = 0; i < comps.Num(); i++) {
		comps[i]->DestroyComponent();
	}

	RefreshSplineMesh();
}

// Called when the game starts or when spawned
void ATrackBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrackBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrackBase::GetLocationAndRotationOnDistance(FVector &location, FRotator &rotation, float distance)
{
	location = Spline->GetWorldLocationAtDistanceAlongSpline(distance);
	rotation = Spline->GetWorldRotationAtDistanceAlongSpline(distance);
}

void ATrackBase::RefreshAllPoints()
{
	int lastIndex = SplineMeshes.Num();

	for (int i = 0; i < lastIndex; i++) {
		USplineMeshComponent* s = SplineMeshes[i];
		SetSplineMeshProperties(i, s);
	}

}

void ATrackBase::RefreshSplineMesh() {
	if (!UseSplineMesh || !SplineMeshToUse)
		return;

	int lastIndex = FMath::DivideAndRoundUp(Spline->GetSplineLength(), Spacing);

	SplineMeshes.Empty();

	for (int i = 0; i < lastIndex; i++) {

		USplineMeshComponent* s = NewObject<USplineMeshComponent>(this);

		s->SetStaticMesh(SplineMeshToUse);

		s->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

		SetSplineMeshProperties(i, s);

		SplineMeshes.Add(s);
	}
}

void ATrackBase::SetSplineMeshProperties(int32 ind, USplineMeshComponent* s) {

	FVector d1 = Spline->GetLocationAtDistanceAlongSpline(ind * Spacing, ESplineCoordinateSpace::World);

	FVector d2 = ((Spline->GetDirectionAtDistanceAlongSpline(ind * Spacing, ESplineCoordinateSpace::World)) * TangentScale);

	FVector d3 = Spline->GetLocationAtDistanceAlongSpline((ind * Spacing) + Spacing, ESplineCoordinateSpace::World);

	FVector d4 = ((Spline->GetDirectionAtDistanceAlongSpline((ind * Spacing) + Spacing, ESplineCoordinateSpace::World)) * TangentScale);

	s->SetStartAndEnd(d1, d2, d3, d4, true);

	float startRoll = FMath::DegreesToRadians(Spline->GetRotationAtDistanceAlongSpline(ind * Spacing, ESplineCoordinateSpace::Local).Roll);
	float endRoll = FMath::DegreesToRadians(Spline->GetRotationAtDistanceAlongSpline((ind * Spacing) + Spacing, ESplineCoordinateSpace::Local).Roll);

	s->SetStartRoll(startRoll, true);
	s->SetEndRoll(endRoll, true);

	RegisterAllComponents();
}