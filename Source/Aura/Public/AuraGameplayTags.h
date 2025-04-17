// Copy Right Celil Bulut

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *  Aura GameplayTags
 *
 *  Singleton containing native Gameplay Tags
 */

struct FAuraGameplayTags
{
public:
	static const FAuraGameplayTags& Get() {return GameplayTags;}
	static void InitializeNativeGameplayTags();

	/*
	* Primary Attributes Tags
	*/
	FGameplayTag Attribute_Primary_Strength;
	FGameplayTag Attribute_Primary_Intelligence;
	FGameplayTag Attribute_Primary_Resilience;
	FGameplayTag Attribute_Primary_Vigor;

	/*
	* Secondary Attributes Tags
	*/
	FGameplayTag Attribute_Secondary_Armor;
	FGameplayTag Attribute_Secondary_ArmorPenetration;
	FGameplayTag Attribute_Secondary_BlockChance;
	FGameplayTag Attribute_Secondary_CriticalHitChance;
	FGameplayTag Attribute_Secondary_CriticalHitDamage;
	FGameplayTag Attribute_Secondary_CriticalHitResistance;
	FGameplayTag Attribute_Secondary_HealthRegeneration;
	FGameplayTag Attribute_Secondary_ManaRegeneration;
	FGameplayTag Attribute_Secondary_MaxHealth;
	FGameplayTag Attribute_Secondary_MaxMana;

	FGameplayTag InputTag_LMB;  //Left mouse buttonu icin key atadik
	FGameplayTag InputTag_RMB;	//Right mouse buttonu icin key atadik
	FGameplayTag InputTag_1;	//Her hangi bir key atadik
	FGameplayTag InputTag_2;	//Her hangi bir key atadik
	FGameplayTag InputTag_3;	//Her hangi bir key atadik
	FGameplayTag InputTag_4;	//Her hangi bir key atadik

	FGameplayTag Damage;

	FGameplayTag Effects_HitReact; //GE_HitReact
	
private:
	static FAuraGameplayTags GameplayTags;
};
