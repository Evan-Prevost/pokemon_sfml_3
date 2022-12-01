#pragma once

#include <SFML/Window.hpp>
#include <string>

//#include "TextBox.h"
#include "Button.h"


class PauseMenu {
public :
	Entity _background;
	TextBox _header;
	Button _resume;
	Button _quit;

	PauseMenu(const sf::Texture& tBackground, const sf::Texture& tBox, const sf::Font& font);
	void setPosition(sf::Vector2f center);
};