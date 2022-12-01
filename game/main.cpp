#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "MainCharacter.h"
#include "AnimatedMainCharacter.h"
#include "ConfigMainCharacter.h"
#include "ConfigMap.h"
#include "GameWindow.h"
#include "MenuWindow.h"
#include "Entity.h"
#include "TileMap.h"
#include "TextBox.h"
#include "Button.h"
#include "PauseMenu.h"

int main()
{
    GameWindow window;
    sf::Font font;
    if (!font.loadFromFile("data/assets/font3.ttf"))
        return -1;

    sf::Texture textureButton;
    if (!textureButton.loadFromFile("data/assets/boxes/100x30.png"))
        return -1;

    sf::Texture texturePauseBG;
    if (!texturePauseBG.loadFromFile("data/assets/boxes/200x100.png"))
        return -1;

    int countFrame = 0;
    int currentWindow = 0;
    bool gameOn = true;
    while (gameOn) {
        if (currentWindow == 0) { //menu
            

            sf::Texture textureBG;
            if (!textureBG.loadFromFile(BACKGROUND_PATH))
                return -1;
            Entity background = Entity(textureBG);

            sf::Texture textureSB;
            if (!textureSB.loadFromFile(MENU_STARTBUTTON_PATH))
                return -1;
            Entity start = Entity(textureSB);
            start.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2);

            Button startButton = Button(textureButton, font, "START");
            startButton.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2);

            Button quitButton = Button(textureButton, font, "QUIT");
            quitButton.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2 + 40);
            

            while (window.isOpen() && currentWindow == 0) {
                window.clear();
                int result = window.handleEventsMenu();
                if (result == 1) {
                    gameOn = false;
                }
                else if (window.isPressed(startButton)) {
                    currentWindow = 1;
                }
                window.drawEntity(background);
                window.drawButton(startButton);
                window.display();
            }
        }
        else if (currentWindow == 1) { //Game
            window._view.setCenter(INITIAL_POS);

            //character
            sf::Texture textureCharacter;
            if (!textureCharacter.loadFromFile(MAIN_CHARACTER_TEXTURE_PATH))
                return -1;
            MainCharacter mainCharacter = MainCharacter(textureCharacter);
            mainCharacter.setPosition(300.f, 210.f);
            mainCharacter.setPositionBoxCollider(306.f, 224.f);

            //pause
            PauseMenu pause = PauseMenu(texturePauseBG, textureButton, font);

            // on crée la tilemap
            TileMap Ocean, Island, Trees_1, Trees_2, Trees_3, Plateau, Flower_grass, Bushes, Fence, House_trees, House, Dock, CollisionsVisible /*,Collisions*/ /*, Battle_zones*/, Foreground_objects;

            if (!Ocean.load(TILE_MAP_PATH, sf::Vector2u(12, 12), ocean, 70, 40))
                return -1;
            if (!Island.load(TILE_MAP_PATH, sf::Vector2u(12, 12), island, 70, 40))
                return -1;
            if (!Trees_1.load(TILE_MAP_PATH, sf::Vector2u(12, 12), trees_1, 70, 40))
                return -1;
            if (!Trees_2.load(TILE_MAP_PATH, sf::Vector2u(12, 12), trees_2, 70, 40))
                return -1;
            if (!Trees_3.load(TILE_MAP_PATH, sf::Vector2u(12, 12), trees_3, 70, 40))
                return -1;
            if (!Plateau.load(TILE_MAP_PATH, sf::Vector2u(12, 12), plateau, 70, 40))
                return -1;
            if (!Flower_grass.load(TILE_MAP_PATH, sf::Vector2u(12, 12), flower_grass, 70, 40))
                return -1;
            if (!Bushes.load(TILE_MAP_PATH, sf::Vector2u(12, 12), bushes, 70, 40))
                return -1;
            if (!Fence.load(TILE_MAP_PATH, sf::Vector2u(12, 12), fence, 70, 40))
                return -1;
            if (!House_trees.load(TILE_MAP_PATH, sf::Vector2u(12, 12), house_trees, 70, 40))
                return -1;
            if (!House.load(TILE_MAP_PATH, sf::Vector2u(12, 12), house, 70, 40))
                return -1;
            if (!Dock.load(TILE_MAP_PATH, sf::Vector2u(12, 12), dock, 70, 40))
                return -1;
            if (!CollisionsVisible.load(TILE_MAP_PATH, sf::Vector2u(12, 12), collisionsVisible, 70, 40))
                return -1;
            //if (!Collisions.load(TILE_MAP_PATH, sf::Vector2u(12, 12), collisions, 70, 40))
            //    return -1;
            //if (!Battle_zones.load(TILE_MAP_PATH, sf::Vector2u(12, 12), battle_zones, 70, 40))
            //    return -1;
            if (!Foreground_objects.load(TILE_MAP_PATH, sf::Vector2u(12, 12), foreground_objects, 70, 40))
                return -1;

            while (gameWindow.isOpen())
            {
                if (window.isPause()) {
                    window.handleEventsPause();
                    int result = window.handleEventsPause();
                    if(result == 1) {
                        gameOn = false;
                        //pause.setPosition(window._view.getCenter().x - pauseTexture.getSize().x / 2, window._view.getCenter().y - pauseTexture.getSize().y / 2);
                        //window.drawPause(pause);
                    }
                    else if (window.isPressed(pause._resume)) {
                        window._pause = false;
                    }
                    else if (window.isPressed(pause._quit)) {
                        window._window.close();
                        gameOn = false;
                    }
                    window.drawPause(pause);
                }
                else {
                    window.clear();
                    int result = window.handleEventsGame();
                    if (result == 1) {
                        gameOn = false;
                    }
                    else {
                        // camera folow character
                        /*window._view(mainCharacter);*/

                        // movement main character
                        mainCharacter.handKeys(window._view);

                        if (countFrame % 15 == 0)
                        {
                            mainCharacter.nextAnimation();
                            countFrame = 0;
                        }
                        countFrame++;

                        // build map

                        // core
                        gameWindow.drawMap(Ocean);
                        gameWindow.drawMap(Island);
                        gameWindow.drawMap(Trees_1);
                        gameWindow.drawMap(Trees_2);
                        gameWindow.drawMap(Trees_3);
                        gameWindow.drawMap(Plateau);
                        gameWindow.drawMap(Flower_grass);

                        //// objects
                        gameWindow.drawMap(Bushes);
                        gameWindow.drawMap(Fence);
                        gameWindow.drawMap(House_trees);
                        gameWindow.drawMap(House);
                        gameWindow.drawMap(Dock);

                        //// character
                        gameWindow.drawSprite(mainCharacter.getBoxCollision());
                        gameWindow.drawEntity(mainCharacter);

                        //// foreground objects
                        gameWindow.drawMap(Foreground_objects);

                        // Collisions
                        //gameWindow.drawMap(collisions);

                        // debuging
                        gameWindow.drawMap(CollisionsVisible);
                        //gameWindow.drawMap(Battle_zones);
                    }
                    // display gameWindow
                    gameWindow.display();

                }
            }
        }
    }
    return 0;
}