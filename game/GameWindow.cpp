#include "GameWindow.h"
#include <iostream>
#include "ConfigMap.h"

GameWindow::GameWindow() : _window(sf::VideoMode::getDesktopMode(), "Pokemon Like", sf::Style::None)
{
    this->_window.setFramerateLimit(60);

    this->_window.setVerticalSyncEnabled(true);

    this->_view.setCenter(320.f/2, 180.f/2);
    this->_view.setSize(320.f, 180.f);

    this->_window.setView(_view);
}

bool GameWindow::isOpen(void) const
{
    return this->_window.isOpen();
}

bool GameWindow::isPause(void)
{
    return this->_pause;
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

    }
    return result;  // 0 = do nothing    1 = close game    2 = start game
}

int GameWindow::handleEventsGame(void)
{
    sf::Event event;
    int result = 0;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            result = 1;
            this->_window.close();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            this->_pause = true;
            break;
        }
    }
    return result;
}

int GameWindow::handleEventsPause(void)
{
    sf::Event event;
    int result = 0;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            result = 1;
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
    return result;
}

void GameWindow::clear(void)
{
    this->_window.clear();
}

void GameWindow::display(void)
{
    this->_window.setView(_view);
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

void GameWindow::drawButton(const Button& button) {
    this->_window.draw(button.getSprite());
    this->_window.draw(button.getText());
}

bool GameWindow::isPressed(const Button& button) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        sf::Vector2i mousePosition = sf::Mouse::getPosition(_window);

        int ratio = _window.getSize().x /_view.getSize().x;

        sf::Vector2f spritePosition = button.getSprite().getPosition();
        sf::Vector2u spriteSize = button.getSprite().getTexture()->getSize();

        std::cout << ratio;
        std::cout << "   ";
        std::cout << spritePosition.x;
        std::cout << " " ;
        std::cout << mousePosition.x / ratio;
        std::cout << " ";
        std::cout << spritePosition.x + spriteSize.x;
        std::cout << "   ";
        std::cout << spritePosition.y;
        std::cout << " ";
        std::cout << mousePosition.y / ratio;
        std::cout << " ";
        std::cout << spritePosition.y + spriteSize.y;
        std::cout << std::endl;



        if (mousePosition.x / ratio >= spritePosition.x
            && mousePosition.x / ratio <= spritePosition.x + spriteSize.x
            && mousePosition.y / ratio >= spritePosition.y
            && mousePosition.y / ratio <= spritePosition.y + spriteSize.y)
        {
            return true;
        }
    }
    return false;
}