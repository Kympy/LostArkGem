#pragma once
#include <iostream>
#include "Gem.h"
using namespace std;

class Craft {
private:
	Gem* currentGem;
	void SetColor(int index);
public:
	Craft();
	~Craft();
	void TryCraft(int index);
	void NewGem();
	void Print();
	void Input();
};