// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "MenuSystem/MenuWidget.h"
#include "GameMenu.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API UGameMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:

	virtual bool Initialize();
private:

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UFUNCTION()
	void CancelPressed();

	UFUNCTION()
	void QuitPressed();
	
};
