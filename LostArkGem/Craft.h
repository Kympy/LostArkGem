#pragma once
#include <iostream>
#include "Gem.h"
using namespace std;

class Craft {
private:
	Gem* currentGem;
	string path = "GemData_";
	void SetColor(int index);
public:
	Craft();
	~Craft();
	void TryCraft(int index);
	void NewGem(bool isTen);
	void Print(bool getInput);
	void Input();
	void AutoCraft();
	void Auto1000(int count);
	void SaveData();
};