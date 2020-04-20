// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
    GENERATED_BODY()

    public:
    virtual void BeginPlay() override;
    virtual void OnInput(const FString& Input) override;

    // Your declarations go below!
    private:
    const int32 MIN_WORD_SIZE = 4;
    const int32 MAX_WORD_SIZE = 8;
    TArray<FString> Isograms;
    FString HiddenWord;
    int32 Lives;
    bool bIsGameOver;

    void InitGame();
    FString GetHiddenWord() const;
    TArray<FString> GetValidWords(const TArray<FString>& WordList) const;
    void PrintWelcomeMessage() const;
    void ProcessGuess(const FString& Guess);
    bool IsIsogram(const FString& Word) const;
    void EndGame();
    FBullCowCount GetBullCowCount(const FString& Guess) const;
};
