#include "Weapon.h"

Weapon::Weapon():
	m_weaponDef(nullptr)
{
}

Weapon::Weapon(WeaponDef * weaponDef):
	m_weaponDef(weaponDef)
{
}

Weapon::~Weapon()
{
}
