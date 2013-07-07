#include "../include/Title.hpp"

void brd::Title::init()
{
    SHE::AssetManager::queueTexture("title.png");
    SHE::AssetManager::loadTextures();
    bg.setTexture(*SHE::AssetManager::getTexture("title.png"));
}

void brd::Title::reInit()
{
}

void brd::Title::doEvents(const sf::Event& E)
{
    if (E.type == sf::Event::KeyPressed)
    {
        if (SHE::InputManager::check(1, "start"))
        {
            SHE::StateManager::create("Play", std::tr1::shared_ptr<SHE::State>(new brd::Play()));
            SHE::StateManager::set("Play");
        }
    }
}

void brd::Title::update(const float& gametime)
{
}

void brd::Title::draw()
{
    SHE::StateManager::window.draw(bg);
}

void brd::Title::clean()
{
}
