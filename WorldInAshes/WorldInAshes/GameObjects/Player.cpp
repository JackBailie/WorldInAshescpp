#include "Player.h"
#include <iostream>

Player::Player()
{
}

Player::Player(sf::Vector2f startPos):
	m_startPos(startPos),
	m_isMoving(false)
{
}

void Player::Initialise()
{
	
	/*if (!m_texture.loadFromFile("Sprite.png"))
	{
		std::cerr << "Unable to load" << std::endl;
	}*/
	m_texture = m_componentStore->m_assetStorage.LoadTexture("Sprite.png");
	m_animatedSprite = new AnimatedSprite();
	m_animatedSprite->setTexture(m_texture);
	m_animatedSprite->setPosition(m_startPos);

	m_animatedSprite->LoadAnimationsFromFile("Playerspr.txt");
	m_animatedSprite->SetAnimation(3);
	m_animatedSprite->setOrigin(m_animatedSprite->getTextureRect().width / 2, m_animatedSprite->getTextureRect().height * 0.9f);

	m_componentStore->m_sprites.push_back(m_animatedSprite);

	m_collisionBox = new CollisionBox(m_animatedSprite->getGlobalBounds(),this,m_componentStore,ctypeWall);
	m_componentStore->m_collisionBoxes.push_back(m_collisionBox);
}

void Player::Update(float dt)
{
	m_collisionBox->SetCollisionRect(m_animatedSprite->getGlobalBounds());
	m_collisionBox->ScaleCollisionRect(0.5f, 1.0f);

	UpdateSpriteState();

	m_isMoving = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_collisionBox->MoveCollisionRect(sf::Vector2f(-100 * dt, 0));

		if (!m_collisionBox->GetColliding(ctypeWall))
		{
			m_animatedSprite->move(-100 * dt, 0);
			m_isMoving = true;
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		m_collisionBox->MoveCollisionRect(sf::Vector2f(100 * dt, 0));

		if (!m_collisionBox->GetColliding(ctypeWall))
		{
			m_animatedSprite->move(100 * dt, 0);
			m_isMoving = true;
		}

	}

	m_collisionBox->SetCollisionRect(m_animatedSprite->getGlobalBounds());
	m_collisionBox->ScaleCollisionRect(0.5f, 1.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{

		m_collisionBox->MoveCollisionRect(sf::Vector2f(0, -100 * dt));

		if (!m_collisionBox->GetColliding(ctypeWall))
		{
			m_animatedSprite->move(0, -100 * dt);
			m_isMoving = true;
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		m_collisionBox->MoveCollisionRect(sf::Vector2f(0, 100 * dt));

		if (!m_collisionBox->GetColliding(ctypeWall))
		{
			m_animatedSprite->move(0, 100 * dt);
			m_isMoving = true;
		}

	}

	sf::Vector2f cameraPos;
	cameraPos.x = std::floor(m_animatedSprite->getPosition().x);
	cameraPos.y = std::floor(m_animatedSprite->getPosition().y);

	m_componentStore->m_view.setCenter(cameraPos);
	m_componentStore->m_renderWindow->setView(m_componentStore->m_view);

	m_animatedSprite->Update(dt);
	m_collisionBox->SetCollisionRect(m_animatedSprite->getGlobalBounds());
	if(m_collisionBox->GetColliding(ctypeWall))
	{
		std::cout << "colliding" << std::endl;
	}

}

float Player::GetFaceDirection()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*m_componentStore->m_renderWindow);
	sf::Vector2f playerScreenPos;
	playerScreenPos.x = m_componentStore->m_renderWindow->getSize().x / 2; playerScreenPos.y = m_componentStore->m_renderWindow->getSize().y / 2;;

	int xdist = mousePos.x - (int)playerScreenPos.x;
	int ydist = mousePos.y - (int)playerScreenPos.y;

	return std::atan2(ydist, xdist) / 3.141f * 180;
}

void Player::UpdateSpriteState()
{
	float faceDirection = GetFaceDirection();

	if (faceDirection > -45.0f && faceDirection < 45.0f)
	{
		if (m_isMoving)
		{
			m_animatedSprite->SetAnimation(3);
		}
		else
		{
			m_animatedSprite->SetAnimation(7);
		}
	}
	else if (faceDirection > 45.0f && faceDirection < 135.0f)
	{
		if (m_isMoving)
		{
			m_animatedSprite->SetAnimation(2);
		}
		else
		{
			m_animatedSprite->SetAnimation(6);
		}
	}
	else if (faceDirection > -135.0f && faceDirection < -45.0f)
	{
		if (m_isMoving)
		{
			m_animatedSprite->SetAnimation(0);
		}
		else
		{
			m_animatedSprite->SetAnimation(4);
		}
	}
	if (faceDirection > 135.0f || faceDirection < -135.0f)
	{
		if (m_isMoving)
		{
			m_animatedSprite->SetAnimation(1);
		}
		else
		{
			m_animatedSprite->SetAnimation(5);
		}
	}
}