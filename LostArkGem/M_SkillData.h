#pragma once
#include <iostream>
#include <map>
using namespace std;

const enum class M_SkillType {
	Attack, Armor, Move, DPS,
};

const map<M_SkillType, string> M_SkillDictionary = {
	{ M_SkillType::Attack, "���ݷ� ����" },
	{ M_SkillType::Armor, "���� ����" },
	{ M_SkillType::Move, "�̵� �ӵ� ����" },
	{ M_SkillType::DPS, "���� �ӵ� ����" },
};
