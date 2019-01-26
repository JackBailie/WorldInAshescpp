#include<iostream>
#include "Game.h"

int main()
{
	Game game;

	game.Initialise();

	std::cout << "GameOpened" << std::endl;

	game.Loop();

	return 0;
}