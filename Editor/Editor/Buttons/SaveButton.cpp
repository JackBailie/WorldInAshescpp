#include "SaveButton.h"
#include<iostream>

SaveButton::SaveButton(Map * map)
{
	m_map = map;
	SetText("Save");
}

void SaveButton::OnClicked()
{
	m_map->Save("testmap.txt");
	std::cout << "save" << std::endl;
}
