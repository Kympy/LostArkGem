#pragma once
#include <iostream>
#include <map>
using namespace std;

const enum class SkillType {
	Wonhan, Barricade, Doctor, HeavyArmor,
	CriticalHit, Awakening, FHFW, Gravity,
	Beadsman, CursedDoll, Safe, MaxMana,
	Rocket, GhostMagic, PowerShield, Adrenaline,
	EdgeMace, BackAttack, HeadAttack, Absorb,
	EdgeKnife, FastFast, MastersPower, FocusOnMe,
	ManaFlow, Bombman, AngleBless, PowerFist,
	BrokenBone, Runner, Thunder, Bully,
	StrongMind, BreakShield,
};

const map<SkillType, string> SkillDictionary = {
	{ SkillType::Wonhan, "����" },
	{ SkillType::Barricade, "�ٸ����̵�" },
	{ SkillType::Doctor, "������" },
	{ SkillType::HeavyArmor, "�߰� ����" },
	{ SkillType::CriticalHit, "�޼� Ÿ��" },
	{ SkillType::Awakening, "����" },
	{ SkillType::FHFW, "�����ʽ�" },
	{ SkillType::Gravity, "���� ����" },
	{ SkillType::Beadsman, "��������" },
	{ SkillType::CursedDoll, "���ֹ��� ����" },
	{ SkillType::Safe, "���� ���" },
	{ SkillType::MaxMana, "�ִ� ���� ����" },
	{ SkillType::Rocket, "������" },
	{ SkillType::GhostMagic, "���ɼ�" },
	{ SkillType::PowerShield, "��ȭ ����" },
	{ SkillType::Adrenaline, "�Ƶ巹����" },
	{ SkillType::EdgeMace, "������ �б�" },
	{ SkillType::BackAttack, "����� �밡" },
	{ SkillType::HeadAttack, "Ÿ���� �밡" },
	{ SkillType::Absorb, "���� ���" },
	{ SkillType::EdgeKnife, "���� �ܵ�" },
	{ SkillType::FastFast, "�����Ӱ�" },
	{ SkillType::MastersPower, "������ ����" },
	{ SkillType::FocusOnMe, "�ü� ����" },
	{ SkillType::ManaFlow, "������ �帧" },
	{ SkillType::Bombman, "���߹� ������" },
	{ SkillType::AngleBless, "������ ��ȣ" },
	{ SkillType::PowerFist, "�м��� �ָ�" },
	{ SkillType::BrokenBone, "�η��� ��" },
	{ SkillType::Runner, "Ż���� ���" },
	{ SkillType::Thunder, "������ �г�" },
	{ SkillType::Bully, "���� ����" },
	{ SkillType::StrongMind, "���� ����" },
	{ SkillType::BreakShield, "���� ����" },
};

const int maxCount = 34;