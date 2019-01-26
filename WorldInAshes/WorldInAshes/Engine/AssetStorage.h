#pragma once
#include <SFML\Graphics.hpp>

struct TextureAsset
{
	std::string m_path;
	sf::Texture m_texture;
};

class AssetStorage
{
public:
	sf::Texture& LoadTexture(std::string texureFile);
private:
	std::vector<TextureAsset> m_textureAssets;
};