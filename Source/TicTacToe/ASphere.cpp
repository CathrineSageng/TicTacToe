// Fill out your copyright notice in the Description page of Project Settings.

#include "ASphere.h"

// Sets default values
AASphere::AASphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AASphere::BeginPlay()
{
	Super::BeginPlay();
	
}

void AASphere::SetState(STATE InState)
{
	if (State==EMPTY) 
	{
		State = InState;
		UpdateMaterialFromState();
	}
}

// Called every frame
void AASphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AASphere::SetScale(float Scale)
{
	SetActorScale3D(FVector(Scale, Scale, Scale));
}

AASphere::STATE AASphere::GetState()
{
	return State;
}

void AASphere::UpdateMaterialFromState()
{
	Mesh->SetMaterial(0, StartColor);

	if (State == PLAYER_1) 
	{
		Mesh->SetMaterial(0, Player1);
	}
	else if (State == PLAYER_2)
	{
		Mesh->SetMaterial(0, Player2);
	}
}



