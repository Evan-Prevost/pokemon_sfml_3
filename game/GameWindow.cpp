#include "GameWindow.h"
#include <iostream>

GameWindow::GameWindow() : _window(sf::VideoMode::getDesktopMode(), "Pokemon Like", sf::Style::None)
{
    this->_window.setFramerateLimit(60);

    this->_window.setVerticalSyncEnabled(true);

    this->_view.reset(sf::FloatRect(150.f, 120.f, 320.f, 180.f));

    this->_window.setView(_view);
}

bool GameWindow::isOpen(void) const
{
    return this->_window.isOpen();
}

void GameWindow::handleEventsGame(void)
{
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            this->_window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->_pause = true;
            break;
        }
    }
}

void GameWindow::handleEventsPause(void)
{
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->_window.close();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i position = sf::Mouse::getPosition(this->_window);
            position.x = position.x / 8;
            position.y = position.y / 8;

            if (position.y >= 55 && position.y <= 74) {
                if (position.x >= 24 && position.x <= 72) {
                    this->_pause = false;
                    break;
                }
                else if (position.x >= 77 && position.y <= 125) {
                    //
                }
                else if (position.x >= 132 && position.y <= 179) {
                    this->_window.close();
                    break;
                }
            }
        }
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

bool GameWindow::isPause(void) {
    return this->_pause;
}