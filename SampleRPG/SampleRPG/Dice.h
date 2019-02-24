#pragma once
#include <random>
#include "IStringable.hpp"

namespace rpg::dice
{
	/**
	* サイコロクラス
	*/
	class Dice : public rpg::interface::IStringable
	{
		int numFace;
		int score;

		static std::random_device rnd;	//! 乱数生成
		static std::mt19937 mt;			//! メルセンヌ・ツイスタを使用する

	public:
		/**
		* ダイスインスタンス
		* @param numFace ダイスの目の数
		*/
		Dice(const int& numFace);
		Dice();
		virtual ~Dice();
		
		/**
		* ダイスを振る
		* @return ダイスの目
		*/
		const int Roll();

		/**
		* ダイスを振ったかどうか？
		* @return 振ったならtrue
		*/
		const bool IsRolled() const;

		const std::u32string ToString() const override;

		Dice& operator=(const Dice& dice);
	};

	/**
	* 複数ダイスを投げるクラス
	*/
	class DiceManager : public rpg::interface::IStringable
	{
		const int numDice;			//! ダイスの個数
		const int numFace;			//! ダイスの面数
		std::vector<Dice> dices;	//! ダイスインスタンス

	public:
		/**
		* 複数ダイスを管理するクラス
		* @param numDice ダイスの個数
		* @param numFace ダイスの面数
		*/
		DiceManager(const int& numDice, const int& numFace);
		~DiceManager();

		/**
		* すべてのダイスを投げる
		*/
		int RollAll();

		const std::u32string ToString() const override;
	};

	std::random_device Dice::rnd = std::random_device();
	std::mt19937 Dice::mt = std::mt19937(Dice::rnd());
}
