#pragma once
#include <iostream>
#include <random>
#include "Skill.h"
using namespace std;

random_device rd;
mt19937_64 mersenne(rd());
uniform_int_distribution<int> randSkill(0, maxCount - 1);
uniform_int_distribution<int> randRank(0, 3);

class Gem {
private:
	string name;
	Skill _01;
	Skill _02;
	Skill _03;
	int maxCraft;
	int percent;
	int lastPercent;
public:
	Gem(bool isTen) {
		percent = 75;
		lastPercent = 0;
		int tempRand_1 = randSkill(mersenne);
		_01.Init((SkillType)tempRand_1);
		int tempRand_2 = randSkill(mersenne);
		while (tempRand_1 == tempRand_2) {
			tempRand_2 = randSkill(mersenne);
		}
		_02.Init((SkillType)tempRand_2);
		_03.Init((M_SkillType)randRank(mersenne));

		if (isTen == true) {
			name = "고고한 비상의 돌";
			maxCraft = 10;
			return;
		}
		switch (randRank(mersenne)) {
		case 0: {
			name = "희귀한 비상의 돌";
			maxCraft = 7;
			break;
		}
		case 1: {
			name = "뛰어난 비상의 돌";
			maxCraft = 8;
			break;
		}
		case 2: {
			name = "강력한 비상의 돌";
			maxCraft = 9;
			break;
		}
		case 3: {
			name = "고고한 비상의 돌";
			maxCraft = 10;
			break;
		}
		default: {
			name = "이름이 에러 난 돌";
			maxCraft = 10;
			break;
		}
		}
	}
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