#pragma once
#include "Abilities.h"

namespace rpg::ability
{
	class Parameter
	{
		STR _str; CON _con;	POW _pow; DEX _dex; APP _app; 
		SIZ _siz; INT _int; EDU _edu; IDE _ide; LCK _lck; 
		KNW _knw; SAN _san; END _end; MGP _mgp;	DMG _dwg; 
		JOB _job; FSC _fsc; ANU _anu; PRP _prp;

	public:
		Parameter();
		virtual ~Parameter();

		void ForceRoll();
	};

}