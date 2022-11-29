#include "MainCharacter.h"
#include "ConfigMainCharacter.h"

MainCharacter::MainCharacter(const sf::Texture& texture) : AnimatedMainCharacter(texture, std::vector< std::vector<sf::IntRect>>(MAIN_CHARACTER_ANIMS_RECT))
{
}