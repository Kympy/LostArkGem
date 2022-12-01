#include <iostream>
#include <Windows.h>
#include "Craft.h"
#include "ColorText.h"
#include "fstream"
#include <string>
using namespace std;

uniform_int_distribution<int> randPercent(0, 99);
// Debug
int currentPercent;

int main() {
	system("title 로스트아크 세공 프로그램");
	Craft* craft = new Craft();
	craft->Print(true);
	delete craft;
	return 0;
}

Craft::Craft() {
	// 저장할 파일명에 추가할 랜덤한 5자리 번호
	uniform_int_distribution<int> randSave(10000, 99999);
	// GemData_13542.csv 형태로 저장됨
	path.append(to_string(randSave(mersenne)));
	path.append(".csv");
	// 현재 세공 스톤 초기화
	currentGem = nullptr;
	cout << "Craft System Enabled" << endl;
	Sleep(1000);
}
Craft::~Craft() {
	delete currentGem;
	cout << "Craft System Disabled" << endl;
}
void Craft::NewGem(bool isTen) {
	Gem* tempGem = new Gem(isTen);
	// 이미 세공 중이던 스톤이 있다면 삭제
	if (currentGem != nullptr) {
		delete currentGem;
	}
	// 새로운 스톤 할당
	currentGem = tempGem;
}
void Craft::TryCraft(int index) {
	// 스톤이 존재하지 않는다면 종료
	if (currentGem == nullptr) {
		return;
	}
	// 세공하고자 하는 스킬이 최대 강화 단계라면 종료
	if (currentGem->GetSkill(index).index == currentGem->GetMax()) {
		return;
	}
	// 0 ~ 99 까지 랜덤한 난수를 뽑는다. (정수)
	currentPercent = randPercent(mersenne);
	// 뽑은 수가 스톤의 현재 세공 성공률 보다 작다면 -> 강화 성공
	if (currentPercent <= currentGem->GetPercent()) {
		currentGem->CraftResult(index, true);
	}
	// 강화 실패
	else {
		currentGem->CraftResult(index, false);
	}
}
void Craft::SetColor(int index) {
	for (int i = 0; i < currentGem->GetMax(); i++) {
		if (currentGem->GetSkill(index).craft[i] == 1) {
			TextColor(Color::BLUE);
			if (index == 3) {
				TextColor(Color::RED);
			}
			cout << "◆ ";
		}
		else if (currentGem->GetSkill(index).craft[i] == 0) {
			TextColor(Color::DARKGRAY);
			if (index == 3) {
				TextColor(Color::DARKGRAY);
			}
			cout << "◆ ";
		}
		else {
			TextColor(Color::LIGHTBLUE);
			if (index == 3) {
				TextColor(Color::RED);
			}
			cout << "◇ ";
		}
		TextColor(Color::WHITE);
	}
}
void Craft::Print(bool getInput) {
	system("CLS");
	cout << "\t---- 로스트아크 세공 시스템 ----" << endl;
	cout << endl;
	if (currentGem == nullptr) {
		cout << "\t새로운 돌을 생성하세요" << endl;
		cout << "\t--------------------------------" << endl;
		cout << endl << endl;
		cout << "\t\t\t○" << endl;
		cout << endl;
		cout << "\t증가 각인\t\t+75%" << endl;
		cout << "\t--------------------------------" << endl;
		cout << "\t스킬 1" << endl;
		cout << "\t\t◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ " << "+0" << endl;
		cout << "\t스킬 2" << endl;
		cout << "\t\t◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ " << "+0" << endl;
		cout << "\t--------------------------------" << endl;
		cout << "\t감소 각인\t\t+75%" << endl;
		cout << "\t--------------------------------" << endl;
		cout << "\t스킬 3" << endl;
		cout << "\t\t◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ ◇ " << "+0" << endl;
		cout << "\t--------------------------------" << endl;
	}
	else {
		cout << "\t" << currentGem->GetName() << endl;
		cout << "\t--------------------------------" << endl;
		cout << endl << endl;
		TextColor(Color::YELLOW);
		cout << "\t\t\t●" << "\tMy : " << currentPercent << " Cpu : " << currentGem->GetLast() << endl;
		TextColor(Color::WHITE);
		cout << endl;
		cout << "\t증가 각인\t\t+" << currentGem->GetPercent() << "%" << endl;
		cout << "\t--------------------------------" << endl;
		cout << "\t" << currentGem->GetSkill(1).name << endl;
		cout << "\t\t";
		SetColor(1);
		cout << "+" << currentGem->GetSkill(1).level << endl;
		cout << "\t" << currentGem->GetSkill(2).name << endl;
		cout << "\t\t";
		SetColor(2);
		cout << "+" << currentGem->GetSkill(2).level << endl;
		cout << "\t--------------------------------" << endl;
		cout << "\t감소 각인\t\t+" << currentGem->GetPercent() << "%" << endl;
		cout << "\t--------------------------------" << endl;
		cout << "\t" << currentGem->GetSkill(3).name << endl;
		cout << "\t\t";
		SetColor(3);
		cout << "+" << currentGem->GetSkill(3).level << endl;
		cout << "\t--------------------------------" << endl;
	}
	cout << "메뉴" << endl;
	cout << "(1) 각인1 강화  (2) 각인2 강화  (3) 감소 각인 강화" << endl;
	cout << "(4) 새로운 돌 생성  (5) 자동 강화  (6) 1000개 자동 강화 (0) 프로그램 종료" << endl;
	if (getInput) {
		Input();
	}
}
void Craft::Input() {
	int menu;
	cin >> menu;
	switch (menu) {
	case 0: { // 프로그램 종료
		exit(0);
		return;
	}
	case 1: { // 1번 세공
		TryCraft(1);
		break;
	}
	case 2: { // 2번 세공
		TryCraft(2);
		break;
	}
	case 3: { // 3번 세공
		TryCraft(3);
		break;
	}
	case 4: { // 새로운 스톤 생성
		NewGem(true);
		break;
	}
	case 5: { // 자동 강화
		NewGem(true);
		AutoCraft();
		break;
	}
	case 6: { // 1000 개 강화
		Auto1000(1000);
		Sleep(1000);
		break;
	}
	default: { // 재입력
		break;
	}
	}
	Print(true);
}
void Craft::AutoCraft() {
	// 세공할 스톤이 없다면 종료
	if (currentGem == nullptr) {
		return;
	}
	// 모든 스킬들이 최대 강화 단계라면 종료
	if (currentGem->GetSkill(1).index == currentGem->GetMax() &&
		currentGem->GetSkill(2).index == currentGem->GetMax() &&
		currentGem->GetSkill(3).index == currentGem->GetMax()) {
		// 세공 데이터 저장
		SaveData();
		return;
	}
	uniform_int_distribution<int> randIndex(1, 2);
	// 스톤의 성공률이 55% 이상이라면 1, 2 번 스킬 중 랜덤하게 선택
	if (currentGem->GetPercent() >= 55) {
		// 성공률이 55% 인데, 1, 2번 스킬이 최대 강화단계라면, 3번 스킬 선택
		if (currentGem->GetSkill(1).index == currentGem->GetMax() &&
			currentGem->GetSkill(2).index == currentGem->GetMax()) {
			TryCraft(3);
		}
		// 1번이 최대 상태라면, 2번 선택
		else if (currentGem->GetSkill(1).index == currentGem->GetMax() &&
			currentGem->GetSkill(2).index != currentGem->GetMax()) {
			TryCraft(2);
		}
		// 2번이 최대 상태라면, 1번 선택
		else if (currentGem->GetSkill(1).index != currentGem->GetMax() &&
			currentGem->GetSkill(2).index == currentGem->GetMax()) {
			TryCraft(1);
		}
		// 1, 2 번 모두 선택 가능하다면 50% 확률로 랜덤하게 결정
		else {
			if (randIndex(mersenne) == 1) {
				TryCraft(1);
			}
			else {
				TryCraft(2);
			}
		}
	}
	// 강화 성공률이 55% 미만이라면 3번 스킬 선택
	else {
		// 3번 스킬이 최대 상태라면, 1, 2번 중 랜덤하게 선택
		if (currentGem->GetSkill(3).index == currentGem->GetMax()) {		
			if (randIndex(mersenne) == 1) {
				TryCraft(1);
			}
			else {
				TryCraft(2);
			}
		}
		TryCraft(3);
	}
	// 세공이 끝날 때 까지 재귀 호출
	AutoCraft();
}
void Craft::Auto1000(int count) {
	// 1000개가 끝났다면 종료
	if (count == 0) {
		return;
	}
	// 새로운 10짜리 스톤 생성
	NewGem(true);
	// 자동 강화
	AutoCraft();
	// 재귀 호출
	Auto1000(count - 1);
}
// 데이터의 갯수를 세기 위한 변수
int saveCount = 1;
void Craft::SaveData() {
	fstream file;
	// 1번 스킬과 2번 스킬 레벨의 합을 저장할 변수
	int plus = 0;
	cout << "[" << saveCount << "] Saving Data...";
	// 쓰기 시작
	file.open(path, ios::app);
	if (file.is_open()) {
		// 1번 스킬 쓰기
		plus += currentGem->GetSkill(1).level;
		file.write(to_string(currentGem->GetSkill(1).level).c_str(), 2);
		file.write(",", 1);
		// 2번 스킬 쓰기
		plus += currentGem->GetSkill(2).level;
		file.write(to_string(currentGem->GetSkill(2).level).c_str(), 2);
		file.write(",", 1);
		// 3번 스킬 쓰기
		file.write(to_string(currentGem->GetSkill(3).level).c_str(), 2);
		file.write(",", 1);
		// 1 + 2 번 레벨 쓰기
		file.write(to_string(plus).c_str(), 2);
		file.write(",", 1);
		// 합이 14 이상의 유효한 스톤이라면 SAFE 표시
		if (plus >= 14 && currentGem->GetSkill(3).level < 5) {
			file.write("SAFE\n", 5);
		}
		else {
			file.write("----\n", 5);
		}
		// 쓰기 종료
		file.close();
		cout << "Success!" << endl;
		saveCount++;
	}
	else {
		cout << "Failed to open file." << endl;
	}
}
