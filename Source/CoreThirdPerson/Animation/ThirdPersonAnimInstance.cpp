/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/


#include "ThirdPersonAnimInstance.h"
#include "ThirdPersonAnimInstanceProxy.h"
#include "CorePlugin/Helpers/DelegateHelper.h"

UThirdPersonAnimInstance::UThirdPersonAnimInstance()
: AnimationData() // Initializes the AnimationData struct with default values (e.g., 0.0f and false)

{
	DefaultAnimationData.Velocity=400;
	DefaultAnimationData.bIsJumping=false;
	
	// Initialize default values for AnimationData
	AnimationData=DefaultAnimationData;
}

void UThirdPersonAnimInstance::NativeInitializeAnimation()
{
	
	Proxy = MakeShared<FThirdPersonAnimInstanceProxy>(this);
	// Send a reference of the anim data to the proxy class
	Proxy->UpdateAnimationData(AnimationData);

	ADelegateHelper::Transmitter_AnimationData.AddDynamic(this,&UThirdPersonAnimInstance::Receiver_AnimationData);
	
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

