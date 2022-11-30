#pragma once
#include <iostream>
#include "SkillData.h"
#include "M_SkillData.h"
using namespace std;

struct Skill {
	string name;
	SkillType typeName;
	int craft[10];
	int index = 0;
	int level = 0;
	void Init(SkillType enumName)
	{
		typeName = enumName;
		name = SkillDictionary.at(typeName);

		for (int i = 0; i < 10; i++) {
			craft[i] = -1;
		}
	}
	void Init(M_SkillType enumName) {

		name = M_SkillDictionary.at(enumName);

		for (int i = 0; i < 10; i++) {
			craft[i] = -1;
		}
	}
};