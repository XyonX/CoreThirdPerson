// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonAnimInstanceProxy.h"
#include "CorePlugin/Data/AnimationData.h"


FThirdPersonAnimInstanceProxy::FThirdPersonAnimInstanceProxy()
{
}

FThirdPersonAnimInstanceProxy::FThirdPersonAnimInstanceProxy(UAnimInstance* InAnimInstance,TSharedPtr<UThirdPersonAnimInstance> InThirdPersonAnimInstance)
: FAnimInstanceProxy(InAnimInstance)//, ThirdPersonAnimInstance(InThirdPersonAnimInstance)

{
	// Initialize default values for AnimationData
	AnimationData.MovementSpeed = 0.0f;
	AnimationData.bIsJumping = false;
}


bool FThirdPersonAnimInstanceProxy::Evaluate(FPoseContext& Output)
{
	// Lock the critical section for safe data access
	FScopeLock Lock(&CriticalSection);
	
	//Program Logic Base on the Anim Data



	// Let the base FAnimInstanceProxy handle the rest of the animation evaluation
	return FAnimInstanceProxy::Evaluate(Output);
}

void FThirdPersonAnimInstanceProxy::UpdateAnimationData(const FAnimationData& NewAnimationData)
{
	// Update the AnimationData with the provided data from the anim instance
	AnimationData = NewAnimationData;
}
