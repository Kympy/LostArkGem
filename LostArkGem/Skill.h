#pragma once
#include <iostream>
#include "SkillData.h"
#include "M_SkillData.h"
using namespace std;
// 스킬 구조체
struct Skill {
	// 스킬 이름
	string name;
	// 스킬의 열거형 이름
	SkillType typeName;
	// 강화 시도 결과를 저장 (총 10번)
	int craft[10];
	// 현재 강화 시도 횟수 -> craft 배열의 인덱스를 의미
	int index = 0;
	// 스킬의 레벨 (강화 성공 횟수)
	int level = 0;
	// 열거형을 받아 나머지 변수들을 초기화
	void Init(SkillType enumName)
	{
		typeName = enumName;
		name = SkillDictionary.at(typeName);

		for (int i = 0; i < 10; i++) {
			craft[i] = -1;
		}
	}
	// 감소형 스킬의 경우 감소 스킬의 열거형을 받아 초기화
	void Init(M_SkillType enumName) {

		name = M_SkillDictionary.at(enumName);

		for (int i = 0; i < 10; i++) {
			craft[i] = -1;
		}
	}
};