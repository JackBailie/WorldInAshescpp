#pragma once
#include <SFML/Graphics.hpp>

class EditorObject
{
public:
	EditorObject();
	~EditorObject();
	virtual void Render(sf::RenderWindow* renderWindow) = 0;
};