#include "Parameter.h"
using namespace rpg::ability;


void rpg::ability::Parameter::Roll(AbilityScore & score, const int numDice, const int numFace, const int modify)
{
	rpg::dice::DiceManager dices(numDice, numFace);
	score.Score(dices.RollAll() + modify);
}

void rpg::ability::Parameter::SetDependency(AbilityScore & score, const AbilityScore & source, const int magnitude)
{
	score.Score(source.Value() * magnitude);
}

Parameter::Parameter()
	: 
	STR(U"筋力"),
	CON(U"頑健さ"),
	POW(U"精神力"),
	DEX(U"敏捷性"),
	APP(U"外見"),
	SIZ(U"体格"),
	INT(U"知力"),
	EDU(U"教育"),
	IDEA(U"発想力"),
	LUCK(U"幸運"),
	KNOW(U"知識"),
	SAN(U"SAN値"),
	HP(U"耐久力"),
	MP(U"魔力"),
	DMGB(U"ダメボ"),
	JOB(U"職業P"),
	ZES(U"興味P"),
	ANU(U"年収"),
	PRP(U"財産")
{
}

void Parameter::DecideDamageBonus(AbilityScore& DMG, const AbilityScore& STR, const AbilityScore& SIZ)
{
	const int score = STR.Score() + SIZ.Score();
	int value = 0;

	if (score <= 12)
		value = -rpg::dice::DiceManager(1, 6).RollAll();
	else if (score <= 16)
		value = rpg::dice::DiceManager(1, 4).RollAll();
	else if (score <= 24)
		value = 0;
	else if (score <= 32)
		value = rpg::dice::DiceManager(1, 4).RollAll();
	else
		value = rpg::dice::DiceManager((score / 16) - 1, 6).RollAll();

	DMG.Score(value);
}

void Parameter::DecideAnnualIncome(AbilityScore& ANU)
{
	int score = rpg::dice::DiceManager(3, 6).RollAll();
	int value;

	if (score <= 10)
		value = (score - 3) * 500000 + 150000;
	else if (score <= 15)
		value = (score - 3) * 1000000 + 1000000;
	else if (score == 16)
		value = 20000000;
	else if (score == 17)
		value = 30000000;
	else if (score >= 18)
		value = 50000000;

	ANU.Score(value);
}

void rpg::ability::Parameter::DecideHP(AbilityScore & HP, const AbilityScore & CON, const AbilityScore & SIZ)
{
	HP.Score(CON.Score() + SIZ.Score() >> 1);
}

Parameter::~Parameter()
{
}

void rpg::ability::Parameter::ForceRoll()
{
	Roll(STR, 3, 6, 0);
	Roll(CON, 3, 6, 0);
	Roll(POW, 3, 6, 0);
	Roll(DEX, 3, 6, 0);
	Roll(APP, 3, 6, 0);
	Roll(SIZ, 2, 6, 6);
	Roll(INT, 2, 6, 6);
	Roll(EDU, 3, 6, 3);
	
	SetDependency(SAN, POW, 5);
	SetDependency(MP, POW, 1);
	SetDependency(JOB, EDU, 20);
	SetDependency(ZES, INT, 10);

	DecideAnnualIncome(ANU);
	SetDependency(PRP, ANU, 5);

	DecideHP(HP, CON, SIZ);

	Update();	// 最後に残りの依存パラメータを更新する
}

void rpg::ability::Parameter::Update()
{
	SetDependency(IDEA, INT, 5);
	SetDependency(LUCK, POW, 5);
	SetDependency(KNOW, EDU, 5);

	DecideDamageBonus(DMGB, STR, SIZ);
}
