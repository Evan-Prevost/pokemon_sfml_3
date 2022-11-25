#include "MainCharacter.h"
#include "ConfigMainCharacter.h"

MainCharacter::MainCharacter(const sf::Texture& texture) : AnimatedMainCharacter(texture, std::vector<sf::IntRect>(MAIN_CHARACTER_ANIM_RECT))
{

}