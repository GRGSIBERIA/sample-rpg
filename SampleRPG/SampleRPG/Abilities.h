#pragma once
#include "AbilityScore.h"
#include "IStringable.hpp"
using namespace rpg::interface;

namespace rpg::ability
{
#define DEFINE_ABILITY(NAME, TO_STR) \
	class NAME : public AbilityScore, public IStringable \
	{\
	public:\
		NAME() : AbilityScore() {}\
		virtual ~NAME() {}\
		const std::u32string ToString() const override { return TO_STR;}\
	}

#define DEFINE_DABILITY(NAME, TO_STR, ND, NF, MOD) \
	class NAME : public DicedAbility, public IStringable \
	{\
	public:\
		NAME() : DicedAbility(ND, NF, MOD) {}\
		virtual ~NAME() {}\
		const std::u32string ToString() const override { return TO_STR;}\
	}

	DEFINE_DABILITY(STR, U"筋力", 3, 6, 0);
	DEFINE_DABILITY(CON, U"頑健さ", 3, 6, 0);
	DEFINE_DABILITY(POW, U"精神力", 3, 6, 0);
	DEFINE_DABILITY(DEX, U"敏捷性", 3, 6, 0);
	DEFINE_DABILITY(APP, U"外見", 3, 6, 0);
	DEFINE_DABILITY(SIZ, U"体格", 2, 6, 6);
	DEFINE_DABILITY(INT, U"知力", 2, 6, 6);
	DEFINE_DABILITY(EDU, U"教育", 3, 6, 3);
	DEFINE_ABILITY (IDE, U"アイデア");
	DEFINE_ABILITY (LCK, U"幸運");
	DEFINE_ABILITY (KNW, U"知識");
	DEFINE_ABILITY (SAN, U"SAN値");
	DEFINE_ABILITY (END, U"耐久力");
	DEFINE_ABILITY (MGP, U"魔力");
	DEFINE_ABILITY (DMG, U"ダメージボーナス");
	DEFINE_ABILITY (JOB, U"職業ポイント");
	DEFINE_ABILITY (FSC, U"興味ポイント");
	DEFINE_ABILITY (ANU, U"年収");
	DEFINE_ABILITY (PRP, U"財産");

}