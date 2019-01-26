#include "Player.h"
#include <iostream>

Player::Player()
{
}

Player::Player(sf::Vector2f startPos):
	m_startPos(startPos)
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
	m_componentStore->m_sprites.push_back(m_animatedSprite);

	m_collisionBox = new CollisionBox(m_animatedSprite->getGlobalBounds(),this,m_componentStore,ctypeWall);
	m_componentStore->m_collisionBoxes.push_back(m_collisionBox);
}

void Player::Update(float dt)
{
	m_collisionBox->SetCollisionRect(m_animatedSprite->getGlobalBounds());
	m_collisionBox->ScaleCollisionRect(0.5f, 1.0f);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_collisionBox->MoveCollisionRect(sf::Vector2f(-100 * dt, 0));

		if (!m_collisionBox->GetColliding(ctypeWall))
		{
			m_animatedSprite->move(-100 * dt, 0);
		}

		m_animatedSprite->SetAnimation(1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		m_collisionBox->MoveCollisionRect(sf::Vector2f(100 * dt, 0));

		if (!m_collisionBox->GetColliding(ctypeWall))
		{
			m_animatedSprite->move(100 * dt, 0);
		}

		m_animatedSprite->SetAnimation(3);
	}

	m_collisionBox->SetCollisionRect(m_animatedSprite->getGlobalBounds());
	m_collisionBox->ScaleCollisionRect(0.5f, 1.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{

		m_collisionBox->MoveCollisionRect(sf::Vector2f(0, -100 * dt));

		if (!m_collisionBox->GetColliding(ctypeWall))
		{
			m_animatedSprite->move(0, -100 * dt);
		}

		m_animatedSprite->SetAnimation(0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		m_collisionBox->MoveCollisionRect(sf::Vector2f(0, 100 * dt));

		if (!m_collisionBox->GetColliding(ctypeWall))
		{
			m_animatedSprite->move(0, 100 * dt);
		}

		m_animatedSprite->SetAnimation(2);
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
