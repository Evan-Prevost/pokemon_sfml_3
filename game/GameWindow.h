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

    int handleEventsMenu(void);
    int handleEventsGame(void);
    int handleEventsPause(void);

    void clear(void);
    void display(void);

    sf::Vector2f getSize(void);
    //void setView();
    
    //
    void drawEntity(const Entity&);
    void drawSprite(const sf::Drawable&);
    void drawMap(const TileMap&);
    bool isPause(void);
};