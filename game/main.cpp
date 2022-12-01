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

int main()
{
    GameWindow gameWindow;

    int countFrame = 0;
    int currentWindow = 0;
    bool gameOn = true;
    while (gameOn) {
        if (currentWindow == 0)
        { //menu
            sf::Texture textureBG;
            if (!textureBG.loadFromFile(MENU_BACKGROUND_PATH))
                return -1;
            Entity background = Entity(textureBG);

            sf::Texture textureSB;
            if (!textureSB.loadFromFile(MENU_STARTBUTTON_PATH))
                return -1;
            Entity start = Entity(textureSB);
            start.setPosition(gameWindow.getSize().x / 2 - 50, gameWindow.getSize().y / 2);


            while (gameWindow.isOpen() && currentWindow == 0) {
                gameWindow.clear();
                int result = gameWindow.handleEventsMenu();
                switch (result) {
                case 1:
                    gameOn = false;
                case 2:
                    currentWindow = 1;
                default:
                    gameWindow.drawEntity(background);
                    gameWindow.drawEntity(start);
                    gameWindow.display();
                }
            }
        }
        else if (currentWindow == 1)
        { //Game
            gameWindow._view.setCenter(INITIAL_POS);

            //character
            sf::Texture texture;
            if (!texture.loadFromFile(MAIN_CHARACTER_TEXTURE_PATH))
                return -1;
            MainCharacter mainCharacter(texture);
            mainCharacter.setPosition(300.f, 210.f);
            mainCharacter.setPositionBoxCollider(306.f, 224.f);

            //pause
            sf::Texture pauseTexture;
            if (!pauseTexture.loadFromFile("data/assets/pause.png"))
                return -1;
            Entity pause = Entity(pauseTexture);
            pause.setPosition(gameWindow._view.getCenter().x - pauseTexture.getSize().x / 2, gameWindow._view.getCenter().y - pauseTexture.getSize().y / 2);

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
                if (gameWindow.isPause()) {
                    gameWindow.handleEventsPause();
                    int result = gameWindow.handleEventsMenu();
                    switch (result) {
                    case 1:
                        gameOn = false;
                    case 2:
                        currentWindow = 1;
                    default:
                        pause.setPosition(gameWindow._view.getCenter().x - pauseTexture.getSize().x / 2, gameWindow._view.getCenter().y - pauseTexture.getSize().y / 2);
                        gameWindow.drawEntity(pause);
                    }
                }
                else {
                    gameWindow.clear();
                    gameWindow.handleEventsGame();
                    int result = gameWindow.handleEventsMenu();
                    switch (result) {
                    default:
                        gameOn = false;
                    case 1:
                        currentWindow = 1;

                // movement main character
                        mainCharacter.handKeys(gameWindow._view);

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