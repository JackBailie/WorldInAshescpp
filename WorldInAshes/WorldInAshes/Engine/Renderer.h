#pragma once
#include<vector>
#include"Renderable.h"
#include<SFML\Graphics.hpp>

class Renderer
{
private:
	std::vector<Renderable> Sprites;
public:
	Renderer();
	
	void Render(sf::RenderWindow* renderWindow);
};