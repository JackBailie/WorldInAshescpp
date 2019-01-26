#pragma once
#include <SFML\Graphics.hpp>

struct TileMap
{
	sf::Texture m_texture;
	std::vector<sf::IntRect> m_tileMap;
};

struct Tile
{
	sf::Sprite m_sprite;
	sf::Vector2i m_pos;
};