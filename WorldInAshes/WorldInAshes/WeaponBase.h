#pragma once
#include<SFML\Graphics.hpp>

struct WeaponDef
{
	std::string		m_name;
	int				m_damage;
};

class WeaponBase
{
public:
	WeaponBase();
	~WeaponBase();
private:
	WeaponDef
};