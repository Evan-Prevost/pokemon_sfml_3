#include "GameWindow.h"

GameWindow::GameWindow() : _window(sf::VideoMode::getDesktopMode(), "Pokemon Like", sf::Style::None)
{
    this->_window.setFramerateLimit(60);

    this->_window.setVerticalSyncEnabled(true);

    this->_view.reset(sf::FloatRect(0.f, 0.f, 240.f, 135.f));

    this->_window.setView(_view);
}

bool GameWindow::isOpen(void) const
{
    return this->_window.isOpen();
}

void GameWindow::handleEvents(void)
{
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->_window.close();
    }
}

void GameWindow::clear(void)
{
    this->_window.clear();
}

void GameWindow::display(void)
{
    this->_window.display();
}

void GameWindow::drawEntity(const Entity& entity)
{
    this->_window.draw(entity.getSprite());
}

void GameWindow::drawMap(const TileMap& tilemap)
{
    this->_window.draw(tilemap);
}