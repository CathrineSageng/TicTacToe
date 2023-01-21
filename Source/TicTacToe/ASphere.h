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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	void SetMaterial(UMaterial* Material) {
		Mesh->SetMaterial(0, Material);
	}

	void SetScale(float Scale)
	{
		SetActorScale3D(FVector(Scale, Scale, Scale));
	}
	
};
