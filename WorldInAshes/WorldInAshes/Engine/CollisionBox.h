#pragma once
#include"GameObject.h"

enum CollisionType
{
	ctypeAll,
	ctypeWall
};

class CollisionBox
{
public:
	CollisionBox(sf::FloatRect collisionRect, GameObject* parent, ComponentStore* componentStore, int type);
	~CollisionBox() {};
	void SetCollisionRect(sf::FloatRect collisionRect);
	void MoveCollisionRect(sf::Vector2f movement);
	void ScaleCollisionRect(float x, float y);
	bool GetColliding(int type);
	int GetType() { return m_type; };
private:
	sf::FloatRect m_collisionRect;
	GameObject* m_parent;
	ComponentStore* m_componentStore;
	int m_type;
};