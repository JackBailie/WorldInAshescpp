#include "Button.h"

Button::Button():
	m_mousePrevious(false)
{
	m_rectangle.setFillColor(sf::Color(50, 50, 50, 255));
	m_text.setCharacterSize(10);
}

void Button::Initialise()
{
	m_text.setOrigin(m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2);
	
}

void Button::SetFont(sf::Font & font)
{
	m_font = font;
	m_text.setFont(m_font);
}

void Button::SetTexture(sf::Texture & texture)
{
}

void Button::SetGlobalBox(float x, float y, float w, float h)
{
	SetGlobalBox(sf::IntRect(x, y, w, h));
}

void Button::SetGlobalBox(sf::IntRect rect)
{
	m_rectangle.setPosition(rect.left, rect.top);
	m_rectangle.setSize(sf::Vector2f(rect.width, rect.height));
	m_boundingBox = m_rectangle.getGlobalBounds();
	m_text.setPosition(rect.left + rect.width / 2, rect.top + rect.height / 2);
}

void Button::SetText(std::string string)
{
	m_text.setString(string);
	m_text.setOrigin(m_text.getLocalBounds().width, m_text.getLocalBounds().height);
}

void Button::Update(sf::RenderWindow* m_renderWindow)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*m_renderWindow);

	if (mousePos.x > m_boundingBox.left && mousePos.x < m_boundingBox.left + m_boundingBox.width &&
		mousePos.y > m_boundingBox.top && mousePos.y < m_boundingBox.top + m_boundingBox.height)
	{
		m_mouseOver = true;
		m_rectangle.setOutlineThickness(1.0f);
		m_text.setFillColor(sf::Color(255, 255, 255));
	}
	else
	{
		m_mouseOver = false;
		m_rectangle.setOutlineThickness(0.0f);
		m_text.setFillColor(sf::Color(150, 150, 150));
	}
	if (m_mouseOver && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !m_mousePrevious)
	{
		OnClicked();
	}
	m_mousePrevious = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

void Button::Render(sf::RenderWindow * renderWindow)
{
	renderWindow->draw(m_rectangle);
	renderWindow->draw(m_text);
}
