#pragma once

namespace rpg::ability
{
	/**
	* 能力値クラス
	*/
	class AbilityScore
	{
		float score;	//! 能力値
		float modify;	//! 修正値
		float vary;		//! 増減値

	public:
		AbilityScore(const int _score);
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
	};
}