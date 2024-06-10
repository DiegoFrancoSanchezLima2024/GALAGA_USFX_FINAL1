// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaNaveTerrestre.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaNodriza.h"


//ANaveEnemiga* AFabricaNaveTerrestre::MakeNave(FString NaveTypeName)
//{
//    // Genera una posición de spawn aleatoria
//    float RandomSpawnX = FMath::RandRange(-1820, 1770);
//    const FVector SpawnLocation = FVector(1770.0f, RandomSpawnX, 210.0f);
//    const FRotator Rotation = FRotator(0.f, 0.f, 0.f);
//
//    if (NaveTypeName.Equals("Nave_Caza"))
//        return GetWorld()->SpawnActor<ANaveEnemigaCaza>(SpawnLocation, Rotation);
//
//    else if (NaveTypeName.Equals("Nave_Nodriza"))
//        return GetWorld()->SpawnActor<ANaveEnemigaNodriza>(SpawnLocation, Rotation);
//    // Si no coincide con ningún tipo de nave conocido, devolver nullptr
//    else return nullptr;
//}