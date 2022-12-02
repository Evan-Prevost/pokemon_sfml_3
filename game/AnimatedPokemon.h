#pragma once

#include "Entity.h"

class AnimatedPokemon : public Entity
{
protected:
    int _currentFrame = 0;
    int _width;
    int _height;
    int _frames;
    /*bool moving = false;*/

public:
    AnimatedPokemon(const sf::Texture&, int infos[]);
    void nextAnimation(void);

    int getWidth(void);
    int getHeight(void);
};