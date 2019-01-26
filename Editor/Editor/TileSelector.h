#pragma once
#include "Tool.h"

struct Tile;

class TileSelector : public Tool
{
public:
	TileSelector(std::vector<Tile>* tilesSprites, std::vector<sf::Sprite>* tileSelectorSprites,
		std::vector<std::vector<int>>* tiles, TileMap* tileMap, sf::RectangleShape* selectedTileRect);
	~TileSelector();
	virtual void Update(sf::RenderWindow* renderWindow, sf::Vector2i mousePos);
	virtual void Render(sf::RenderWindow* renderWindow);
private:
	//sf::RenderWindow* m_renderWindow;
	std::vector<Tile>* m_tileSprites;
	std::vector<sf::Sprite>* m_tileSelectorSprites;
	std::vector<std::vector<int>>* m_tiles;
	TileMap* m_tileMap;
	int m_selectedTile;
	sf::RectangleShape* m_selectedTileRect;
};