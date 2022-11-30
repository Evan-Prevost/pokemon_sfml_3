#include "TextBox.h"


/*Button::Button(const sf::Texture& texture) : Entity(texture) {

}*/

TextBox::TextBox(const sf::Texture& texture, const sf::Font& font, std::string string) : Entity(texture) {
    this->_font = font;
    this->_text.setFont(this->_font);
    this->_text.setString(string);
}


const sf::Text& TextBox::getText() const {
    return this->_text;
}

void TextBox::setText(std::string string) {
    this->_text.setString(string);
}


