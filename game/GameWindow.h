#pragma once

#include <SFML/Window.hpp>
#include "Entity.h"

class GameWindow
{
private:
    sf::RenderWindow _window;
    sf::View _view;

public:
    GameWindow(void);
    //
    bool isOpen(void) const;
    void handleEvents(void);
    void clear(void);
    void display(void);

    //
    void drawEntity(const Entity&);
};