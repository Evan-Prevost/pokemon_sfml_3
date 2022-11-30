#pragma once

#include <SFML/Window.hpp>
#include <string>

#include "TextBox.h"
#include "GameWindow.h"

class Button : public TextBox {
public:
	Button(const sf::Texture& texture, const sf::Font& font, std::string string);

	void setPosition(float x, float y);

	bool isPressed(GameWindow* window);
};