#include "AbilityScore.h"
#include <cmath>
using namespace rpg::ability;

rpg::ability::AbilityScore::AbilityScore(const std::u32string & name)
	: score(0), modify(0), vary(0), name(name)
{
}

rpg::ability::AbilityScore::AbilityScore(const std::u32string & name, int score, int modify, int vary)
	: score(score), modify(modify), vary(vary), name(name)
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
	this->score = _score;
}

void AbilityScore::Modify(const int _modify)
{
	this->modify = _modify;
}

void AbilityScore::Vary(const int _vary)
{
	this->vary = _vary;
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

const std::u32string & rpg::ability::AbilityScore::ToString() const
{
	return name;
}

AbilityScore rpg::ability::AbilityScore::operator+(const AbilityScore & rhs)
{
	return AbilityScore(name, score, modify + rhs.score, vary);
}
