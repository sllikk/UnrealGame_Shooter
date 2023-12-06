// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHero.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Windows/AllowWindowsPlatformTypes.h"


// Sets default values
AMyHero::AMyHero()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set default values for running
	WalkingSpeed = 300.0f;
	RunningSpeed = 600.0f;
	blsRunning = false;
	
}

// Called when the game starts or when spawned
void AMyHero::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AMyHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PrimaryActorTick.bCanEverTick = true;
	
}

// Called to bind functionality to input
void AMyHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// entering keys for movement
	PlayerInputComponent->BindAxis("MoveForward",this, &AMyHero::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyHero::MoveRight);
	// entering keys for jump
	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &AMyHero::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyHero::StopJumping);
	// entering keys for run
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyHero::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMyHero::StopSprint);
}
// initial input Keys
void AMyHero::MoveForward(float Value) 
{
const FVector ForwardVector = GetActorForwardVector();
 AddMovementInput(ForwardVector,Value);
}

void AMyHero::MoveRight(float Value) 
{
const FVector RightVector = GetActorRightVector();
AddMovementInput(RightVector,Value);
}

void AMyHero::Jump()
{
	Super::Jump();

}

void AMyHero::StopJumping()
{
	Super::StopJumping();

}

void AMyHero::Sprint()
{
	blsRunning = true;
	GetCharacterMovement()-> MaxWalkSpeed = RunningSpeed;  
	
}


void AMyHero::StopSprint()
{
	blsRunning = false;
	GetCharacterMovement()-> MaxWalkSpeed = WalkingSpeed;
	
}






