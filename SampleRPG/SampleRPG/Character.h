#pragma once
#include <memory>
#include "Parameter.h"

namespace rpg::character
{
	class Character
	{
		rpg::ability::Parameter parameter;

	public:
		Character();
		virtual ~Character();
	};

	class CharacterGenerator
	{
	public:
		template <class CHAR = rpg::character::Character>
		static std::shared_ptr<CHAR> Generate();
	};
}

template <class CHAR>
std::shared_ptr<CHAR> rpg::character::CharacterGenerator::Generate()
{
	std::shared_ptr<CHAR> ptr(new CHAR());
	return ptr;
}