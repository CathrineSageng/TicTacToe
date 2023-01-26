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
	SpringArm->TargetArmLength = 2000.f;
	SpringArm->SetRelativeRotation(FRotator(-70.f, 0.f, 0.f));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APTicTacToe::BeginPlay()
{
	
	Super::BeginPlay();

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Spheres[i][j] = GetWorld()->SpawnActor<AASphere>(BP_Sphere_Class, FVector(i * 360, j * 360, 160), FRotator(0,0,0));
		}		
	}

	ResultSphere1 = GetWorld()->SpawnActor<AASphere>(BP_Sphere_Class, FVector(360,1200, 150), FRotator(0, 0, 0));
	ResultSphere2 = GetWorld()->SpawnActor<AASphere>(BP_Sphere_Class, FVector(360, 1520, 150), FRotator(0, 0, 0));

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

	DECLARE_DELEGATE_TwoParams(ChangeColorForSphere, const int, const int);
	PlayerInputComponent->BindAction<ChangeColorForSphere>("ChangeColor1", IE_Pressed, this, &APTicTacToe::ChangeColor, 0, 0);
	PlayerInputComponent->BindAction<ChangeColorForSphere>("ChangeColor2", IE_Pressed, this, &APTicTacToe::ChangeColor, 0, 1);
	PlayerInputComponent->BindAction<ChangeColorForSphere>("ChangeColor3", IE_Pressed, this, &APTicTacToe::ChangeColor, 0, 2);
	PlayerInputComponent->BindAction<ChangeColorForSphere>("ChangeColor4", IE_Pressed, this, &APTicTacToe::ChangeColor, 1, 0);
	PlayerInputComponent->BindAction<ChangeColorForSphere>("ChangeColor5", IE_Pressed, this, &APTicTacToe::ChangeColor, 1, 1);
	PlayerInputComponent->BindAction<ChangeColorForSphere>("ChangeColor6", IE_Pressed, this, &APTicTacToe::ChangeColor, 1, 2);
	PlayerInputComponent->BindAction<ChangeColorForSphere>("ChangeColor7", IE_Pressed, this, &APTicTacToe::ChangeColor, 2, 0);
	PlayerInputComponent->BindAction<ChangeColorForSphere>("ChangeColor8", IE_Pressed, this, &APTicTacToe::ChangeColor, 2, 1);
	PlayerInputComponent->BindAction<ChangeColorForSphere>("ChangeColor9", IE_Pressed, this, &APTicTacToe::ChangeColor, 2, 2);

}

void APTicTacToe::ChangeColor(int row, int column)
{
	if (IsGameOver == false)
	{
		if (IsPlayer1)
		{
			Spheres[row][column]->SetState(AASphere::PLAYER_1);
			IsPlayer1 = false;
			CheckSate();
			CheckDrawn();
		}
		else
		{
			Spheres[row][column]->SetState(AASphere::PLAYER_2);
			IsPlayer1 = true;
			CheckSate();
			CheckDrawn();
		}
	}
}

void APTicTacToe::CheckSate()
{
	if (Spheres[0][0]->GetState() == Spheres[0][1]->GetState()
		&& Spheres[0][1]->GetState() == Spheres[0][2]->GetState() && Spheres[0][0]->GetState() != AASphere::EMPTY)
	{
		ResultSphere1->SetState(Spheres[0][0]->GetState());
		ResultSphere2->SetState(Spheres[0][0]->GetState());
		IsGameOver = true;
	}
	else if (Spheres[1][0]->GetState() == Spheres[1][1]->GetState()
		&& Spheres[1][1]->GetState() == Spheres[1][2]->GetState() && Spheres[1][0]->GetState() != AASphere::EMPTY)
	{
		ResultSphere1->SetState(Spheres[1][0]->GetState());
		ResultSphere2->SetState(Spheres[1][0]->GetState());
		IsGameOver = true;
	}
	else if (Spheres[2][0]->GetState() == Spheres[2][1]->GetState()
		&& Spheres[2][1]->GetState() == Spheres[2][2]->GetState() && Spheres[2][0]->GetState() != AASphere::EMPTY)
	{
		ResultSphere1->SetState(Spheres[2][0]->GetState());
		ResultSphere2->SetState(Spheres[2][0]->GetState());
		IsGameOver = true;
	}
	else if (Spheres[0][0]->GetState() == Spheres[1][0]->GetState()
		&& Spheres[1][0]->GetState() == Spheres[2][0]->GetState() && Spheres[0][0]->GetState() != AASphere::EMPTY)
	{
		ResultSphere1->SetState(Spheres[0][0]->GetState());
		ResultSphere2->SetState(Spheres[0][0]->GetState());
		IsGameOver = true;
	}
	else if (Spheres[0][1]->GetState() == Spheres[1][1]->GetState()
		&& Spheres[1][1]->GetState() == Spheres[2][1]->GetState() && Spheres[0][1]->GetState() != AASphere::EMPTY)
	{
		ResultSphere1->SetState(Spheres[0][1]->GetState());
		ResultSphere2->SetState(Spheres[0][1]->GetState());
		IsGameOver = true;
	}
	else if (Spheres[0][2]->GetState() == Spheres[1][2]->GetState()
		&& Spheres[1][2]->GetState() == Spheres[2][2]->GetState() && Spheres[0][2]->GetState() != AASphere::EMPTY)
	{
		ResultSphere1->SetState(Spheres[0][2]->GetState());
		ResultSphere2->SetState(Spheres[0][2]->GetState());
		IsGameOver = true;
	}
	else if (Spheres[0][0]->GetState() == Spheres[1][1]->GetState()
		&& Spheres[1][1]->GetState() == Spheres[2][2]->GetState() && Spheres[0][0]->GetState() != AASphere::EMPTY)
	{
		ResultSphere1->SetState(Spheres[0][0]->GetState());
		ResultSphere2->SetState(Spheres[0][0]->GetState());
		IsGameOver = true;
	}
	else if (Spheres[0][2]->GetState() == Spheres[1][1]->GetState()
		&& Spheres[1][1]->GetState() == Spheres[2][0]->GetState() && Spheres[0][2]->GetState() != AASphere::EMPTY)
	{
		ResultSphere1->SetState(Spheres[0][2]->GetState());
		ResultSphere2->SetState(Spheres[0][2]->GetState());
		IsGameOver = true;
	}


}

void APTicTacToe::CheckDrawn()
{
	if(Spheres[0][0]-> GetState() != AASphere::EMPTY && Spheres[0][1]->GetState() != AASphere::EMPTY && Spheres[0][2]->GetState() != AASphere::EMPTY
		&& Spheres[1][0]->GetState() != AASphere::EMPTY && Spheres[1][1]->GetState() != AASphere::EMPTY && Spheres[1][2]->GetState() != AASphere::EMPTY
		&& Spheres[2][0]->GetState() != AASphere::EMPTY && Spheres[2][1]->GetState() != AASphere::EMPTY && Spheres[2][2]->GetState() != AASphere::EMPTY)
	{
		ResultSphere1->SetState(AASphere::PLAYER_1);
		ResultSphere2->SetState(AASphere::PLAYER_2);
		IsGameOver = true;
	}
}



