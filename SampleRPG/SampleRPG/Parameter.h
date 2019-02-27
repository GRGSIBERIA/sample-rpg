#pragma once
#include "AbilityScore.h"

namespace rpg::ability
{
	/**
	* アビリティのENUM型
	*/
	enum Ability
	{
		STR,
		CON,
		POW,
		DEX,
		APP,
		SIZ,
		INT,
		EDU,
		IDEA,
		LUCK,
		KNOW,
		SAN,
		HP,
		MP,
		DMGB,
		JOB,
		ZES,
		ANU,
		PRP
	};

	/**
	* パラメータ
	*/
	class Parameter
	{
		AbilityScore STR;
		AbilityScore CON;
		AbilityScore POW;
		AbilityScore DEX;
		AbilityScore APP;
		AbilityScore SIZ;
		AbilityScore INT;
		AbilityScore EDU;
		AbilityScore IDEA;
		AbilityScore LUCK;
		AbilityScore KNOW;
		AbilityScore SAN;
		AbilityScore HP;
		AbilityScore MP;
		AbilityScore DMGB;
		AbilityScore JOB;
		AbilityScore ZES;
		AbilityScore ANU;
		AbilityScore PRP;

		void Roll(AbilityScore& score, const int numDice, const int numFace, const int modify);

		void SetDependency(AbilityScore& score, const AbilityScore& source, const int magnitude);

		void DecideDamageBonus(AbilityScore& DMG, const AbilityScore& STR, const AbilityScore& SIZ);

		void DecideAnnualIncome(AbilityScore& ANU);

		void DecideHP(AbilityScore& HP, const AbilityScore& CON, const AbilityScore& SIZ);

	public:
		Parameter();

		virtual ~Parameter();

		void ForceRoll();

		void Update();
	};

}