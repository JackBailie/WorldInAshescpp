#include "Map.h"
#include<iostream>
#include<fstream>

Map::Map(int width, int height, int tilewidth, int tileheight, std::string texture, sf::View* defaultView, sf::View* mapView) :
	m_mousePrevious(false),
	m_selectedTool(0),
	m_defaultView(defaultView),
	m_mapView(mapView)
{
	const float SCALE = 1.0f;

	m_tiles.resize(height);
	for (unsigned int i = 0; i < m_tiles.size(); i++)
	{
		m_tiles[i].resize(width);
	}

	//Load Texture
	int xamount, yamount;
	if (m_tileMap.m_texture.loadFromFile(texture))
	{
		xamount = m_tileMap.m_texture.getSize().x / tilewidth;
		yamount = m_tileMap.m_texture.getSize().y / tileheight;
		for (unsigned int y = 0; y < yamount; y++)
		{
			for (unsigned int x = 0; x < xamount; x++)
			{
				m_tileMap.m_tileMap.push_back(sf::IntRect(x*tilewidth, y*tileheight, tilewidth, tileheight));
				sf::Sprite sprite;
				sprite.setTexture(m_tileMap.m_texture);
				sprite.setTextureRect(sf::IntRect(x*tilewidth, y*tilewidth, tilewidth, tileheight));
				sprite.setPosition(x*tilewidth + 800, y*tileheight + 50);
				m_tileSelectorSprites.push_back(sprite);
			}
		}
	}
	else
	{
		std::cerr << "unable to open file: " << texture << std::endl;
	}

	//Create the tile map
	for (int y = 0; y < m_tiles.size(); y++)
	{
		for (int x = 0; x < m_tiles[y].size(); x++)
		{
			Tile tile;
			tile.m_pos = sf::Vector2i(x, y);
			tile.m_sprite.setTexture(m_tileMap.m_texture);
			tile.m_sprite.setPosition(y*tilewidth*SCALE, x*tileheight*SCALE + 50);
			tile.m_sprite.setScale(SCALE, SCALE);
			tile.m_sprite.setTextureRect(m_tileMap.m_tileMap[m_tileMap.m_tileMap.size()-1]);
			m_tileSprites.push_back(tile);
		}
	}

	m_background.setFillColor(sf::Color(0, 255, 0));
	m_background.setSize(sf::Vector2f(width*tilewidth*SCALE, height*tileheight*SCALE));
	m_background.setPosition(0.0f, 50.0f);
	
	m_selectedTileRect.setSize(sf::Vector2f((float)tilewidth, (float)tileheight));
	m_selectedTileRect.setPosition(360.0f, 50.0f);
	m_selectedTileRect.setFillColor(sf::Color(255, 0, 0, 0));
	m_selectedTileRect.setOutlineThickness(2);
	m_selectedTileRect.setOutlineColor(sf::Color(255, 0, 0));

	m_tools.push_back(new TileSelector(&m_tileSprites, &m_tileSelectorSprites, &m_tiles, &m_tileMap, &m_selectedTileRect));
	m_tools.push_back(new CollisionBoxPlacer(&m_CollisionBoxes));
}

void Map::Save(std::string saveFilePath)
{
	std::ofstream saveFile;
	saveFile.open(saveFilePath);
	if (!saveFile.is_open())
	{
		std::cerr << "unable to open file: " << saveFilePath << std::endl;
		return;
	}
	for (int y = 0; y < m_tiles.size(); y++)
	{
		for (int x = 0; x < m_tiles[y].size(); x++)
		{
			std::string tileString = std::to_string(m_tiles[y][x]);
			if (x == 0)
			{
				if (y != 0)
				{
					saveFile << std::endl;
				}
			}
			else
			{
				saveFile << " ";
			}
			saveFile << tileString;
		}
	}
	std::ofstream collisionsSaveFile;
	collisionsSaveFile.open("CollisionBoxes.txt");
	if (!collisionsSaveFile.is_open())
	{
		std::cerr << "Collision save file could not be opened" << std::endl;
		return;
	}
	for (int i = 0; i < m_CollisionBoxes.size(); i++)
	{
		if (i != 0)
		{
			collisionsSaveFile << std::endl;
		}

		collisionsSaveFile << std::to_string(m_CollisionBoxes[i].getPosition().x) << " " << std::to_string(m_CollisionBoxes[i].getPosition().y - 48.0f) << " ";
		collisionsSaveFile << std::to_string(m_CollisionBoxes[i].getSize().x) << " " << std::to_string(m_CollisionBoxes[i].getSize().y);
	}
	collisionsSaveFile.close();
}

void Map::Update(sf::RenderWindow * renderWindow)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*renderWindow);
	mousePos.x += m_mapView->getCenter().x - m_mapView->getSize().x/2;
	mousePos.y += m_mapView->getCenter().y - m_mapView->getSize().y/2;
	m_tools[m_selectedTool]->Update(renderWindow, mousePos);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
	{
		m_selectedTool = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
	{
		m_selectedTool = 1;
	}

	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
	{
		CameraMove(sf::Mouse::getPosition() - m_mousePreviousPos);
	}

	m_mousePreviousPos = sf::Mouse::getPosition();
	m_mousePrevious = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

bool Map::MouseOver(sf::FloatRect box, sf::Vector2i mousePos)
{
	if (mousePos.x > box.left && mousePos.x < box.left + box.width &&
		mousePos.y > box.top && mousePos.y < box.top + box.height)
	{
		return true;
	}
	return false;
}

void Map::Render(sf::RenderWindow * renderWindow)
{
	renderWindow->setView(*m_mapView);
	renderWindow->draw(m_background);
	for (int i = 0; i < m_tileSprites.size(); i++)
	{
		renderWindow->draw(m_tileSprites[i].m_sprite);
	}
	
	for (int i = 0; i < m_CollisionBoxes.size(); i++)
	{
		renderWindow->draw(m_CollisionBoxes[i]);
	}
	
	renderWindow->setView(*m_defaultView);
	for (int i = 0; i < m_tileSelectorSprites.size(); i++)
	{
		renderWindow->draw(m_tileSelectorSprites[i]);
	}

	renderWindow->draw(m_selectedTileRect);
	
	renderWindow->setView(*m_mapView);
	m_tools[1]->Render(renderWindow);
	renderWindow->setView(*m_defaultView);
}

void Map::CameraMove(sf::Vector2i movement)
{
	sf::Vector2f newPos = m_mapView->getCenter();
	newPos.x -= (float)movement.x;
	newPos.y -= (float)movement.y;
	m_mapView->setCenter(newPos);
}
