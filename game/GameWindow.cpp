#include "GameWindow.h"
#include "ConfigMap.h"
#include <iostream>

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
            result = 2;
            break;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            result = 3;
            break;
        }
    }
    return result;
}

int GameWindow::handleEventsQuit(void)
{
    sf::Event event;
    int result = 0;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            this->_window.close();
            result = 1;
        }
    }
    return result;
}

int GameWindow::handleEventsCombat(void)
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
            result = 2;
            break;
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

void GameWindow::drawSprite(const sf::Drawable &sprite)
{
    this->_window.draw(sprite);
}

void GameWindow::drawMap(const TileMap& tilemap)
{
    this->_window.draw(tilemap);
}

void GameWindow::drawTextBox(const TextBox& textBox) {
    this->_window.draw(textBox.getSprite());
    this->_window.draw(textBox.getText());
}

void GameWindow::drawButton(const Button& button) {
    this->_window.draw(button.getSprite());
    this->_window.draw(button.getText());
}

void GameWindow::drawPause(const PauseMenu& pause) {
    this->drawEntity(pause._background);
    this->drawTextBox(pause._header);
    this->drawButton(pause._resume);
    this->drawButton(pause._quit);
}

bool GameWindow::isPressed(const Button& button) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        
        sf::Vector2i mousePosition = sf::Mouse::getPosition(_window);

        sf::Vector2f viewCenter = _view.getCenter();
        sf::Vector2f viewSize = _view.getSize();
        sf::Vector2f viewPosition(viewCenter.x - viewSize.x / 2, viewCenter.y - viewSize.y / 2);

        int ratio = _window.getSize().x /_view.getSize().x;
        
        sf::Vector2f spritePosition = button.getSprite().getPosition();
        sf::Vector2u spriteSize = button.getSprite().getTexture()->getSize();

        /*std::cout << ratio;
        std::cout << "   ";
        std::cout << spritePosition.x - viewPosition.x;
        std::cout << " " ;
        std::cout << mousePosition.x / ratio;
        std::cout << " ";
        std::cout << spritePosition.x + spriteSize.x - viewPosition.x;
        std::cout << "   ";
        std::cout << spritePosition.y - viewPosition.y;
        std::cout << " ";
        std::cout << mousePosition.y / ratio;
        std::cout << " ";
        std::cout << spritePosition.y + spriteSize.y - viewPosition.y;
        std::cout << std::endl;*/


        if (mousePosition.x / ratio >= spritePosition.x - viewPosition.x
            && mousePosition.x / ratio <= spritePosition.x + spriteSize.x - viewPosition.x
            && mousePosition.y / ratio >= spritePosition.y - viewPosition.y
            && mousePosition.y / ratio <= spritePosition.y + spriteSize.y - viewPosition.y)
        {
            return true;
        }
    }
    return false;
}