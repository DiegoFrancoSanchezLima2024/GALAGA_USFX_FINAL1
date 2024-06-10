// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaNodrizaBuqe.generated.h"


/**
 *
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaNodrizaBuqe : public ANaveEnemigaNodriza
{
	GENERATED_BODY()
public:
	virtual void Mover(float DeltaTime) override;
	virtual void Atacar() override;
	virtual void Destruir() override;
	virtual void Escapar() override;

};