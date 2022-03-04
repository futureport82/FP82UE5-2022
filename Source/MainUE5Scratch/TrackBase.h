// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SplineComponent.h"
#include "Runtime/Engine/Classes/Components/SplineMeshComponent.h"
#include "TrackBase.generated.h"

UCLASS()
class MAINUE5SCRATCH_API ATrackBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrackBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	USplineComponent* Spline;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SetUp")
	USceneComponent* SceneComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spline Mesh Set Up")
	bool UseSplineMesh = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spline Mesh Set Up")
	float Spacing = 200.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spline Mesh Set Up")
	float TangentScale = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline Mesh Set Up")
	UStaticMesh* SplineMeshToUse;

	TArray<USplineMeshComponent*> SplineMeshes;

	UFUNCTION(BlueprintCallable, Category = "Helpers")
		void GetLocationAndRotationOnDistance(FVector &location, FRotator &rotation, float distance);

	void RefreshAllPoints();

	void RefreshSplineMesh();

	void SetSplineMeshProperties(int32 ind, USplineMeshComponent* s);
};
