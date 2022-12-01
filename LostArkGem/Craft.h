#pragma once
#include <iostream>
#include "Gem.h"
using namespace std;
// ���� �ý���
class Craft {
private:
	Gem* currentGem; // ���� ������ ����
	string path = "GemData_"; // ������ ���� ���ϸ�
	void SetColor(int index); // ��� �ؽ�Ʈ ���� ���� �Լ�
public:
	Craft();
	~Craft();
	// ���� �õ�
	void TryCraft(int index);
	// ���ο� ���� ����
	void NewGem(bool isTen);
	// ��� ���
	void Print(bool getInput);
	// �޴� �Է�
	void Input();
	// ���� ���� �ڵ� ����
	void AutoCraft();
	// 1000���� ���� �ڵ� ����
	void Auto1000(int count);
	// ���� ��� ���� �Լ�
	void SaveData();
};