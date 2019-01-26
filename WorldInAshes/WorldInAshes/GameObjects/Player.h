#pragma once
#include"../Engine/GameObject.h"
#include"../Engine/AnimatedSprite.h"
#include"../Engine/CollisionBox.h"

class Player : public GameObject
{
public:
	Player();
	Player(sf::Vector2f startPos);
	void Initialise();
	void Update(float dt);
private:
	AnimatedSprite* m_animatedSprite;
	sf::Texture m_texture;
	sf::Vector2f m_startPos;
	CollisionBox* m_collisionBox;
};