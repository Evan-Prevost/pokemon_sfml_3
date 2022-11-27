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
    GameWindow window;

    sf::Texture texture;
    if (!texture.loadFromFile(MAIN_CHARACTER_DOWN_TEXTURE_PATH))
    {
        // error...
    }

    // on cr�e la tilemap
    TileMap Ocean, Island, Trees_1, Trees_2, Trees_3, Plateau, Flower_grass, Bushes, Fence, House_trees, House, Dock/*, Collisions*//*, Battle_zones*/, Foreground_objects;

    if (!Ocean.load(MAP_PATH, sf::Vector2u(12, 12), ocean, 70, 40))
        return -1;
    if (!Island.load(MAP_PATH, sf::Vector2u(12, 12), island, 70, 40))
        return -1;
    if (!Trees_1.load(MAP_PATH, sf::Vector2u(12, 12), trees_1, 70, 40))
        return -1;
    if (!Trees_2.load(MAP_PATH, sf::Vector2u(12, 12), trees_2, 70, 40))
        return -1;
    if (!Trees_3.load(MAP_PATH, sf::Vector2u(12, 12), trees_3, 70, 40))
        return -1;
    if (!Plateau.load(MAP_PATH, sf::Vector2u(12, 12), plateau, 70, 40))
        return -1;
    if (!Flower_grass.load(MAP_PATH, sf::Vector2u(12, 12), flower_grass, 70, 40))
        return -1;
    if (!Bushes.load(MAP_PATH, sf::Vector2u(12, 12), bushes, 70, 40))
        return -1;
    if (!Fence.load(MAP_PATH, sf::Vector2u(12, 12), fence, 70, 40))
        return -1;
    if (!House_trees.load(MAP_PATH, sf::Vector2u(12, 12), house_trees, 70, 40))
        return -1;
    if (!House.load(MAP_PATH, sf::Vector2u(12, 12), house, 70, 40))
        return -1;
    if (!Dock.load(MAP_PATH, sf::Vector2u(12, 12), dock, 70, 40))
        return -1;
    //if (!Collisions.load(MAP_PATH, sf::Vector2u(12, 12), collisions, 70, 40))
    //    return -1;
    //if (!Battle_zones.load(MAP_PATH, sf::Vector2u(12, 12), battle_zones, 70, 40))
    //    return -1;
    if (!Foreground_objects.load(MAP_PATH, sf::Vector2u(12, 12), foreground_objects, 70, 40))
        return -1;

    MainCharacter mainCharacter = MainCharacter(texture);

    // init main character position
    mainCharacter.setPosition(120.f, 60.f);

    int countFrame = 0;
    while (window.isOpen())
    {
        window.clear();
        window.handleEvents();
        //window.handKeys();
        if (countFrame % 15 == 0)
        {
            mainCharacter.nextAnimation();
            countFrame = 0;
        }
        countFrame++;

        // draw map
        window.drawMap(Ocean);
        window.drawMap(Island);
        window.drawMap(Trees_1);
        window.drawMap(Trees_2);
        window.drawMap(Trees_3);
        window.drawMap(Plateau);
        window.drawMap(Flower_grass);
        window.drawMap(Bushes);
        window.drawMap(Fence);
        window.drawMap(House_trees);
        window.drawMap(House);
        window.drawMap(Dock);
        //window.drawMap(Collisions);
        //window.drawMap(Battle_zones);
        window.drawMap(Foreground_objects);
        window.drawEntity(mainCharacter);

        // display window
        window.display();

    }
    
    return 0;
}