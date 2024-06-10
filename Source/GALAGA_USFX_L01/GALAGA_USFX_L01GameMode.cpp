// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_L01GameMode.h"
#include "GALAGA_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaCazaTipo1.h"
#include "NaveEnemigaCazaTipo2.h"
#include "InventoryActor.h"


AGALAGA_USFX_L01GameMode::AGALAGA_USFX_L01GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGALAGA_USFX_L01Pawn::StaticClass();
	//NaveEnemiga01 = nullptr;
}

void AGALAGA_USFX_L01GameMode::SpawnNaveEnemiga(FString NaveTypeName, FVector SpawnLocation, FRotator SpawnRotation)
{
	// Lógica para spawnear la nave enemiga
	if (NaveTypeName.Equals("NaveEspia"))
	{
		GetWorld()->SpawnActor<ANaveEnemigaCaza>(SpawnLocation, SpawnRotation);
	}
	else if (NaveTypeName.Equals("NaveCaza"))
	{
		GetWorld()->SpawnActor<ANaveEnemigaNodriza>(SpawnLocation, SpawnRotation);
	}
}

void AGALAGA_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();
	//Set the game state to playing
	FVector ubicacionInicioNavesEnemigasCaza = FVector(1600.0f, -530.0f, 215.0f);
	FVector ubicacionInicioNavesEnemigasTransporte = FVector(500.0f, 500.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasEspia = FVector(1875.0f,-540.0f, 214.0f);
	FVector ubicacionInicioNavesEnemigasNodriza = FVector(1645.0f, -534.0f, 214.0f);
	FVector ubicacionInicioNavesEnemigasReabastecimiento = FVector(1400.0f, 500.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasCazaTipo1 = FVector(1774.463989f, -1851.308716f, 214.727936f);
	FVector ubicacionInicioNavesEnemigasCazaTipo2 = FVector(1550.0f, -530.0f, 215.0f);
	FVector ubicacionInventoryActor = FVector(0.0f, 0.0f, 250.0f);


	//NaveEnemiga01->GetVelocidad();
	//NaveEnemiga01->SetVelocidad(5.0f);

	//FVector ubicacionNave01 = FVector(-1000.0f, 500.0f, 250.0f);
	//FVector ubicacionNave02 = FVector(-500.0f, -500.0f, 250.0f);

	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	int contador= 0;

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		for (contador ; contador < 5; contador++) {

			FVector PosicionNaveActual = FVector( ubicacionInicioNavesEnemigasCaza.X , ubicacionInicioNavesEnemigasCaza.Y+ contador*400 , ubicacionInicioNavesEnemigasCaza.Z );
			
			ANaveEnemigaCaza* NaveEnemigaCazaTemporal = World->SpawnActor<ANaveEnemigaCaza>(PosicionNaveActual, rotacionNave);

			//TANavesEnemigasCaza.Push(NaveEnemigaCazaTemporal);
			TANavesEnemigas.Push(NaveEnemigaCazaTemporal);
		}

		float nuevaposicionX = ubicacionInicioNavesEnemigasTransporte.X - 300.0f;

		for (int j = 0; j < 5; j++) {
			FVector PosicionNaveActual = FVector(nuevaposicionX, ubicacionInicioNavesEnemigasTransporte.Y + j * 400, ubicacionInicioNavesEnemigasTransporte.Z);
			ANaveEnemigaTransporte* NaveEnemigaTransporteTemporal = World->SpawnActor<ANaveEnemigaTransporte>(PosicionNaveActual, rotacionNave);

			//TANavesEnemigasTransporte.Push(NaveEnemigaTransporteTemporal);
			TANavesEnemigas.Push(NaveEnemigaTransporteTemporal);
		}

		for (int k = 0; k < 5; k++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasEspia.X, ubicacionInicioNavesEnemigasEspia.Y + k * 300, ubicacionInicioNavesEnemigasEspia.Z);
			ANaveEnemigaEspia* NaveEnemigaEspiaTemporal = World->SpawnActor<ANaveEnemigaEspia>(PosicionNaveActual, rotacionNave);
			
			//TANavesEnemigasEspia.Push(NaveEnemigaEspiaTemporal);
			TANavesEnemigas.Push(NaveEnemigaEspiaTemporal);
		}
		for (int l = 0; l < 5; l++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasNodriza.X, ubicacionInicioNavesEnemigasNodriza.Y + l * 300, ubicacionInicioNavesEnemigasNodriza.Z);
			ANaveEnemigaNodriza* NaveEnemigaNodrizaTemporal = World->SpawnActor<ANaveEnemigaNodriza>(PosicionNaveActual, rotacionNave);

			//TANavesEnemigasNodriza.Push(NaveEnemigaNodrizaTemporal);
			TANavesEnemigas.Push(NaveEnemigaNodrizaTemporal);
		}

		for (int m = 0; m < 5; m++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasReabastecimiento.X, ubicacionInicioNavesEnemigasReabastecimiento.Y + m * 300, ubicacionInicioNavesEnemigasReabastecimiento.Z);
			ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimientoTemporal = World->SpawnActor<ANaveEnemigaReabastecimiento>(PosicionNaveActual, rotacionNave);

			//TANavesEnemigasReabastecimiento.Push(NaveEnemigaReabastecimientoTemporal);
			TANavesEnemigas.Push(NaveEnemigaReabastecimientoTemporal);
		}
		for (int n = 0; n < 5; n++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasCazaTipo1.X, ubicacionInicioNavesEnemigasCazaTipo1.Y + n * 300, ubicacionInicioNavesEnemigasCazaTipo1.Z);
			ANaveEnemigaCazaTipo1* NaveEnemigaCazaTipo1Temporal = World->SpawnActor<ANaveEnemigaCazaTipo1>(PosicionNaveActual, rotacionNave);

			//TANavesEnemigasCazaTipo1.Push(NaveEnemigaCazaTipo1Temporal);
			TANavesEnemigas.Push(NaveEnemigaCazaTipo1Temporal);
		}
		for (int o = 0; o < 5; o++) {
			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasCazaTipo2.X, ubicacionInicioNavesEnemigasCazaTipo2.Y + o * 300, ubicacionInicioNavesEnemigasCazaTipo2.Z);
			ANaveEnemigaCazaTipo2* NaveEnemigaCazaTipo2Temporal = World->SpawnActor<ANaveEnemigaCazaTipo2>(PosicionNaveActual, rotacionNave);

			//TANavesEnemigasCazaTipo2.Push(NaveEnemigaCazaTipo2Temporal);
			TANavesEnemigas.Push(NaveEnemigaCazaTipo2Temporal);
		}

		InventoryActor01= World->SpawnActor<AInventoryActor>(ubicacionInventoryActor, rotacionNave);
	
		


		//NaveEnemigaTransporte01 = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNave01, rotacionNave);
		//NaveEnemigaCaza01 = World->SpawnActor<ANaveEnemigaCaza>(ubicacionNave02, rotacionNave);

		TiempoTranscurrido = 0;
	}

	/*NaveEnemigaCaza01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f));
	NaveEnemigaTransporte01->SetPosicion(FVector(500.0f, -500.0f, 200.0f));*/

}
void AGALAGA_USFX_L01GameMode::Tick(float DeltaTime)
{
}
//void AGALAGA_USFX_L01GameMode::Tick(float DeltaTime)
//{
	//Super::Tick(DeltaTime);
	//TiempoTranscurrido++;

	//if (TiempoTranscurrido >= 100)
	//{
	//	int numeroEnemigo = FMath::RandRange(0, 9);
	//	if (GEngine)
	//	{
	//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Hola estoy aqui")));

	//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Entero: %d"), numeroEnemigo));

		//}
		//TANavesEnemigas[numeroEnemigo]->PrimaryActorTick.bCanEverTick = false;
	//	TANavesEnemigas[numeroEnemigo]->SetVelocidad(0);
//	}
//}
