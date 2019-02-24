#include "AbilityScore.h"
using namespace rpg;

AbilityScore::AbilityScore()
	: score(0.f), modify(0.f), vary(0.f)
{
}


AbilityScore::~AbilityScore()
{
}

const int rpg::AbilityScore::GetValue() const
{
	return score + vary + modify;
}
