// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NetBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Net/UnrealNetwork.h"
#include "NetAvatar.generated.h"

/**
 * 
 */
UCLASS()
class ANetAvatar : public ANetBaseCharacter
{
	GENERATED_BODY()

public:

	ANetAvatar();

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WalkingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RunningSpeed;

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = UpdateMovementParams)
	bool bIsRunning;

private:

	void MoveForward(float Amount);
	void MoveRight(float Amount);

	void RunPressed();
	void RunReleased();

	UFUNCTION()
	void UpdateMovementParams();
};
