// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"


void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/Nodriza1.Nodriza1'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
	velocidad = 600;

	SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));

	SetActorRelativeScale3D(FVector(0.8f, 0.8f, 0.8f));

	Nombre_Nave = "NaveTransporte";

}

void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	// Obtiene la posici�n actual del actor
	FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float NuevaX =-velocidad * DeltaTime;
	float NuevaY = 0;
	float NuevaZ = 0;

	// Crea un nuevo vector de posici�n con las coordenadas aleatorias y la misma Z que la posici�n actual
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z + NuevaZ);

	// Establece la nueva posici�n del actor
	SetActorLocation(NuevaPosicion);
	if (NuevaPosicion.X < limiteInferiorX)
	{
		SetActorLocation(FVector(500.0f, NuevaPosicion.Y, NuevaPosicion.Z));
	}
}