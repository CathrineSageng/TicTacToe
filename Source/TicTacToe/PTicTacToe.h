// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ASphere.h"
#include "PTicTacToe.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UMaterial;

UCLASS()
class TICTACTOE_API APTicTacToe : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APTicTacToe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	UMaterial* StartColor;

	UPROPERTY(EditAnywhere)
	UMaterial* Player1;

	UPROPERTY(EditAnywhere)
	UMaterial* Player2;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AASphere> BP_Sphere_Class;

	AASphere* testSphere[3][3];

};