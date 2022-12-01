#pragma once

#include <SFML/Window.hpp>
#include "Entity.h"
#include "MapArray.h"
#include "TileMap.h"

class MenuWindow
{
private:
    sf::RenderWindow _window;
    sf::View _view;

public:
    MenuWindow(void);
    //
    bool isOpen(void) const;
    int handleEvents(void);
    void clear(void);
    void display(void);
    sf::Vector2f getSize(void);

    //
    void drawEntity(const Entity&);
};