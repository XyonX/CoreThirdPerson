#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstanceProxy.h"
#include "ThirdPersonAnimInstanceProxy.generated.h"

struct FAnimationData;
class UThirdPersonAnimInstance;

// Create a custom AnimInstanceProxy struct
USTRUCT()
struct CORETHIRDPERSON_API FThirdPersonAnimInstanceProxy : public FAnimInstanceProxy
{
	GENERATED_BODY()

public:
	/** Constructor */
	FThirdPersonAnimInstanceProxy();
	
	FThirdPersonAnimInstanceProxy(UThirdPersonAnimInstance* InThirdPersonAnimInstance);


	/**Actual function to calculate the character data */
	virtual bool Evaluate(FPoseContext& Output) override;

	//** Setter Function to set the Animation Data */
	void UpdateAnimationData(const FAnimationData& NewAnimationData);

	
protected:
	
	/** Animation data that can be accessed from the rendering thread */
	FAnimationData AnimationData;


	/** Reference to the owning UMyAnimInstance */
	UPROPERTY()
	UThirdPersonAnimInstance* ThirdPersonAnimInstance;
	
	/** Critical section for synchronization */
	//FCriticalSection CriticalSection;
	//FThreadSafeBool bIsUpdating;
	/** Critical section for synchronization */
	//mutable FCriticalSection CriticalSection;
};