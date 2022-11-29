#include "GameWindow.h"
#include <iostream>
#include "ConfigMap.h"

GameWindow::GameWindow() : _window(sf::VideoMode::getDesktopMode(), "Pokemon Like", sf::Style::None)
{
    this->_window.setFramerateLimit(60);

    this->_window.setVerticalSyncEnabled(true);

    this->_view.reset(INITIAL_VIEW_RECT);

    this->_window.setView(_view);
}

bool GameWindow::isOpen(void) const
{
    return this->_window.isOpen();
}

int GameWindow::handleEventsMenu(void)
{
    sf::Event event;
    int result = 0;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            this->_window.close();
            result = 1;
            break;
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(this->_window);

            int ratio = this->_window.getSize().x / this->_view.getSize().x;
            sf::Vector2f size = this->_view.getSize();

            /*std::cout << size.x / 2 - 50;
            std::cout << " ";
            std::cout << mousePosition.x / ratio;
            std::cout << " ";
            std::cout << size.x / 2 + 50;

            std::cout << std::endl;


            std::cout << size.y / 2;
            std::cout << " ";
            std::cout << mousePosition.y / ratio;
            std::cout << " ";
            std::cout << size.y / 2 + 30;
            std::cout << std::endl;
            std::cout << std::endl;*/

            if (mousePosition.y / ratio >= size.y / 2 && mousePosition.y / ratio <= size.y / 2 + 30) {
                if (mousePosition.x / ratio >= size.x / 2 - 50 && mousePosition.y / ratio <= size.x / 2 + 50) {
                    result = 2;
                    break;
                }
            }
        }

    }
    return result;  // 0 = do nothing    1 = close game    2 = start game
}

void GameWindow::handleEventsGame(void)
{
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            this->_window.close();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
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
        if (event.type == sf::Event::Closed) {
            this->_window.close();
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(this->_window);

            int ratio = this->_window.getSize().x / this->_view.getSize().x;

            /*
            std::cout << mousePosition.x;
            std::cout << " ";
            std::cout << mousePosition.y;
            std::cout << " ";
            std::cout << ratio;
            std::cout << " ";
            std::cout << mousePosition.x/ratio;
            std::cout << " ";
            std::cout << mousePosition.y/ratio;
            std::cout << std::endl;*/

            if ( mousePosition.y >= 55*ratio   &&   mousePosition.y <= 74*ratio ) {
                if ( mousePosition.x >= 132 * ratio   &&   mousePosition.y <= 179 * ratio ) {
                    this->_window.close();
                    break;
                }
                else if ( mousePosition.x >= 24*ratio   &&   mousePosition.x <= 72*ratio ) {
                    this->_pause = false;
                    break;
                }/*
                else if (position.x >= 77 && position.y <= 125) {
                    //
                }
                else if (position.x >= 132 && position.y <= 179) {
                    this->_window.close();
                    break;
                }*/
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

sf::Vector2f GameWindow::getSize(void) {
    return this->_view.getSize();
}



void GameWindow::drawEntity(const Entity& entity)
{
    this->_window.draw(entity.getSprite());
}

void GameWindow::drawMap(const TileMap& tilemap)
{
    this->_window.draw(tilemap);
}

bool GameWindow::isPause(void) 
{
    return this->_pause;
}