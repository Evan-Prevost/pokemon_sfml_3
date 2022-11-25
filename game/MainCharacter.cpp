#include "MainCharacter.h"
#include "ConfigMainCharacter.h"

MainCharacter::MainCharacter(const sf::Texture& texture) : AnimatedMainCharacter(texture, std::vector<sf::IntRect>(MAIN_CHARACTER_DOWN_ANIM_RECT))
{
	this->_transformable.setPosition(30.f, 30.f);
}

