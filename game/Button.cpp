#include "Button.h"

Button::Button(const sf::Texture& texture, const sf::Font& font, std::string string) : TextBox(texture, font, string) {

}

void Button::setPosition(float x, float y)
{
    Entity::setPosition(x, y);
    //sf::Vector2u size = this->_sprite.getTexture()->getSize();
    //this->_text.setPosition(x+size/2-  , y);
    this->_text.setPosition(x + 10, y + 10);
}

bool Button::isPressed(GameWindow* window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window->_window);

        int ratio = window->_window.getSize().x / window->_view.getSize().x;

        sf::Vector2f spritePosition = this->_sprite.getPosition();
        sf::Vector2u spriteSize = this->_sprite.getTexture()->getSize();

        if (mousePosition.x / ratio >= spritePosition.x / ratio
            && mousePosition.x / ratio <= spritePosition.x / ratio + spriteSize.x
            && mousePosition.y / ratio >= spritePosition.y / ratio
            && mousePosition.y / ratio <= spritePosition.y / ratio + spriteSize.y) 
        {
            return true;
        }
    }
    return false;
}