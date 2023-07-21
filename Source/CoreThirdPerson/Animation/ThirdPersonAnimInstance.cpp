// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonAnimInstance.h"

#include "CorePlugin/Helpers/DelegateHelper.h"

UThirdPersonAnimInstance::UThirdPersonAnimInstance()
: AnimationData() // Initializes the AnimationData struct with default values (e.g., 0.0f and false)

{
	// Initialize default values for AnimationData
	AnimationData.MovementSpeed = 0.0f;
	AnimationData.bIsJumping = false;
}

void UThirdPersonAnimInstance::NativeInitializeAnimation()
{
	// Create the custom proxy and pass a shared pointer to this UThirdPersonAnimInstance
	//Proxy = MakeShared<FThirdPersonAnimInstanceProxy>(this,MakeShared<UThirdPersonAnimInstance>(this) /*shared ref of this class*/);
	// Send a reference of the anim data to the proxy class
	//Proxy->UpdateAnimationData(AnimationData);

	ADelegateHelper::Delegate_UpdateAnimationDataDelegate.AddDynamic(this,&UThirdPersonAnimInstance::Receiver_AnimationData);
}

void UThirdPersonAnimInstance::Receiver_AnimationData(FAnimationData InAnimData)
{
	
}


//Updated the anim data In the Animation instance class
void UThirdPersonAnimInstance::UpdateAnimationData(FAnimationData InAnimationData)
{
	AnimationData=InAnimationData;
}



// Add more functions and logic for other animation calculations if needed

