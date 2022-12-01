#include "Button.h"

Button::Button() : TextBox() {}

Button::Button(const sf::Texture& texture, const sf::Font& font, std::string string) : TextBox(texture, font, string) 
{}

void Button::setPosition(float x, float y)
{
    TextBox::setPosition(x, y);
}