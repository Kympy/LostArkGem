#include <iostream>
#include <Windows.h>
#include "Craft.h"
#include "ColorText.h"
#include "fstream"
#include <string>
using namespace std;

uniform_int_distribution<int> randPercent(0, 100);
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
	uniform_int_distribution<int> randSave(10000, 99999);
	path.append(to_string(randSave(mersenne)));
	path.append(".csv");
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
	if (currentGem != nullptr) {
		delete currentGem;
	}
	currentGem = tempGem;
}
void Craft::TryCraft(int index) {
	if (currentGem == nullptr) {
		return;
	}
	if (currentGem->GetSkill(index).index == currentGem->GetMax()) {
		return;
	}
	currentPercent = randPercent(mersenne);
	if (currentPercent <= currentGem->GetPercent()) {
		currentGem->CraftResult(index, true);
	}
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
	case 0: {
		exit(0);
		return;
	}
	case 1: {
		TryCraft(1);
		break;
	}
	case 2: {
		TryCraft(2);
		break;
	}
	case 3: {
		TryCraft(3);
		break;
	}
	case 4: {
		NewGem(true);
		break;
	}
	case 5: {
		NewGem(true);
		AutoCraft();
		break;
	}
	case 6: {
		Auto1000(1000);
		Sleep(1000);
		break;
	}
	default: {
		break;
	}
	}
	Print(true);
}
void Craft::AutoCraft() {
	if (currentGem == nullptr) {
		return;
	}
	if (currentGem->GetSkill(1).index == currentGem->GetMax() &&
		currentGem->GetSkill(2).index == currentGem->GetMax() &&
		currentGem->GetSkill(3).index == currentGem->GetMax()) {
		SaveData();
		return;
	}
	uniform_int_distribution<int> randIndex(1, 2);
	if (currentGem->GetPercent() >= 55) {
		if (currentGem->GetSkill(1).index == currentGem->GetMax() &&
			currentGem->GetSkill(2).index == currentGem->GetMax()) {
			TryCraft(3);
		}
		else if (currentGem->GetSkill(1).index == currentGem->GetMax() &&
			currentGem->GetSkill(2).index != currentGem->GetMax()) {
			TryCraft(2);
		}
		else if (currentGem->GetSkill(1).index != currentGem->GetMax() &&
			currentGem->GetSkill(2).index == currentGem->GetMax()) {
			TryCraft(1);
		}
		else {
			if (randIndex(mersenne) == 1) {
				TryCraft(1);
			}
			else {
				TryCraft(2);
			}
		}
	}
	else {
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
	AutoCraft();
}
void Craft::Auto1000(int count) {
	if (count == 0) {
		return;
	}
	NewGem(true);
	AutoCraft();
	Auto1000(count - 1);
}
int saveCount = 1;
void Craft::SaveData() {
	fstream file;
	int plus = 0;
	cout << "[" << saveCount << "] Saving Data...";
	file.open(path, ios::app);
	if (file.is_open()) {
		plus += currentGem->GetSkill(1).level;
		file.write(to_string(currentGem->GetSkill(1).level).c_str(), 2);
		file.write(",", 1);
		plus += currentGem->GetSkill(2).level;
		file.write(to_string(currentGem->GetSkill(2).level).c_str(), 2);
		file.write(",", 1);
		file.write(to_string(currentGem->GetSkill(3).level).c_str(), 2);
		file.write(",", 1);
		file.write(to_string(plus).c_str(), 2);
		file.write(",", 1);
		if (plus >= 14 && currentGem->GetSkill(3).level < 5) {
			file.write("SAFE\n", 5);
		}
		else {
			file.write("----\n", 5);
		}
		file.close();
		cout << "Success!" << endl;
		saveCount++;
	}
	else {
		cout << "Failed to open file." << endl;
	}
}
