// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActor.h"
#include "GALAGA_USFX_L01Pawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/CollisionProfile.h"


AInventoryActor::AInventoryActor()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> InventoryActor(TEXT("StaticMesh'/Game/TwinStick/Meshes/BulletAmmunition1.BulletAmmunition1'"));
	// Create the mesh component
	//InventoryActorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InventoryActor"));
	//InventoryActorMesh->SetupAttachment(RootComponent);
	//InventoryActorMesh->SetStaticMesh(InventoryActor.Object);
	
	RootComponent = InventoryActorMesh;


	if (InventoryActor.Object != nullptr)
	{
        GetStaticMeshComponent()->SetRelativeScale3D(FVector(3.5f, 3.5f, 2.5f));
		GetStaticMeshComponent()->SetRelativeRotation(FRotator(180.0f, 0.0f, 0.0f));
		GetStaticMeshComponent()->SetStaticMesh(InventoryActor.Object);
		GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
		

	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);

}



void AInventoryActor::PickUp()
{
	SetActorTickEnabled(false);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void AInventoryActor::PutDown(FTransform TargetLocation)
{
	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorLocation(TargetLocation.GetLocation());

	AGALAGA_USFX_L01Pawn* OwnerPawn = Cast<AGALAGA_USFX_L01Pawn>(GetOwner());

	if (OwnerPawn)
	{
		// Aumentar la velocidad del pawn en un 100%
		OwnerPawn->MoveSpeed *= 2;
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Velocidad aumentada a: %f"), OwnerPawn->MoveSpeed));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Propietario no encontrado"));
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se retiro del inventario")));

}
