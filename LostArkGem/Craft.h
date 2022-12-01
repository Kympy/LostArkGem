#pragma once
#include <iostream>
#include "Gem.h"
using namespace std;
// 세공 시스템
class Craft {
private:
	Gem* currentGem; // 현재 세공할 스톤
	string path = "GemData_"; // 데이터 저장 파일명
	void SetColor(int index); // 출력 텍스트 색상 조정 함수
public:
	Craft();
	~Craft();
	// 세공 시도
	void TryCraft(int index);
	// 새로운 스톤 생성
	void NewGem(bool isTen);
	// 결과 출력
	void Print(bool getInput);
	// 메뉴 입력
	void Input();
	// 현재 스톤 자동 세공
	void AutoCraft();
	// 1000개의 스톤 자동 세공
	void Auto1000(int count);
	// 세공 결과 저장 함수
	void SaveData();
};