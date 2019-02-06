#pragma once
#include<SFML\Graphics.hpp>

struct WeaponDef
{
	std::string		m_name;
	int				m_damage;
};

class Weapon
{
public:
	Weapon();
	Weapon(WeaponDef* weaponDef);
	~Weapon();

	void Fire();
private:
	WeaponDef* m_weaponDef;
};