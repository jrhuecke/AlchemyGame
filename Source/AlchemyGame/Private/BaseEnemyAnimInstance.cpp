// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemyAnimInstance.h"

#include "AlchemyGame/BaseEnemy.h"
#include "Kismet/KismetMathLibrary.h"

void UBaseEnemyAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (Enemy == nullptr) 
	{
		Enemy = Cast<ABaseEnemy>(TryGetPawnOwner());
	}

	if (Enemy)
	{
		// Get lateral speed of enemy from velocity
		FVector Velocity{ Enemy->GetVelocity() };
		Velocity.Z = 0;
		Speed = Velocity.Size();

		// Get offset yaw to use in blend spaces
		FRotator AimRotation = Enemy->GetBaseAimRotation();
		FRotator MovementRotation = UKismetMathLibrary::MakeRotFromX(Enemy->GetVelocity());

		MovementOffsetYaw = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation).Yaw;
	}
}
