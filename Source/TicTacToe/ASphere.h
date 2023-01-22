// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "ASphere.generated.h"

class UMaterial;

UCLASS()
class TICTACTOE_API AASphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AASphere();

	UPROPERTY(EditAnywhere)
	UMaterial* StartColor;

	UPROPERTY(EditAnywhere)
	UMaterial* Player1;

	UPROPERTY(EditAnywhere)
	UMaterial* Player2;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	enum STATE { EMPTY, PLAYER_1, PLAYER_2 };
	
	void SetState(STATE InState);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetScale(float Scale);

	STATE GetState();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	STATE State = EMPTY;

	void UpdateMaterialFromState();

	

};
