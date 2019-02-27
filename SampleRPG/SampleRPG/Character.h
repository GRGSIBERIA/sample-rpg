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
}