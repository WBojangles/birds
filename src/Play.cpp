#include "../include/Play.hpp"

void brd::Play::init()
{
	SHE::AssetManager::queueFont("Latin-Modern-Mono/lmmono10-regular.otf");
	SHE::AssetManager::loadFonts();
	dialogue.setFont(*SHE::AssetManager::getFont("Latin-Modern-Mono/lmmono10-regular.otf"));
	dialogue.setCharacterSize(16);
	dialogue.setColor(sf::Color(255, 255, 255));

    reInit();
}

void brd::Play::reInit()
{
	std::cout << birds[0].name << ": " << birds[0].gnd << "\n";
	birds[0].setDialogue(0);
}

void brd::Play::doEvents(const sf::Event& E)
{
}

void brd::Play::update(const float& gametime)
{
}

void brd::Play::draw()
{
	SHE::StateManager::window.draw(dialogue);
}

void brd::Play::clean()
{
}
