#pragma once

#include <SFML/Window.hpp>
#include "Entity.h"
#include "MapArray.h"
#include "TileMap.h"
#include "TextBox.h"
#include "Button.h"
#include "PauseMenu.h"

class GameWindow
{
public:

    sf::RenderWindow _window;
    sf::View _view;
    bool _pause = false;

    GameWindow(void);
    //
    bool isOpen(void) const;
    bool isPause(void);

    int handleEventsGame(void);
    int handleEventsQuit(void);
    int handleEventsCombat(void);

    void clear(void);
    void display(void);

    sf::Vector2f getSize(void);
    //void setView();
    
    //
    void drawEntity(const Entity&);
    void drawSprite(const sf::Drawable&);
    void drawMap(const TileMap&);
    void drawTextBox(const TextBox&);
    void drawButton(const Button&);
    void drawPause(const PauseMenu&);

    bool isPressed(const Button&);
};