#include "TestGameState.h"

const float SCALE = 2.0f;

void TestGameState::Initialise()
{	
	m_tileMap.LoadMap("bac_tileset.png", "testmap.txt", m_componentStore, sf::Vector2i(32, 32), SCALE);
	Player* player = new Player(sf::Vector2f(100.0f, 400.0f - 63.0f));
	AddGameObject(player);

	LoadCollisionBox("CollisionBoxes.txt", SCALE);
	m_componentStore->m_renderWindow->setView(m_componentStore->m_view);
}
