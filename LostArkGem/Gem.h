#pragma once
#include <iostream>
#include <random>
#include "Skill.h"
using namespace std;

random_device rd;
mt19937_64 mersenne(rd());
uniform_int_distribution<int> randSkill(0, maxCount - 1);
uniform_int_distribution<int> randRank(0, 3);
// �����Ƽ ����
class Gem {
private:
	// ���� �̸�
	string name;
	// ���� 1
	Skill _01;
	// ���� 2
	Skill _02;
	// ���� ����
	Skill _03;
	// ������ �ִ� ��ȭ ���� Ƚ��
	int maxCraft;
	// ������ ���� ��ȭ ������
	int percent;
	// ����׿� : ������ ������ ��ȭ ������
	int lastPercent;
public:
	// �����ϰ� ��ų 3���� �����ϰ� ������ ��͵��� ����
	Gem(bool isTen) {
		percent = 75;
		lastPercent = 0;
		// 1�� ��ų �ʱ�ȭ
		int tempRand_1 = randSkill(mersenne);
		_01.Init((SkillType)tempRand_1);
		// 2�� ��ų �ʱ�ȭ -> 1�� ��ų�� �ߺ��� ���� �ʵ���
		int tempRand_2 = randSkill(mersenne);
		while (tempRand_1 == tempRand_2) {
			tempRand_2 = randSkill(mersenne);
		}
		_02.Init((SkillType)tempRand_2);
		// 3�� ��ų �ʱ�ȭ
		_03.Init((M_SkillType)randRank(mersenne));
		// ����� �� ���� ��û�� �ִٸ�, 10¥�� �� ����
		if (isTen == true) {
			name = "����� ����� ��";
			maxCraft = 10;
			return;
		}
		// �����ϰ� ���� ��͵��� �����Ѵ�.
		switch (randRank(mersenne)) {
		case 0: {
			name = "����� ����� ��";
			maxCraft = 7;
			break;
		}
		case 1: {
			name = "�پ ����� ��";
			maxCraft = 8;
			break;
		}
		case 2: {
			name = "������ ����� ��";
			maxCraft = 9;
			break;
		}
		case 3: {
			name = "����� ����� ��";
			maxCraft = 10;
			break;
		}
		default: {
			name = "�̸��� ���� �� ��";
			maxCraft = 10;
			break;
		}
		}
	}
	// ��ȭ ����� ���޹޾� �ڱ� �ڽſ��� �ݿ��Ѵ�.
	void CraftResult(int skillNumber, bool isSuccess) {
		if (skillNumber == 1) {
			if (isSuccess) {
				_01.craft[_01.index] = 1;
				SetPercent(-10);
				_01.level++;
			}
			else {
				_01.craft[_01.index] = 0;
				SetPercent(10);
			}
			_01.index++;
		}
		else if(skillNumber == 2) {
			if (isSuccess) {
				_02.craft[_02.index] = 1;
				SetPercent(-10);
				_02.level++;
			}
			else {
				_02.craft[_02.index] = 0;
				SetPercent(10);
			}
			_02.index++;
		}
		else {
			if (isSuccess) {
				_03.craft[_03.index] = 1;
				SetPercent(-10);
				_03.level++;
			}
			else {
				_03.craft[_03.index] = 0;
				SetPercent(+10);
			}
			_03.index++;
		}
	}
	// ���� ��ȭ �������� �ʱ�ȭ�Ѵ�.
	void SetPercent(int value) {
		lastPercent = percent;
		percent += value;
		if (percent < 25) {
			percent = 25;
		}
		else if (percent > 75) {
			percent = 75;
		}
	}
	string GetName() {
		return name;
	}
	Skill GetSkill(int index) {
		if (index == 1) {
			return _01;
		}
		else if(index == 2) {
			return _02;
		}
		else {
			return _03;
		}
	}
	int GetMax() {
		return maxCraft;
	}
	int GetPercent() {
		return percent;
	}
	int GetLast() {
		return lastPercent;
	}
};