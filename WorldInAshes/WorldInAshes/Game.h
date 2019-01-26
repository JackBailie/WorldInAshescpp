#pragma once
#include "GameStates/TestGameState.h"
class Game
{
public:
	Game();
	~Game();
	void Initialise();
	void Loop();
	void Update(float dt);
	void Render();

private:
	sf::RenderWindow m_renderWindow;
	GameState* m_testGameState;
	sf::Clock m_clock;
};

