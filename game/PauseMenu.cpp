#include "PauseMenu.h"
#include <iostream>

PauseMenu::PauseMenu(const sf::Texture& tBackground, const sf::Texture& tBox, const sf::Font& font) :
	_background(tBackground), 
	_header(tBox,font,"PAUSED"),
	_resume(tBox, font, "RESUME"),
	_quit(tBox, font, "QUIT")
{}

void PauseMenu::setPosition(sf::Vector2f center) {
	sf::Vector2i BGSize(this->_background.getSprite().getTexture()->getSize());
	
	//std::cout<< ;
	
	sf::Vector2f BGPosition(center.x - BGSize.x/2, center.y - BGSize.y/2);

	this->_background.setPosition(BGPosition.x,BGPosition.y);
	this->_header.setPosition(BGPosition.x+50, BGPosition.y-15);
	this->_resume.setPosition(BGPosition.x + 50, BGPosition.y + 25);
	this->_quit.setPosition(BGPosition.x + 50, BGPosition.y + 65);
}