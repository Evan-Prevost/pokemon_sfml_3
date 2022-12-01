#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedMainCharacter.h"
#include "GameWindow.h"

class MainCharacter : public AnimatedMainCharacter
{
public:
	MainCharacter(const sf::Texture& texture);
};