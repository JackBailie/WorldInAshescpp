#include "Tool.h"

Tool::Tool()
{
}

Tool::~Tool()
{
}

bool Tool::MouseOver(sf::FloatRect box, sf::Vector2i mousePos)
{
	if (mousePos.x > box.left && mousePos.x < box.left + box.width &&
		mousePos.y > box.top && mousePos.y < box.top + box.height)
	{
		return true;
	}
	return false;
}

bool Tool::MouseOver(sf::RectangleShape box, sf::Vector2i mousePos)
{
	sf::FloatRect floatRect = sf::FloatRect(box.getPosition().x, box.getPosition().y,
		box.getSize().x, box.getSize().y);
	return MouseOver(floatRect, mousePos);
}
