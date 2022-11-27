#pragma once

#include <SFML/Window.hpp>
#include "Entity.h"
#include "MapArray.h"
#include "TileMap.h"

class GameWindow
{
private:
    sf::RenderWindow _window;
    sf::View _view;
    bool _pause = false;

public:
    GameWindow(void);
    //
    bool isOpen(void) const;
    void handleEventsGame(void);
    void handleEventsPause(void);
    void clear(void);
    void display(void);
    
    //
    void drawEntity(const Entity&);
    void drawMap(const TileMap&);
    bool isPause(void);
};