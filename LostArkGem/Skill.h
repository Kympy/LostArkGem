#pragma once
#include <iostream>
#include "SkillData.h"
#include "M_SkillData.h"
using namespace std;
// ��ų ����ü
struct Skill {
	// ��ų �̸�
	string name;
	// ��ų�� ������ �̸�
	SkillType typeName;
	// ��ȭ �õ� ����� ���� (�� 10��)
	int craft[10];
	// ���� ��ȭ �õ� Ƚ�� -> craft �迭�� �ε����� �ǹ�
	int index = 0;
	// ��ų�� ���� (��ȭ ���� Ƚ��)
	int level = 0;
	// �������� �޾� ������ �������� �ʱ�ȭ
	void Init(SkillType enumName)
	{
		typeName = enumName;
		name = SkillDictionary.at(typeName);

		for (int i = 0; i < 10; i++) {
			craft[i] = -1;
		}
	}
	// ������ ��ų�� ��� ���� ��ų�� �������� �޾� �ʱ�ȭ
	void Init(M_SkillType enumName) {

		name = M_SkillDictionary.at(enumName);

		for (int i = 0; i < 10; i++) {
			craft[i] = -1;
		}
	}
};