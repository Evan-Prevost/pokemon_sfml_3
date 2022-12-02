#pragma once

#include "AnimatedPokemon.h"
#include <iostream>


AnimatedPokemon::AnimatedPokemon(const sf::Texture& texture, int infos[]) : Entity(texture) {
	this->_width = infos[0];
	this->_height = infos[1];
	this->_frames = infos[2];

	this->_sprite.setTextureRect(sf::IntRect(0, 0, this->_width, this->_height));

}

void AnimatedPokemon::nextAnimation(void) {
	this->_currentFrame++;

	if (this->_currentFrame >= this->_frames)
	{
		this->_currentFrame = 0;
	}

	/*std::cout << this->_currentFrame;
	std::cout << " ";
	std::cout << this->_currentFrame%5 * this->_width;
	std::cout << " ";
	std::cout << this->_currentFrame/5 * this->_height;
	std::cout << std::endl;*/

	this->_sprite.setTextureRect(sf::IntRect(this->_width * (this->_currentFrame % 5), this->_height * (this->_currentFrame / 5), this->_width-1, this->_height-1));
}

int AnimatedPokemon::getWidth(void) {
	return this->_width;
}

int AnimatedPokemon::getHeight(void) {
	return this->_height;
}