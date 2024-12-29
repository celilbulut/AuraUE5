// Copy Right Celil Bulut


#include "AbilitySystem/ModMagCalc/MMC_MaxMana.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	IntelligentDef.AttributeToCapture = UAuraAttributeSet::GetIntelligenceAttribute();
	IntelligentDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntelligentDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(IntelligentDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// Gater tags from source and target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = SourceTags;
	EvaluateParameters.TargetTags = TargetTags;

	float IntValue = 0.f;
	GetCapturedAttributeMagnitude(IntelligentDef, Spec, EvaluateParameters, IntValue);
	IntValue = FMath::Max<float>(IntValue, 0.0f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	return 50.f + 2.5f * IntValue + 15.f * PlayerLevel;
	// Suan ki degerler 50 + 2.5 * 17 + 15 * 1 = 107.5
}
