#pragma once
#include "Tool.h"

class TilePlacer
{
public:
	TilePlacer();
	~TilePlacer();
	virtual void Update();
	virtual void Render(sf::RenderWindow* renderWindow);
};