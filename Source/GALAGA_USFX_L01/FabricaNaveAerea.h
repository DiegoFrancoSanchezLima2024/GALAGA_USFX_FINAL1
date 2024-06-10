// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CreaciondeNaves.h"
#include "FabricaNaveAerea.generated.h"

UCLASS()
class GALAGA_USFX_L01_API AFabricaNaveAerea : public ACreaciondeNaves
{
	GENERATED_BODY()
	

public:
	virtual ANaveEnemiga* MakeNave(FString TypeNave)override;
};
