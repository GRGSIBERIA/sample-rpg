#pragma once
#include <random>

namespace rpg::dice
{
	/**
	* サイコロクラス
	*/
	class Dice
	{
		const int numFace;
		int score;

		static std::random_device rnd;	//! 乱数生成
		static std::mt19937 mt;			//! メルセンヌ・ツイスタを使用する

	public:
		/**
		* ダイスインスタンス
		* @param numFace ダイスの目の数
		*/
		Dice(const int& numFace);
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
	};

	/**
	* 複数ダイスを投げるクラス
	*/
	class MultiDice
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
		MultiDice(const int& numDice, const int& numFace);
		~MultiDice();

		/**
		* すべてのダイスを投げる
		*/
		const int RollAll();
	};

	std::random_device Dice::rnd = std::random_device();
	std::mt19937 Dice::mt = std::mt19937(Dice::rnd());
}
