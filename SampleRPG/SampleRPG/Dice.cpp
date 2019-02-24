#include "Dice.h"
using namespace rpg::dice;

rpg::dice::Dice::Dice(const int & numFace)
	: numFace(numFace), score(0)
{

}

const int rpg::dice::Dice::Roll()
{
	std::uniform_int_distribution<> randomDist(1, numFace);
	score = randomDist(mt);
	return std::lroundf(score);
}

const bool rpg::dice::Dice::IsRolled() const
{
	return score > 0;
}

Dice::~Dice()
{
}

rpg::dice::MultiDice::MultiDice(const int & numDice, const int & numFace)
	: numDice(numDice), numFace(numFace)
{
	dices = std::vector<Dice>(numDice);
}

rpg::dice::MultiDice::~MultiDice()
{
}

const int rpg::dice::MultiDice::RollAll()
{
	int total = 0;

	for each (auto& dice in dices)
	{
		total += dice.Roll();
	}

	return total;
}
