#pragma once
#include <string>

namespace rpg::interface
{
	class IStringable
	{
	public:
		virtual const std::u32string& ToString() const = 0;
		virtual ~IStringable() {}
	};
};