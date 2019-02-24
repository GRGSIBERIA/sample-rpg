#pragma once

namespace rpg
{
	/**
	* 能力値
	*/
	class AbilityScore
	{
		float score;	//! 能力値
		float modify;	//! 修正値
		float vary;		//! 増減値

	public:
		AbilityScore();
		virtual ~AbilityScore();

		/**
		* 正味の能力値を得る
		* @return 正味の能力値
		*/
		const int GetValue() const;
	};
}