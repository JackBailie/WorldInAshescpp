#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Renderer.h"
#include"TileMap.h"
#include "CollisionBox.h"



class GameState
{
public:
	GameState();
	~GameState();
	virtual void Initialise() = 0;
	void Update(float dt);
	void Render();
	void AddGameObject(GameObject* gameObject);
	void SetRenderWindow(sf::RenderWindow *renderWindow);
	void LoadCollisionBox(std::string fileName, float scale);
	ComponentStore* m_componentStore;
private:
	std::vector<GameObject*> m_gameObjects;
	Renderer m_renderer;


	bool m_persistent;
};

#endif