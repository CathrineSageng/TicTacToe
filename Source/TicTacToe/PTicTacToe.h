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

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AASphere> BP_Sphere_Class;

	AASphere* Spheres[3][3];
	AASphere* ResultSphere1;
	AASphere* ResultSphere2;

	void ChangeColor(int row, int column);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool IsPlayer1 = true;

	bool IsGameOver = false;

	void CheckSate();

	void CheckDrawn();

	

};
