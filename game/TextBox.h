#pragma once

#include <SFML/Window.hpp>
#include <string>

#include "Entity.h"

class TextBox : public Entity {
protected :
	sf::Font _font;
	sf::Text _text;
	
public :
	TextBox();
	TextBox(const sf::Texture& texture, const sf::Font& font , std::string string);

	const sf::Text& getText() const;
	void setText(std::string);
	void setPosition(float x, float y);
};