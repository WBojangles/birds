#ifndef SHE_ASSETMANAGER
#define SHE_ASSETMANAGER

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <vector>
#include <tr1/memory>

#include <iostream>

	namespace SHE
	{
class AssetManager
{
  public:
	static void queueTexture(const std::string&);
	static void loadTextures();
	static void removeTexture(const std::string&);
	static std::tr1::shared_ptr<sf::Texture> getTexture(const std::string&);
	static std::string textureLocation;
	static void queueFont(const std::string&);
	static void loadFonts();
	static void removeFont(const std::string&);
	static std::tr1::shared_ptr<sf::Font> getFont(const std::string&);
	static std::string fontLocation;

  private:
	static std::map< std::string, std::tr1::shared_ptr<sf::Texture> > textures;
	static std::map< std::string, std::tr1::shared_ptr<sf::Font> > fonts;
	static std::vector<std::string> textureLoadReady;
	static std::vector<std::string> fontLoadReady;
};
	}

#endif
