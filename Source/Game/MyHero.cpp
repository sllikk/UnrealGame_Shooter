// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHero.h"

// Sets default values
AMyHero::AMyHero()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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






