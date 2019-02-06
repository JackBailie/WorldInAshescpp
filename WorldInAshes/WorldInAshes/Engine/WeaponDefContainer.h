#pragma once
#include"../GameObjects/Weapon.h"

class WeaponDefContainer
{
public:
	WeaponDefContainer();
	~WeaponDefContainer();

	void AddWeaponDef(std::string name, int damage);
	void AddWeaponDef(WeaponDef weaponDef);

	void LoadWeaponDef(std::string fileName);
private:
	std::vector<WeaponDef> m_weaponDef;
};