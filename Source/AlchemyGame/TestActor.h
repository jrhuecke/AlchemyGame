// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class ALCHEMYGAME_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category = "TestValues") int32 ValueA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category = "TestValues") int32 ValueB;

	UFUNCTION(BlueprintCallable, Category = "TestFunctions") int32 CalculateValue();
	UFUNCTION(BlueprintNativeEvent, Category = "TestFunctions") void OnValueCalculate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
