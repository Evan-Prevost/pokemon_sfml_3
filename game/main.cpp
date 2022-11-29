#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "MainCharacter.h"
#include "AnimatedMainCharacter.h"
#include "ConfigMainCharacter.h"
#include "ConfigMap.h"
#include "GameWindow.h"
#include "Entity.h"
#include "TileMap.h"


int main()
{
    GameWindow gameWindow;

    sf::Texture texture;
    if (!texture.loadFromFile(MAIN_CHARACTER_TEXTURE_PATH))
    {
        // error...
    }

    sf::Texture pauseTexture;
    if (!pauseTexture.loadFromFile("data/assets/pause.png"))
        return -1;

    Entity pause = Entity(pauseTexture);
    pause.setPosition(INITIAL_VIEW_RECT.left, INITIAL_VIEW_RECT.top);



    // on cr�e la tilemap
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

    MainCharacter mainCharacter = MainCharacter(texture);

    // init main character position
    mainCharacter.setPosition(300.f, 210.f);


    int countFrame = 0;

    while (gameWindow.isOpen())
    {
        if (gameWindow.isPause()) {
            gameWindow.handleEventsPause();
            gameWindow.drawEntity(pause);
        }
        else {
            gameWindow.clear();
            gameWindow.handleEventsGame();
            
            // camera folow character
            /*gameWindow._view(mainCharacter);*/

            // movement main character
            mainCharacter.handKeys();

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

            // debuging
            //gameWindow.drawMap(Collisions);
            //gameWindow.drawMap(Battle_zones);

            //// character
            gameWindow.drawEntity(mainCharacter);

            //// foreground objects
            gameWindow.drawMap(Foreground_objects);
        }
        // display gameWindow
        gameWindow.display();

    }
    
    return 0;
}