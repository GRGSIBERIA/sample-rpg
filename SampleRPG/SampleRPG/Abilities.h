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
		NAME(const int _score) : AbilityScore(_score) {}\
		virtual ~NAME() {}\
		const std::u32string ToString() const override { return TO_STR;}\
	}

	DEFINE_ABILITY(STR, U"筋力");
	DEFINE_ABILITY(CON, U"頑健さ");
	DEFINE_ABILITY(POW, U"精神力");
	DEFINE_ABILITY(DEX, U"敏捷性");
	DEFINE_ABILITY(APP, U"外見");
	DEFINE_ABILITY(SIZ, U"体格");
	DEFINE_ABILITY(INT, U"知力");
	DEFINE_ABILITY(EDU, U"教育");
	DEFINE_ABILITY(IDE, U"アイデア");
	DEFINE_ABILITY(LCK, U"幸運");
	DEFINE_ABILITY(KNW, U"知識");
	DEFINE_ABILITY(SAN, U"SAN値");
	DEFINE_ABILITY(END, U"耐久力");
	DEFINE_ABILITY(MGP, U"魔力");
	DEFINE_ABILITY(DMG, U"ダメージボーナス");
	DEFINE_ABILITY(JOB, U"職業ポイント");
	DEFINE_ABILITY(FSC, U"興味ポイント");
	DEFINE_ABILITY(ANU, U"年収");
	DEFINE_ABILITY(PRP, U"財産");

}