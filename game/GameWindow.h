#pragma once

#include <SFML/Window.hpp>
#include "Entity.h"
#include "MapArray.h"
#include "TileMap.h"
#include "Button.h"

class GameWindow
{
private:
    bool _pause = false;

public:

    sf::RenderWindow _window;
    sf::View _view;

    GameWindow(void);
    //
    bool isOpen(void) const;
    bool isPause(void);

    int handleEventsMenu(void);
    int handleEventsGame(void);
    int handleEventsPause(void);

    void clear(void);
    void display(void);

    sf::Vector2f getSize(void);
    //void setView();
    
    //
    void drawEntity(const Entity&);
    void drawMap(const TileMap&);
    void drawButton(const Button&);
};