#include "CollisionBoxPlacer.h"

CollisionBoxPlacer::CollisionBoxPlacer(std::vector<sf::RectangleShape>* collisionBoxes):
	m_collisionBoxes(collisionBoxes),
	m_mousePrev(false)
{
	m_currentBox.setFillColor(sf::Color(255, 0, 0, 100));
	m_currentBox.setSize(sf::Vector2f(0.0f,0.0f));
}

CollisionBoxPlacer::~CollisionBoxPlacer()
{
}

void CollisionBoxPlacer::Update(sf::RenderWindow * renderWindow, sf::Vector2i mousePos)
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !m_mousePrev && mousePos.y > 50)
	{
		m_currentBox.setPosition(mousePos.x / 16 * 16, mousePos.y / 16 * 16);
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_mousePrev)
	{
		float w = std::max( mousePos.x - m_currentBox.getPosition().x, 16.0f );
		float h = std::max( mousePos.y - m_currentBox.getPosition().y, 16.0f );
		w = std::floor(w / 16) * 16;
		h = std::floor(h / 16) * 16;

		m_currentBox.setSize(sf::Vector2f(w, h));
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_mousePrev  && mousePos.y > 50)
	{
		m_collisionBoxes->push_back(m_currentBox);
		m_currentBox.setPosition(0.0f, 0.0f);
		m_currentBox.setSize(sf::Vector2f(0.0f, 0.0f));
	}

	for (unsigned int i = 0; i < m_collisionBoxes->size(); i++)
	{
		if (MouseOver(m_collisionBoxes->at(i), mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		{
			m_collisionBoxes->erase(m_collisionBoxes->begin() + i);
		}
	}

	m_mousePrev = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

void CollisionBoxPlacer::Render(sf::RenderWindow * renderWindow)
{
	renderWindow->draw(m_currentBox);
}
