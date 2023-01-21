// Fill out your copyright notice in the Description page of Project Settings.


#include "PTicTacToe.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


APTicTacToe::APTicTacToe()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Springarm"));
	SpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APTicTacToe::BeginPlay()
{
	SpringArm->TargetArmLength = 2000.f;
	SpringArm->SetRelativeRotation(FRotator(-70.f, 0.f, 0.f));

	Super::BeginPlay();

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			testSphere[i][j] = GetWorld()->SpawnActor<AASphere>(BP_Sphere_Class, FVector(i * 360, j * 360, 160), FRotator(0,0,0));
		}		
	}

	testSphere[0][0]->SetMaterial(Player1);
	testSphere[1][1]->SetMaterial(Player2);
	testSphere[0][0]->SetScale(0.5f);
	testSphere[0][2]->SetScale(1.4f);

}

// Called every frame
void APTicTacToe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APTicTacToe::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

