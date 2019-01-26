#pragma once
#include<SFML\Graphics.hpp>
#include"AnimatedSprite.h"
#include"AssetStorage.h"

class GameObject;
class CollisionBox;

class ComponentHandler
{
private:
	
};

struct ComponentStore
{
	sf::RenderWindow* m_renderWindow;
	AssetStorage m_assetStorage;
	std::vector<GameObject*> m_gameObjects;
	std::vector<sf::Sprite*> m_sprites;
	std::vector<CollisionBox*> m_collisionBoxes;
	sf::View m_view;
};