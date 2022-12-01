#pragma once

#include <SFML/Window.hpp>
#include "Entity.h"
#include "MapArray.h"
#include "TileMap.h"

class GameWindow
{
private:
    sf::RenderWindow _window;
    bool _pause = false;

public:
    sf::View _view;

    GameWindow(void);
    //
    bool isOpen(void) const;
    void handleEventsGame();
    void handleEventsPause(void);
    void clear(void);
    void display(void);
    
    //
    void drawEntity(const Entity&);
    void drawMap(const TileMap&);
    bool isPause(void);
};