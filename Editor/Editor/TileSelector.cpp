#include "TileSelector.h"

TileSelector::TileSelector(std::vector<Tile>* tileSprites, std::vector<sf::Sprite>* tileSelectorSprites,
	std::vector<std::vector<int>>* tiles, TileMap* tileMap, sf::RectangleShape* selectedTileRect)
	://m_renderWindow(renderWindow),
	m_tileSprites(tileSprites),
	m_tileSelectorSprites(tileSelectorSprites),
	m_tiles(tiles),
	m_tileMap(tileMap),
	m_selectedTile(0),
	m_selectedTileRect(selectedTileRect)
{
}

TileSelector::~TileSelector()
{
}

void TileSelector::Update(sf::RenderWindow* renderWindow, sf::Vector2i mousePos)
{
	for (int i = 0; i < m_tileSprites->size(); i++)
	{
		if (MouseOver(m_tileSprites->at(i).m_sprite.getGlobalBounds(), mousePos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && sf::Mouse::getPosition(*renderWindow).x < renderWindow->getSize().x/2)
			{
				m_tiles->at(m_tileSprites->at(i).m_pos.x)[m_tileSprites->at(i).m_pos.y] = m_selectedTile;
				m_tileSprites->at(i).m_sprite.setTextureRect(m_tileMap->m_tileMap[m_selectedTile]);
			}
		}
	}
	for (int i = 0; i < m_tileSelectorSprites->size(); i++)
	{
		if (MouseOver(m_tileSelectorSprites->at(i).getGlobalBounds(), sf::Mouse::getPosition(*renderWindow)))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				m_selectedTile = i;
				m_selectedTileRect->setPosition(m_tileSelectorSprites->at(i).getPosition());
			}
		}
	}
}

void TileSelector::Render(sf::RenderWindow * renderWindow)
{
}
