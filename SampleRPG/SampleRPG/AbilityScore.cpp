#include "AbilityScore.h"
#include <cmath>
using namespace rpg::ability;

AbilityScore::AbilityScore()
	: score(0.f), modify(0.f), vary(0.f)
{
}

rpg::ability::AbilityScore::AbilityScore(const int _modify)
	: score(0.f), modify((float)_modify), vary(0.f)
{
}


AbilityScore::~AbilityScore()
{
}

const int AbilityScore::Value() const
{
	return std::lroundf(score + vary + modify);
}

void AbilityScore::Score(const int _score)
{
	this->score = (float)_score;
}

void AbilityScore::Modify(const int _modify)
{
	this->modify = (float)_modify;
}

void AbilityScore::Vary(const int _vary)
{
	this->vary = (float)_vary;
}

int AbilityScore::Score() const
{
	return (int)score;
}

int AbilityScore::Modify() const
{
	return (int)modify;
}

int AbilityScore::Vary() const
{
	return (int)vary;
}

rpg::ability::DicedAbility::DicedAbility(const int numDice, const int numFace)
	: AbilityScore(), dices(numDice, numFace)
{
}

rpg::ability::DicedAbility::DicedAbility(const int numDice, const int numFace, const int modify)
	: AbilityScore(modify), dices(numDice, numFace)
{
}

const rpg::dice::DiceManager & rpg::ability::DicedAbility::Roll()
{
	dices.RollAll();
	return dices;
}
