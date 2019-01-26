#pragma once
#include "Renderable.h"
#include <SFML/Graphics.hpp>

struct Animation
{
	std::string m_name;
	float m_currentFrame;
	std::vector<sf::IntRect> m_frames;
	float m_fps;
};

class AnimatedSprite : public sf::Sprite
{
public:
	AnimatedSprite();
	void Addanimation(std::vector<sf::IntRect> frames, float fps, std::string name);
	void LoadAnimationsFromFile(const char* AnimationFile);
	void Update(float dt);
	void SetAnimation(int animationIndex);
private:
	std::vector<Animation> m_animations;
	int m_currentAnimation;
};