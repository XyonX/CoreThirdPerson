// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonAnimInstance.h"

// MyAnimInstance.cpp

#include "MyAnimInstance.h"

UThirdPersonAnimInstance::UThirdPersonAnimInstance()
{
	// Initialize default values for AnimationData
	AnimationData.MovementSpeed = 0.0f;
	AnimationData.bIsJumping = false;
}

void UThirdPersonAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	// Implement animation logic here (e.g., blending animations, updating bone transforms)
	// Use AnimationData.MovementSpeed and AnimationData.bIsJumping for your calculations
}

void UThirdPersonAnimInstance::UpdateAnimationData(float Speed, bool bJumping)
{
	// Update the AnimationData with the provided values
	AnimationData.MovementSpeed = Speed;
	AnimationData.bIsJumping = bJumping;
}

// Add more functions and logic for other animation calculations if needed

