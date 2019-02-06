#include "WeaponDefContainer.h"
#include <fstream>
#include <sstream>
#include <iostream>

WeaponDefContainer::WeaponDefContainer()
{
}

WeaponDefContainer::~WeaponDefContainer()
{
}

void WeaponDefContainer::AddWeaponDef(std::string name, int damage)
{
	WeaponDef weapondef;
	weapondef.m_name = name;
	weapondef.m_damage = damage;

	m_weaponDef.push_back(weapondef);
}

void WeaponDefContainer::AddWeaponDef(WeaponDef weaponDef)
{
	m_weaponDef.push_back(weaponDef);
}

void WeaponDefContainer::LoadWeaponDef(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);

	if (!file.is_open())
	{
		std::cerr << "Could not open file: " << fileName << std::endl;
	}

	while (!file.eof())
	{
		WeaponDef weaponDef;
		std::string line;
		std::getline(file, line);
		std::stringstream lineStream(line);
		std::string data;
		
		lineStream >> data;
		std::replace(data.begin(), data.end(), '_', ' ');
		weaponDef.m_name = data;
		lineStream >> data;
		weaponDef.m_damage = std::stoi(data);

		AddWeaponDef(weaponDef);
	}
	file.close();

	for (auto weaponDefIt : m_weaponDef)
	{
		std::cout << weaponDefIt.m_name << " " << weaponDefIt.m_damage << std::endl;
	}
}