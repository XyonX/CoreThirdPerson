// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonAnimInstanceProxy.h"


FThirdPersonAnimInstanceProxy::FThirdPersonAnimInstanceProxy()
{
}

FThirdPersonAnimInstanceProxy::FThirdPersonAnimInstanceProxy(UAnimInstance* InAnimInstance)
	: FAnimInstanceProxy(InAnimInstance)
{
	// Initialize default values for AnimationData
	AnimationData.MovementSpeed = 0.0f;
	AnimationData.bIsJumping = false;
}

void FThirdPersonAnimInstanceProxy::UpdateAnimationData(const FMyAnimationData& NewAnimationData)
{
	// Update the AnimationData with the provided data from the game thread
	AnimationData = NewAnimationData;
}

// Add more functions and logic for other animation calculations if needed
