#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayerVisibilityLibrary.generated.h"

/**
 * Blueprint Function Library for managing player-specific actor visibility
 */
UCLASS()
class BUSSTOP_API UPlayerVisibilityLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     * Hide an actor from the specified player controller's view
     * The actor will still be visible in Scene Captures
     */
    UFUNCTION(BlueprintCallable, Category = "Player Visibility")
    static void HideActorFromPlayer(APlayerController* PlayerController, AActor* ActorToHide);

    /**
     * Unhide a previously hidden actor from the player controller's view
     */
    UFUNCTION(BlueprintCallable, Category = "Player Visibility")
    static void UnhideActorFromPlayer(APlayerController* PlayerController, AActor* ActorToUnhide);

    /**
     * Check if an actor is currently hidden from the player controller
     */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Player Visibility")
    static bool IsActorHiddenFromPlayer(APlayerController* PlayerController, AActor* ActorToCheck);

    /**
     * Clear all hidden actors from the player controller
     */
    UFUNCTION(BlueprintCallable, Category = "Player Visibility")
    static void ClearAllHiddenActors(APlayerController* PlayerController);
};