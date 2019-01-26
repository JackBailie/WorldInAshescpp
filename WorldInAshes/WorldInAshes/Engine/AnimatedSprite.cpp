#include "AnimatedSprite.h"
#include <fstream>
#include <iostream>
#include <sstream>

AnimatedSprite::AnimatedSprite():
m_currentAnimation(0)
{
}

void AnimatedSprite::Addanimation(std::vector<sf::IntRect> frames, float fps, std::string name)
{
	Animation t_animation;
	t_animation.m_frames = frames;
	t_animation.m_currentFrame = 0.0f;
	t_animation.m_fps = fps;
	m_animations.push_back(t_animation);
}

void AnimatedSprite::LoadAnimationsFromFile(const char * animationFile)
{
	std::ifstream file;
	file.open(animationFile);


	if (!file.is_open())
	{
		std::cerr << "Unable to open File: " << animationFile << std::endl;
		return;
	}
	
	Animation animation;
	while(!file.eof())
	{
		std::string line, input;
		std::getline(file, line);
		std::stringstream lineStream(line);
		
		lineStream >> input;

		if (input.compare("a") == 0)
		{
			animation = Animation();
			lineStream >> animation.m_name;
			lineStream >> input;
			float fps = std::stof(input);
			animation.m_fps = fps;
			animation.m_currentFrame = 0.0f;

		}
		if (input.compare("f") == 0)
		{
			sf::IntRect frame;
			
			lineStream >> input;
			frame.left = std::stoi(input);
			lineStream >> input;
			frame.top = std::stoi(input);
			lineStream >> input;
			frame.width = std::stoi(input);
			lineStream >> input;
			frame.height = std::stoi(input);
			
			animation.m_frames.push_back(frame);
		}
		if (input.compare("end") == 0)
		{
			m_animations.push_back(animation);
		}
	}

	file.close();
}

void AnimatedSprite::Update(float dt)
{
	Animation* animation = &m_animations[m_currentAnimation];;

	animation->m_currentFrame += dt * animation->m_fps;
	
	if (animation->m_currentFrame > (float)animation->m_frames.size())
	{
		m_animations[m_currentAnimation].m_currentFrame = 0.0f;
	}

	setTextureRect(animation->m_frames[(int)floor(animation->m_currentFrame)]);
	
}

void AnimatedSprite::SetAnimation(int animationIndex)
{
	m_currentAnimation = animationIndex;
}
