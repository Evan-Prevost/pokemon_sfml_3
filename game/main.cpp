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
    GameWindow window;

    int countFrame = 0;
    int currentWindow = 0;
    bool gameOn = true;
    while (gameOn) {
        if (currentWindow == 0) { //menu
            

            sf::Texture textureBG;
            if (!textureBG.loadFromFile(MENU_BACKGROUND_PATH))
                return -1;
            Entity background = Entity(textureBG);

            sf::Texture textureSB;
            if (!textureSB.loadFromFile(MENU_STARTBUTTON_PATH))
                return -1;
            Entity start = Entity(textureSB);
            start.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2);


            while (window.isOpen() && currentWindow == 0) {
                window.clear();
                int x = window.handleEventsMenu();
                std::cout << currentWindow;
                switch (x) {
                case 1:
                    gameOn = false;
                    std::cout << "in 1";
                case 2:
                    currentWindow = 1;
                    std::cout << "in 2";
                }
                window.drawEntity(background);
                window.drawEntity(start);
                window.display();
            }
        }
        else if (currentWindow == 1) { //Game
            

            //character
            sf::Texture texture;
            if (!texture.loadFromFile(MAIN_CHARACTER_TEXTURE_PATH))
                return -1;
            MainCharacter mainCharacter = MainCharacter(texture);
            mainCharacter.setPosition(300.f, 210.f);

            //pause
            sf::Texture pauseTexture;
            if (!pauseTexture.loadFromFile("data/assets/pause.png"))
                return -1;
            Entity pause = Entity(pauseTexture);
            pause.setPosition(INITIAL_VIEW_RECT.left, INITIAL_VIEW_RECT.top);

            //tilemap
            TileMap Ocean, Island, Trees_1, Trees_2, Trees_3, Plateau, Flower_grass, Bushes, Fence, House_trees, House, Dock/*, Collisions*//*, Battle_zones*/, Foreground_objects;

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
            //if (!Collisions.load(COLLISION_MAP_PATH, sf::Vector2u(12, 12), collisions, 70, 40))
            //    return -1;
            //if (!Battle_zones.load(TILE_MAP_PATH, sf::Vector2u(12, 12), battle_zones, 70, 40))
            //    return -1;
            if (!Foreground_objects.load(TILE_MAP_PATH, sf::Vector2u(12, 12), foreground_objects, 70, 40))
                return -1;

            while (window.isOpen())
            {
                if (window.isPause()) {
                    window.handleEventsPause();
                    window.drawEntity(pause);
                }
                else {
                    window.clear();
                    window.handleEventsGame();

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
                    window.drawMap(Ocean);
                    window.drawMap(Island);
                    window.drawMap(Trees_1);
                    window.drawMap(Trees_2);
                    window.drawMap(Trees_3);
                    window.drawMap(Plateau);
                    window.drawMap(Flower_grass);

                    //// objects
                    window.drawMap(Bushes);
                    window.drawMap(Fence);
                    window.drawMap(House_trees);
                    window.drawMap(House);
                    window.drawMap(Dock);

                    // debuging
                    //window.drawMap(Collisions);
                    //window.drawMap(Battle_zones);

                    //// character
                    window.drawEntity(mainCharacter);

                    //// foreground objects
                    window.drawMap(Foreground_objects);
                }
                // display window
                window.display();

            }
        }
    }
    return 0;
}