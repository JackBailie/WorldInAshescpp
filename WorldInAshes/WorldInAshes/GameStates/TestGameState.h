#pragma once
#include"../Engine/GameState.h"
#include"../GameObjects/Player.h"

class TestGameState : public GameState
{
public:
	virtual void Initialise();
private:
	TileMap m_tileMap;
};