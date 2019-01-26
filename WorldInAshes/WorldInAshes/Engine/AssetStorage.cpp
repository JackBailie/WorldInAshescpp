#include "AssetStorage.h"
#include <iostream>

sf::Texture& AssetStorage::LoadTexture(std::string textureFile)
{
	bool exists = false;
	int i;
	for (i = 0; i < m_textureAssets.size(); i++)
	{
		if (m_textureAssets[i].m_path.compare(textureFile) == 0)
		{
			exists = true;
			break;
		}
	}
	if (exists)
	{
		return m_textureAssets[i].m_texture;
	}
	else
	{
		int textureAssetPoint = m_textureAssets.size();
		m_textureAssets.push_back(TextureAsset());
		m_textureAssets[textureAssetPoint].m_path = textureFile;
		if(!m_textureAssets[textureAssetPoint].m_texture.loadFromFile(textureFile))
		{
			std::cerr << "could not load file: " << textureFile << std::endl;
		}
		
		return m_textureAssets[textureAssetPoint].m_texture;
	}
}
