#pragma once
#include <SFML/Graphics.hpp>
#include "Buttons\SaveButton.h"
#include "Map.h"

class Editor
{
public:
	Editor();
	~Editor();
	void Initialise();
	void Loop();
	void Update();
	void Render();
	void AddToolBarButton(Button* button);
private:
	sf::RenderWindow m_RenderWindow;
	sf::Font m_Font;
	std::vector<Button*> m_Buttons;
	Map* m_map;

	sf::View m_defaultView;
	sf::View m_mapView;
};