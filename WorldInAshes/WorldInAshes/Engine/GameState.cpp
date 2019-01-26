#include "GameState.h"
#include <fstream>
#include <iostream>
#include <sstream>


GameState::GameState():
	m_persistent(false)
{
	m_componentStore = new ComponentStore();
	
}

GameState::~GameState()
{

}

void GameState::Update(float dt)
{
	if (true) {
		for (unsigned int i = 0; i < m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->Update(dt);
		}
	}
}

void GameState::Render()
{
	std::vector<sf::Sprite*> sprites = m_componentStore->m_sprites;
	for (int i = 0; i < sprites.size(); i++)
	{
		m_componentStore->m_renderWindow->draw(*sprites[i]);
	}
}

void GameState::AddGameObject(GameObject * gameObject)
{
	gameObject->SetComponentStore(m_componentStore);
	gameObject->Initialise();
	m_gameObjects.push_back(gameObject);
}

void GameState::SetRenderWindow(sf::RenderWindow *renderWindow)
{
	m_componentStore->m_renderWindow = renderWindow;
	m_componentStore->m_view.reset(sf::FloatRect(0.0f, 0.0f, m_componentStore->m_renderWindow->getSize().x, m_componentStore->m_renderWindow->getSize().y));
}

void GameState::LoadCollisionBox(std::string fileName, float scale)
{
	std::ifstream file;
	file.open(fileName);

	if (!file.is_open())
	{
		std::cerr << "file could not be opened: " << fileName << std::endl;
		return;
	}

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		std::stringstream lineStream(line);
		sf::FloatRect collisionBoxRect;

		std::string input;
		lineStream >> input;
		collisionBoxRect.left = std::stof(input) * scale;

		lineStream >> input;
		collisionBoxRect.top = std::stof(input) * scale;

		lineStream >> input;
		collisionBoxRect.width = std::stof(input) * scale;

		lineStream >> input;
		collisionBoxRect.height = std::stof(input) * scale;

		CollisionBox* collisionBox = new CollisionBox(collisionBoxRect, nullptr, m_componentStore, ctypeWall);
		m_componentStore->m_collisionBoxes.push_back(collisionBox);
	}

	file.close();
}
