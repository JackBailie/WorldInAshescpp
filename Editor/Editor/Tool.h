#pragma once

#include"Tile.h"

class Tool
{
public:
	Tool();
	virtual ~Tool();
	virtual void Update(sf::RenderWindow* renderWindow, sf::Vector2i mousePos) = 0;
	virtual void Render(sf::RenderWindow* renderWindow) = 0;
	bool MouseOver(sf::FloatRect box, sf::Vector2i mousePos);
	bool MouseOver(sf::RectangleShape box, sf::Vector2i mousePos);
};