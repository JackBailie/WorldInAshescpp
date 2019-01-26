#include "CollisionBox.h"
#include <iostream>

CollisionBox::CollisionBox(sf::FloatRect collisionRect, GameObject* parent, ComponentStore* componentStore, int type) :
	m_collisionRect(collisionRect),
	m_parent(parent),
	m_componentStore(componentStore),
	m_type(type)
{
}

void CollisionBox::SetCollisionRect(sf::FloatRect collisionRect)
{
	m_collisionRect = collisionRect;
}

void CollisionBox::MoveCollisionRect(sf::Vector2f movement)
{
	m_collisionRect.left += movement.x;
	m_collisionRect.top += movement.y;
}

void CollisionBox::ScaleCollisionRect(float x, float y)
{
	float originalWidth = m_collisionRect.width;
	float originalHeight = m_collisionRect.height;


	m_collisionRect.width *= x;
	m_collisionRect.left -= (m_collisionRect.width - originalWidth) / 2;

	m_collisionRect.height *= y;
	m_collisionRect.height -= (m_collisionRect.height - originalHeight) / 2;

}

bool CollisionBox::GetColliding(int type)
{
	for (int i = 0; i < m_componentStore->m_collisionBoxes.size(); i++)
	{
		CollisionBox* box = m_componentStore->m_collisionBoxes[i];
		if(box == this)
		{
			continue;
		}
		if (box->GetType() != type && type != ctypeAll)
		{
			continue;
		}
		if (m_collisionRect.left < box->m_collisionRect.left + box->m_collisionRect.width &&
			m_collisionRect.left + m_collisionRect.width > box->m_collisionRect.left &&
			m_collisionRect.top < box->m_collisionRect.top + box->m_collisionRect.height &&
			m_collisionRect.top + m_collisionRect.height > box->m_collisionRect.top)
		{
			
			return true;
		}
	}
	return false;
}
