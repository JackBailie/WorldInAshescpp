#include "Game.h"



Game::Game() :
	m_renderWindow(sf::VideoMode(800, 600), "World In ashes")
{
}


Game::~Game()
{
}

void Game::Initialise()
{
	m_testGameState = new TestGameState();
	m_testGameState->SetRenderWindow(&m_renderWindow);
	m_testGameState->Initialise();
}

void Game::Loop()
{
	while (m_renderWindow.isOpen())
	{
		sf::Time deltaTime = m_clock.restart();
		sf::Event e;
		while (m_renderWindow.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				m_renderWindow.close();
			}
		}
		Update(deltaTime.asSeconds());
		Render();
	}
}

void Game::Update(float dt)
{
	m_testGameState->Update(dt);
}

void Game::Render()
{
	m_renderWindow.clear(sf::Color(78, 89, 100,255));

	m_testGameState->Render();

	m_renderWindow.display();
}
