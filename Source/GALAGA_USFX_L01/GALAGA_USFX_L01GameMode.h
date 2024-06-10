// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GALAGA_USFX_L01GameMode.generated.h"


class ANaveEnemiga;
class ANaveEnemigaCaza;
class ANaveEnemigaTransporte;
class ANaveEnemigaEspia;
class ANaveEnemigaNodriza;
class ANaveEnemigaReabastecimiento;
class ANaveEnemigaCazaTipo1;
class ANaveEnemigaCazaTipo2;
class AInventoryActor;


UCLASS(MinimalAPI)
class AGALAGA_USFX_L01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGALAGA_USFX_L01GameMode();

	void SpawnNaveEnemiga(FString NaveTypeName, FVector SpawnLocation, FRotator SpawnRotation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	TArray<ANaveEnemiga*> TANavesEnemigas;
	TArray<ANaveEnemigaCaza*> TANavesEnemigasCaza;
	TArray<ANaveEnemigaTransporte*> TANavesEnemigasTransporte;
	TArray<ANaveEnemigaEspia*> TANavesEnemigasEspia;
	TArray<ANaveEnemigaNodriza*> TANavesEnemigasNodriza;
	TArray<ANaveEnemigaReabastecimiento*> TANavesEnemigasReabastecimiento;
	TArray<ANaveEnemigaCazaTipo1*> TANavesEnemigasCazaTipo1;
	TArray<ANaveEnemigaCazaTipo2*> TANavesEnemigasCazaTipo2;

	TMap<FString, ANaveEnemiga*>TMapCambiarVelocidad;


	//un TMap nos sirve para diferenciar diferentes tipos de naves;
public:
	ANaveEnemiga* NaveEnemiga01;
	ANaveEnemigaCaza* NaveEnemigaCaza01;
	ANaveEnemigaCaza* NaveEnemigaCaza02;
	ANaveEnemigaTransporte* NaveEnemigaTransporte01;
	ANaveEnemigaTransporte* NaveEnemigaTransporte02;
	ANaveEnemigaEspia* NaveEnemigaEspia01;
	ANaveEnemigaNodriza* NaveEnemigaNodriza01;
	ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimiento01;
	/*ANaveEnemigaCazaTipo1* NaveEnemigaCazaTipo01;*/
	ANaveEnemigaCazaTipo2* NaveEnemigaCazaTipo02;
	AInventoryActor* InventoryActor01;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	int TiempoTranscurrido;
	
};




