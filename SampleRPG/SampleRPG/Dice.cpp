#include "Dice.h"
using namespace rpg::dice;

std::random_device Dice::rnd = std::random_device();
std::mt19937 Dice::mt = std::mt19937(Dice::rnd());

rpg::dice::Dice::Dice(const int numFace)
	: numFace(numFace), score(0)
{

}

const int rpg::dice::Dice::Roll()
{
	std::uniform_int_distribution<> randomDist(1, numFace);
	score = randomDist(mt);
	return score;
}

const bool rpg::dice::Dice::IsRolled() const
{
	return score > 0;
}

const std::u32string& rpg::dice::Dice::ToString() const
{
	const auto str = std::to_string(score);
	return std::u32string(str.cbegin(), str.cend());
}

Dice & rpg::dice::Dice::operator=(const Dice & dice)
{
	score = dice.score;
	numFace = dice.numFace;
	return *this;
}

Dice::~Dice()
{
}

rpg::dice::DiceManager::DiceManager(const int numDice, const int numFace)
	: numDice(numDice), numFace(numFace), total(0)
{
	dices = std::vector<Dice>();
	for (size_t i = 0; i < numDice; ++i)
		dices.emplace_back(numFace);
}

rpg::dice::DiceManager::~DiceManager()
{
}

int rpg::dice::DiceManager::RollAll()
{
	total = 0;

	for (size_t i = 0; i < dices.size(); ++i)
	{
		total += dices[i].Roll();
	}

	return total;
}

const std::u32string& rpg::dice::DiceManager::ToString() const
{
	const std::string str = std::to_string(numDice) + "d" + std::to_string(numFace);
	return std::u32string(str.cbegin(), str.cend());
}
