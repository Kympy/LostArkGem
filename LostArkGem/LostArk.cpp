#include <iostream>
#include <Windows.h>
#include "Craft.h"
#include "ColorText.h"
using namespace std;

uniform_int_distribution<int> randPercent(0, 100);

int main() {
	system("tiTle 로스트아크 세공 프로그램");
	Craft* craft = new Craft();
	craft->Print();
	delete craft;
	return 0;
}

Craft::Craft() {
	currentGem = nullptr;
	cout << "Craft System Enabled" << endl;
	Sleep(1000);
}
Craft::~Craft() {
	delete currentGem;
	cout << "Craft System Disabled" << endl;
}
void Craft::NewGem() {
	Gem* tempGem = new Gem();
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
	if (randPercent(mersenne) <= currentGem->GetPercent()) {
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
void Craft::Print() {
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
		cout << "\t\t\t●" << endl;
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
	cout << "1. 각인(1) 강화  2. 각인(2) 강화  3. 감소 각인 강화" << endl;
	cout << "4. 새로운 돌 생성  0. 프로그램 종료" << endl;
	Input();
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
		NewGem();
		break;
	}
	default: {
		break;
	}
	}
	Print();
}
