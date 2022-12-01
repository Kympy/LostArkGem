#pragma once
#include <iostream>
#include <random>
#include "Skill.h"
using namespace std;

random_device rd;
mt19937_64 mersenne(rd());
uniform_int_distribution<int> randSkill(0, maxCount - 1);
uniform_int_distribution<int> randRank(0, 3);
// 어빌리티 스톤
class Gem {
private:
	// 스톤 이름
	string name;
	// 각인 1
	Skill _01;
	// 각인 2
	Skill _02;
	// 감소 각인
	Skill _03;
	// 스톤의 최대 강화 가능 횟수
	int maxCraft;
	// 스톤의 현재 강화 성공률
	int percent;
	// 디버그용 : 스톤의 마지막 강화 성공률
	int lastPercent;
public:
	// 랜덤하게 스킬 3개를 결정하고 스톤의 희귀도를 결정
	Gem(bool isTen) {
		percent = 75;
		lastPercent = 0;
		// 1번 스킬 초기화
		int tempRand_1 = randSkill(mersenne);
		_01.Init((SkillType)tempRand_1);
		// 2번 스킬 초기화 -> 1번 스킬과 중복이 되지 않도록
		int tempRand_2 = randSkill(mersenne);
		while (tempRand_1 == tempRand_2) {
			tempRand_2 = randSkill(mersenne);
		}
		_02.Init((SkillType)tempRand_2);
		// 3번 스킬 초기화
		_03.Init((M_SkillType)randRank(mersenne));
		// 고고한 돌 생성 요청이 있다면, 10짜리 돌 생성
		if (isTen == true) {
			name = "고고한 비상의 돌";
			maxCraft = 10;
			return;
		}
		// 랜덤하게 돌의 희귀도를 결정한다.
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
	// 강화 결과를 전달받아 자기 자신에게 반영한다.
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
	// 현재 강화 성공률을 초기화한다.
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