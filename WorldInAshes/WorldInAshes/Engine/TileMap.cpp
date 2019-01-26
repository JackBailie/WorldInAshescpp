#include "TileMap.h"
#include <fstream>
#include <sstream>
#include <iostream>

TileMap::TileMap()
{
}

TileMap::~TileMap()
{
}

void TileMap::LoadMap(std::string texture, std::string mapFile, ComponentStore* componentStore,
	sf::Vector2i tileSize, float scale)
{
	m_texture = componentStore->m_assetStorage.LoadTexture(texture);
	int xamount = m_texture.getSize().x / tileSize.x;
	int yamount = m_texture.getSize().y / tileSize.y;

	for (int y = 0; y < yamount; y++)
	{
		for (int x = 0; x < xamount; x++)
		{
			m_tileRects.push_back(sf::IntRect(x * tileSize.x, y * tileSize.y, tileSize.x, tileSize.y));
		}
	}

	std::ifstream file;
	file.open(mapFile);
	
	if (!file.is_open())
	{
		std::cerr << "file could not be opened: " << mapFile << std::endl;
		return;
	}
	int ypos = 0;
	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		std::stringstream lineStream(line);

		int xpos = 0;
		while (!lineStream.eof())
		{
			std::string indexstring;
			int index;

			lineStream >> indexstring;
			index = std::stoi(indexstring);

			if (index == 0)
			{
				break;
			}

			sf::Sprite* sprite = new sf::Sprite;
			sprite->setTexture(m_texture);
			sprite->setTextureRect(m_tileRects[index]);
			sprite->setPosition((float)(xpos * tileSize.x) * scale, (float)(ypos * tileSize.y) * scale);
			sprite->setScale(scale, scale);

			m_tiles.push_back(sprite);
			componentStore->m_sprites.push_back(sprite);

			xpos++;
		}
		ypos++;
	}

	file.close();
}
