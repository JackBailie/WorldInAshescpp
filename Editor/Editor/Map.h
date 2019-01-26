#pragma once
#include"TileSelector.h"
#include"CollisionBoxPlacer.h"

class Map
{
public:
	Map(int width, int height, int tilewidth, int tileheight, std::string texture, sf::View* defaultView, sf::View* mapView);
	void Save(std::string saveFilePath);
	void Update(sf::RenderWindow* renderWindow);
	bool MouseOver(sf::FloatRect box, sf::Vector2i mousePos);
	void Render(sf::RenderWindow* renderWindow);
	void CameraMove(sf::Vector2i movement);
private:
	std::vector<std::vector<int>> m_tiles;
	std::vector<Tile> m_tileSprites;
	std::vector<sf::Sprite> m_tileSelectorSprites;

	TileMap m_tileMap;
	sf::IntRect m_clickableArea;

	sf::RectangleShape m_background;
	sf::RectangleShape m_selectedTileRect;
	
	std::vector<sf::RectangleShape> m_CollisionBoxes;

	std::vector<Tool*> m_tools;
	
	bool m_mousePrevious;
	int m_selectedTool;

	sf::View* m_defaultView;
	sf::View* m_mapView;

	sf::Vector2i m_mousePreviousPos;
};