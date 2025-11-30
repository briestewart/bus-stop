#include "PlayerVisibilityLibrary.h"
#include "GameFramework/PlayerController.h"

void UPlayerVisibilityLibrary::HideActorFromPlayer(APlayerController* PlayerController, AActor* ActorToHide)
{
    if (PlayerController && ActorToHide)
    {
        PlayerController->HiddenActors.AddUnique(ActorToHide);
    }
}

void UPlayerVisibilityLibrary::UnhideActorFromPlayer(APlayerController* PlayerController, AActor* ActorToUnhide)
{
    if (PlayerController && ActorToUnhide)
    {
        PlayerController->HiddenActors.Remove(ActorToUnhide);
    }
}

bool UPlayerVisibilityLibrary::IsActorHiddenFromPlayer(APlayerController* PlayerController, AActor* ActorToCheck)
{
    if (PlayerController && ActorToCheck)
    {
        return PlayerController->HiddenActors.Contains(ActorToCheck);
    }
    return false;
}

void UPlayerVisibilityLibrary::ClearAllHiddenActors(APlayerController* PlayerController)
{
    if (PlayerController)
    {
        PlayerController->HiddenActors.Empty();
    }
}