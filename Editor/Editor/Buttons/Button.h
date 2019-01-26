#pragma once
#include<SFML/Graphics.hpp>

class Button
{
public:
	Button();
	virtual void Initialise();
	virtual void OnClicked() = 0;
	
	void SetFont(sf::Font& font);
	void SetTexture(sf::Texture& texture);
	void SetGlobalBox(float x, float y, float w, float h);
	void SetGlobalBox(sf::IntRect rect);
	void SetText(std::string string);

	void Update(sf::RenderWindow* renderWindow);
	void Render(sf::RenderWindow* renderWindow);
private:
	sf::FloatRect m_boundingBox;
	bool m_mouseOver;
	bool m_mousePrevious;

	sf::Font m_font;
	sf::Text m_text;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::RectangleShape m_rectangle;
};