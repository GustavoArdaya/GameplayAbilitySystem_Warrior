// Gustavo Ardaya


#include "DataAssets/StartupData/DataAsset_HeroStartupData.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"

void UDataAsset_HeroStartupData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
    Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

    for (const FWarriorHeroAbilitySet& AbilitySet : HeroStartupAbilitySets)
    {
        if (!AbilitySet.IsValid()) continue;

        FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
        AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
        AbilitySpec.Level = ApplyLevel;
        AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

        InASCToGive->GiveAbility(AbilitySpec);
    }
}
