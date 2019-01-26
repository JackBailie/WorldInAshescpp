#pragma once
#include "Tool.h"

class CollisionBoxPlacer : public Tool
{
public:
	CollisionBoxPlacer(std::vector<sf::RectangleShape>* collisionBoxes);
	~CollisionBoxPlacer();
	virtual void Update(sf::RenderWindow* renderWindow, sf::Vector2i mousePos);
	virtual void Render(sf::RenderWindow* renderWindow);
private:
	std::vector<sf::RectangleShape>* m_collisionBoxes;
	sf::RectangleShape m_currentBox;
	bool m_mousePrev;

};