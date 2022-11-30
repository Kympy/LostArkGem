#pragma once
#include <iostream>
#include <map>
using namespace std;

const enum class M_SkillType {
	Attack, Armor, Move, DPS,
};

const map<M_SkillType, string> M_SkillDictionary = {
	{ M_SkillType::Attack, "공격력 감소" },
	{ M_SkillType::Armor, "방어력 감소" },
	{ M_SkillType::Move, "이동 속도 감소" },
	{ M_SkillType::DPS, "공격 속도 감소" },
};
