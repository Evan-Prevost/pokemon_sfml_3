#include "MenuWindow.h"
#include <iostream>
#include "ConfigMap.h"

MenuWindow::MenuWindow() : _window(sf::VideoMode::getDesktopMode(), "Menu", sf::Style::None)
{
    this->_window.setFramerateLimit(60);

    this->_window.setVerticalSyncEnabled(true);

    this->_view.reset(sf::FloatRect(0, 0, 320.f, 180.f));

    this->_window.setView(_view);
}

bool MenuWindow::isOpen(void) const
{
    return this->_window.isOpen();
}

int MenuWindow::handleEvents(void)
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

            if (mousePosition.y/ratio >= size.y/2 && mousePosition.y/ratio <= size.y / 2 +30) {
                if (mousePosition.x/ratio >= size.x/2 -50 && mousePosition.y/ratio <= size.x / 2 +50) {
                    result = 2;
                    break;
                }
            }
        }
        
    }
    return result;  // 0 = do nothing    1 = close game    2 = start game
}

void MenuWindow::clear(void)
{
    this->_window.clear();
}

void MenuWindow::display(void)
{
    this->_window.display();
}

sf::Vector2f MenuWindow::getSize(void) {
    return this->_view.getSize();
}

void MenuWindow::drawEntity(const Entity& entity)
{
    this->_window.draw(entity.getSprite());
}