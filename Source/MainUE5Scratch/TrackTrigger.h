// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrackBase.h"
#include "TrackTrigger.generated.h"

UENUM(BlueprintType)
enum class ETrackTrigger : uint8
{
	None,
	ChangeColor,
	Narration,
	StopNarration,
	StartBGM,
	EndBGM,
	LoadFWE,
	LoadFWW
};

UCLASS()
class MAINUE5SCRATCH_API ATrackTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrackTrigger();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SetUp")
	float TrackPosition = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SetUp")
	ATrackBase* Track;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnConstruction(const FTransform& Transform) override;

};
