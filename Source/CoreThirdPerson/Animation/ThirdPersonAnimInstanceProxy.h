#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstanceProxy.h"
#include "Templates/SharedPointer.h"
#include "ThirdPersonAnimInstanceProxy.generated.h"

struct FAnimationData;
class UThirdPersonAnimInstance;

// Create a custom AnimInstanceProxy struct
USTRUCT()
struct CORETHIRDPERSON_API FThirdPersonAnimInstanceProxy : public FAnimInstanceProxy
{
	GENERATED_BODY()

public:
	// Constructor
	FThirdPersonAnimInstanceProxy();
	FThirdPersonAnimInstanceProxy(UAnimInstance* InAnimInstance, TSharedPtr<UThirdPersonAnimInstance> InThirdPersonAnimInstance); // Updated parameter type


	//Actual function to calculate the character data
	virtual bool Evaluate(FPoseContext& Output) override;

	void UpdateAnimationData(const FAnimationData& NewAnimationData);

	// Override the FAnimInstanceProxy functions if needed
	// For example, you can override Update, GatherBonesToUpdate, etc.

	protected:
	
	// Animation data that can be accessed from the rendering thread
	FAnimationData AnimationData;


	// Reference to the owning UMyAnimInstance
	UPROPERTY()
	//UThirdPersonAnimInstance*ThirdPersonAnimInstance;
	UThirdPersonAnimInstance* ThirdPersonAnimInstance;
	
	// Critical section for synchronization
	FCriticalSection CriticalSection;
};