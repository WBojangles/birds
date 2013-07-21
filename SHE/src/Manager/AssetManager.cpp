#include "../../include/Manager/AssetManager.hpp"

typedef std::map<std::string, std::tr1::shared_ptr<sf::Texture> > textureMap;
typedef std::map<std::string, std::tr1::shared_ptr<sf::Font> > fontMap;

// Static members
textureMap SHE::AssetManager::textures = textureMap();
fontMap SHE::AssetManager::fonts = fontMap();
std::string SHE::AssetManager::textureLocation = ".assets/img/";
std::string SHE::AssetManager::fontLocation = ".assets/fnt/";
std::vector<std::string> SHE::AssetManager::textureLoadReady = std::vector<std::string>();
std::vector<std::string> SHE::AssetManager::fontLoadReady = std::vector<std::string>();

/// Textures

// Adds a texture to be leaded on next call of loadTextures
void SHE::AssetManager::queueTexture(const std::string& texture)
{
	textureLoadReady.push_back(texture);
}

// Load textures currently in textureLoadReady
void SHE::AssetManager::loadTextures()
{
	if (textureLoadReady.size()) // At least 1 element
	{
		for (unsigned int i = 0; i < textureLoadReady.size(); i++) // For each new texture to be added
		{
			if (textures.find(textureLoadReady[i]) == textures.end()) // Be sure that key added doesn't already exist (hey I don't judge just making sure)
			{
				textures[textureLoadReady[i]] = std::tr1::shared_ptr<sf::Texture>(new sf::Texture);
				if (!textures[textureLoadReady[i]]->loadFromFile(textureLocation + textureLoadReady[i])) exit(1); // TODO: handle dat error
				//textures[textureLoadReady[i]]->setSmooth(true);
			}
		}
	}
	textureLoadReady.clear(); // Refresh

	std::cout << "All textures loaded\n";
}

// Remove a texture
void SHE::AssetManager::removeTexture(const std::string& texture)
{
	textures.erase(texture);
}

// Return a given texture
std::tr1::shared_ptr<sf::Texture> SHE::AssetManager::getTexture(const std::string& texture)
{
	return textures[texture];
}

/// Fonts

// Add fonts to be loaded
void SHE::AssetManager::queueFont(const std::string& font)
{
	fontLoadReady.push_back(font);
}

// Load fonts
void SHE::AssetManager::loadFonts()
{
	if (fontLoadReady.size()) // At least 1 element
	{
		for (unsigned int i = 0; i < fontLoadReady.size(); i++) // For each new font to be added
		{
			if (fonts.find(fontLoadReady[i]) == fonts.end()) // Be sure that key added doesn't already exist
			{
				fonts[fontLoadReady[i]] = std::tr1::shared_ptr<sf::Font>(new sf::Font);
				if (!fonts[fontLoadReady[i]]->loadFromFile(fontLocation + fontLoadReady[i])) exit(1); // TODO: handle dat error
			}
		}
	}
	fontLoadReady.clear(); // Refresh

	std::cout << "All fonts loaded\n";
}

// Remove a font
void SHE::AssetManager::removeFont(const std::string& font)
{
	fonts.erase(font);
}

// Return a given font
std::tr1::shared_ptr<sf::Font> SHE::AssetManager::getFont(const std::string& font)
{
	return fonts[font];
}
