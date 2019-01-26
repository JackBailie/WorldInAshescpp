#pragma once
#include<SFML/Graphics.hpp>
#include"ComponentStore.h"

class TileMap
{
public:
	TileMap();
	~TileMap();
	void LoadMap(std::string texture, std::string mapFile, ComponentStore* componentStore, sf::Vector2i tileSize, float scale);
private:
	std::vector<sf::Sprite*> m_tiles;
	std::vector<sf::IntRect> m_tileRects;
	sf::Texture m_texture;
};