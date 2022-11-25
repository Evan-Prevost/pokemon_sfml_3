#pragma once

#include "AnimatedMainCharacter.h"

class MainCharacter : public AnimatedMainCharacter
{
private:
	sf::Transformable _transformable;
public :
	MainCharacter(const sf::Texture& texture);
};