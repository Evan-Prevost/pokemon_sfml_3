#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "MainCharacter.h"
#include "AnimatedMainCharacter.h"
#include "ConfigMainCharacter.h"
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

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map, map2;
    if (!map.load("data/assets/tileMap/tileSetTest.png", sf::Vector2u(32, 32), level, 16, 8))
        return -1;
    if (!map2.load("data/assets/tileMap/tileSetTest.png", sf::Vector2u(32, 32), level2, 16, 8))
        return -1;

    sf::Texture pauseTexture;
    if (!pauseTexture.loadFromFile("data/assets/pause.png"))
        return -1;

    Entity pause = Entity(pauseTexture);

    MainCharacter mainCharacter = MainCharacter(texture);
    mainCharacter.setPosition(30.f, 30.f);

    int countFrame = 0;
    while (window.isOpen())
    {
        if (window.isPause()) {
            window.handleEventsPause();
            window.drawEntity(pause);
        }
        else {
            window.clear();
            window.handleEventsGame();
            //window.handKeys();
            if (countFrame % 15 == 0)
            {
                mainCharacter.nextAnimation();
                countFrame = 0;
            }
            countFrame++;
            window.drawMap(map);
            window.drawEntity(mainCharacter);
        }
        window.display();

    }
    
    return 0;
}