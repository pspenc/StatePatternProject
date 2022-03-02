// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit/UnitAnimInstance.h"
#include "Unit/Unit.h"
#include "State/UnitState.h"

void UUnitAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if(GetOwningActor())
	{
		OwningUnit = Cast<AUnit>(GetOwningActor());
	}
	
}

void UUnitAnimInstance::UpdateAnimation()
{
	if(OwningUnit)
	{
		float MaxMovementSpeed = OwningUnit->GetMoveSpeed();
			
		float CurrentVelocityLength = OwningUnit->GetVelocity().Size();

		NormalizedSpeed = FMath::Clamp(CurrentVelocityLength/MaxMovementSpeed,0.f,1.f);
		if(OwningUnit->GetCurrentState())
		{
			bCanMove = OwningUnit->GetCurrentState()->CanMove();
		}
		
	}
	else
	{
		bCanMove = false;
	}
	
}

UUnitState* UUnitAnimInstance::GetCurrentState()
{
	if(OwningUnit)
	{
		return OwningUnit->GetCurrentState();
	}
	return nullptr;
}
