// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseEnemyAnimInstance.generated.h"

class ABaseEnemy;
/**
 * 
 */
UCLASS()
class ALCHEMYGAME_API UBaseEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	// Simulates the tick function
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);

private:

	// Get Enemy
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	ABaseEnemy* Enemy;

	// Speed of Enemy
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess = "true"))
	float Speed;

	// Offset yaw used for strafing
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta=(AllowPrivateAccess = "true"))
	float MovementOffsetYaw;
};
