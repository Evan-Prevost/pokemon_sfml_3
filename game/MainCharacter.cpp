#include "MainCharacter.h"
#include "ConfigMainCharacter.h"
#include <iostream>
using namespace std;

MainCharacter::MainCharacter(const sf::Texture& texture) : boxCollision(sf::Vector2f(15.f, 15.f)), AnimatedMainCharacter(texture, std::vector< std::vector<sf::IntRect>>(MAIN_CHARACTER_ANIMS_RECT))
{
	this->boxCollision.setFillColor(sf::Color(100, 250, 50));
	sf::Vector2f position = _sprite.getPosition();
}

const sf::RectangleShape& MainCharacter::getBoxCollision() const
{
	return this->boxCollision;
}