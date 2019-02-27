#pragma once
#include "Dice.h"
#include "IStringable.hpp"

namespace rpg::ability
{
	/**
	* 能力値クラス
	*/
	class AbilityScore : public rpg::interface::IStringable
	{
	protected:
		const std::u32string name;	// アビリティ名

		int score;	//! 能力値
		int modify;	//! 修正値
		int vary;	//! 増減値

	public:
		AbilityScore(const std::u32string& name);

		AbilityScore(const std::u32string& name, int score, int modify, int vary);

		virtual ~AbilityScore();

		/**
		* 正味の能力値を得る
		* @return 正味の能力値
		*/
		const int Value() const;

		/**
		* 能力値を設定
		*/
		void Score(const int _score);

		/**
		* 修正値を設定
		*/
		void Modify(const int _modify);

		/**
		* 増減値を設定
		*/
		void Vary(const int _vary);

		/**
		* 能力値を取得
		*/
		int Score() const;

		/**
		* 修正値を取得
		*/
		int Modify() const;

		/**
		* 増減値を取得
		*/
		int Vary() const;

		const std::u32string& ToString() const override;

		/**
		* 修正値を右辺から足す
		*/
		AbilityScore operator+(const AbilityScore& rhs);
	};
}