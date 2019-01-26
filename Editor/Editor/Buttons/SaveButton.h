#pragma once
#include"Button.h"
#include"../Map.h"

class SaveButton: public Button
{
public:
	SaveButton(Map* map);
	virtual void OnClicked();
private:
	Map* m_map;
};