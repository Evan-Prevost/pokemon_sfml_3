#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "MainCharacter.h"
#include "AnimatedMainCharacter.h"

#include "ConfigMainCharacter.h"
#include "ConfigMap.h"
#include "ConfigPokemonSprites.h"

#include "GameWindow.h"
#include "Entity.h"
#include "TileMap.h"
#include "TextBox.h"
#include "Button.h"
#include "PauseMenu.h"
#include "AnimatedPokemon.h"

int main()
{
    GameWindow window;
    sf::Font font;
    if (!font.loadFromFile("data/assets/font3.ttf"))
        return -1;

    // musiques
    sf::Music menu, main, fight;
    
    menu.setVolume(50.f);
    main.setVolume(20.f);
    fight.setVolume(50.f);

    if (!menu.openFromFile("data/sound/music/menuTheme.wav"))
    {
        std::cout << "ERROR" << std::endl;
    }
    if (!main.openFromFile("data/sound/music/mainTheme.wav"))
    {
        std::cout << "ERROR" << std::endl;
    }
    if (!fight.openFromFile("data/sound/music/fightTheme.wav"))
    {
        std::cout << "ERROR" << std::endl;
    }

    // Boxes' texture
    sf::Texture textureButton;
    if (!textureButton.loadFromFile("data/assets/boxes/100x30.png"))
        return -1;

    sf::Texture texturePauseBG;
    if (!texturePauseBG.loadFromFile("data/assets/boxes/200x100.png"))
        return -1;

    
    int currentWindow = 0;
    sf::Vector2f lastCharacterPosition(INITIAL_POS);

    bool gameOn = true;
    while (gameOn) {
        if (currentWindow == 0) { 
            
            //menu

            
            menu.play();

            sf::Texture textureTitle;
            if (!textureTitle.loadFromFile("data/assets/background/title.png"))
                return -1;
            Entity title = Entity(textureTitle);
            title.setPosition(0, -180);

            sf::Texture textureSky;
            if (!textureSky.loadFromFile("data/assets/background/titleBackgroundSky.png"))
                return -1;
            Entity sky = Entity(textureSky);
            Entity sky2 = Entity(textureSky);
            sky2.setPosition(490, 0);

            sf::Texture textureSea;
            if (!textureSea.loadFromFile("data/assets/background/titleBackgroundSea.png"))
                return -1;
            Entity sea = Entity(textureSea);

            sf::Texture textureGround;
            if (!textureGround.loadFromFile("data/assets/background/titleBackgroundGround.png"))
                return -1;
            Entity ground = Entity(textureGround);
            Entity ground2 = Entity(textureGround);
            ground2.setPosition(490, 0);

            sf::Texture textureCharacter;
            if (!textureCharacter.loadFromFile(MAIN_CHARACTER_TEXTURE_PATH))
                return -1;
            MainCharacter mainCharacter = MainCharacter(textureCharacter);
            mainCharacter.setPosition(-100, 100);
            mainCharacter.setScale(3,3);

            /*sf::Texture textureBG;
            if (!textureBG.loadFromFile("data/assets/titleBackground.png"))
                return -1;
            Entity background = Entity(textureBG);*/
            

            Button startButton = Button(textureButton, font, "START");
            startButton.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2);

            Button quitButton = Button(textureButton, font, "QUIT");
            quitButton.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2 + 40);
            
            int countFrame = 0;
            while (window.isOpen() && currentWindow == 0) {
                window.clear();
                //inputs
                int result = window.handleEventsQuit();
                if (result == 1) {
                    gameOn = false;
                }
                else if (window.isPressed(startButton)) {
                    currentWindow = 1;
                    menu.stop();
                }
                else if (window.isPressed(quitButton)) {
                    window._window.close();
                    menu.stop();
                    gameOn = false;
                }

                //animations
                sky.getSprite().move(-1, 0);
                if (sky.getSprite().getPosition().x <= -490) {
                    sky.setPosition(490, 0);
                }
                ground.getSprite().move(-3, 0);
                if (ground.getSprite().getPosition().x <= -490) {
                    ground.setPosition(490, 0);
                }
                sky2.getSprite().move(-1, 0);
                if (sky2.getSprite().getPosition().x <= -490) {
                    sky2.setPosition(490, 0);
                }
                ground2.getSprite().move(-3, 0);
                if (ground2.getSprite().getPosition().x <= -490) {
                    ground2.setPosition(490, 0);
                }
                
                if (title.getSprite().getPosition().y < 0) {
                    title.getSprite().move(0, 1);
                }

                if (title.getSprite().getPosition().y >= 0 && mainCharacter.getSprite().getPosition().x < 10) {
                    mainCharacter.getSprite().move(1, 0);
                }
                if (countFrame % 10 == 0) {
                    mainCharacter.nextAnimation();
                    countFrame = 0;
                }
                countFrame++;


                //drawings
                //window.drawEntity(background);

                window.drawEntity(sky);
                window.drawEntity(sky2);
                window.drawEntity(sea);
                window.drawEntity(ground);
                window.drawEntity(ground2);
                window.drawEntity(title);
                window.drawEntity(mainCharacter);

                if (title.getSprite().getPosition().y >= 0) {
                    window.drawButton(startButton);
                    window.drawButton(quitButton);
                }
                window.display();
            }
        }
        else if (currentWindow == 1) { //=====MAIN GAME=====
            
            // stop playback and rewind
            
            main.play();

            //Game
            window._view.setCenter(lastCharacterPosition);

            //character
            sf::Texture textureCharacter;
            if (!textureCharacter.loadFromFile(MAIN_CHARACTER_TEXTURE_PATH))
                return -1;
            MainCharacter mainCharacter = MainCharacter(textureCharacter);
            mainCharacter.setPosition(lastCharacterPosition.x, lastCharacterPosition.y);
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
            /*if (!CollisionsVisible.load(TILE_MAP_PATH, sf::Vector2u(12, 12), collisionsVisible, 70, 40))
                return -1;*/
            /*if (!Collisions.load(TILE_MAP_PATH, sf::Vector2u(12, 12), collisions, 70, 40))
                return -1;*/
            /*if (!Battle_zones.load(TILE_MAP_PATH, sf::Vector2u(12, 12), battle_zones, 70, 40))
                return -1;*/
            if (!Foreground_objects.load(TILE_MAP_PATH, sf::Vector2u(12, 12), foreground_objects, 70, 40))
                return -1;

            int countFrame = 0;
            while (window.isOpen() && currentWindow == 1)
            {
                if (window.isPause()) {

                    main.pause();

                    window.handleEventsQuit();
                    int result = window.handleEventsQuit();
                    if(result == 1) {
                        gameOn = false;
                        //pause.setPosition(window._view.getCenter().x - pauseTexture.getSize().x / 2, window._view.getCenter().y - pauseTexture.getSize().y / 2);
                        //window.drawPause(pause);
                    }
                    else if (window.isPressed(pause._resume)) {
                        // resume playback
                        main.play();
                        window._pause = false;
                    }
                    else if (window.isPressed(pause._quit)) {
                        window._window.close();
                        main.stop();
                        gameOn = false;
                    }
                    window.drawPause(pause);
                
                }
                else {
                    window.clear();
                    int result = window.handleEventsGame();
                    if (result == 1) { // close program
                        gameOn = false;
                    }
                    
                    else if (result == 3) { // combat
                        currentWindow = 2;
                        main.stop();
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

                        //// character
                        window.drawSprite(mainCharacter.getBoxCollision());
                        window.drawEntity(mainCharacter);

                        //// foreground objects
                        window.drawMap(Foreground_objects);

                        // Collisions
                        //gameWindow.drawMap(collisions);

                        // debuging
                        //window.drawMap(CollisionsVisible);
                        //gameWindow.drawMap(Battle_zones);
                    }
                    if (result == 2) { // pause
                        pause.setPosition(window._view.getCenter());
                    }
                    
                }
                // display window
                window.display();
            }
        }
        else if (currentWindow == 2) { // Combat

            //medias

            fight.play();

            window._view.setCenter(320.f/2,180.f/2);

            sf::Texture textureBG;
            if (!textureBG.loadFromFile("data/assets/fightBackground.png"))
                return -1;
            Entity background = Entity(textureBG);

            sf::Texture texturePokemon1;
            if (!texturePokemon1.loadFromFile(BULBIZARRE_TEXTURE_PATH))
                return -1;
            int pokemon1Infos[3]BULBIZARRE_SPRITE_INFOS;
            AnimatedPokemon pokemon1 = AnimatedPokemon(texturePokemon1, pokemon1Infos);
            pokemon1.setScale(-1, 1);
            pokemon1.setPosition(100 + pokemon1.getWidth() / 2, 105 - pokemon1.getHeight());


            sf::Texture texturePokemon2;
            if (!texturePokemon2.loadFromFile(SALAMECHE_TEXTURE_PATH))
                return -1;
            int pokemon2Infos[3]SALAMECHE_SPRITE_INFOS;
            AnimatedPokemon pokemon2 = AnimatedPokemon(texturePokemon2, pokemon2Infos);
            pokemon2.setPosition(219 - pokemon2.getWidth()/2, 105 - pokemon2.getHeight());

            PauseMenu pause = PauseMenu(texturePauseBG, textureButton, font);

            //combat loop

            int countFrame = 0;
            while (window.isOpen() && currentWindow == 2)
            {
                if (window.isPause()) { //pause

                    fight.pause();

                    window.handleEventsQuit();
                    int result = window.handleEventsQuit();
                    if (result == 1) {
                        gameOn = false;
                    }
                    else if (window.isPressed(pause._resume)) {
                        fight.play();
                        window._pause = false;
                    }
                    else if (window.isPressed(pause._quit)) {
                        window._window.close();
                        fight.stop();
                        gameOn = false;
                    }
                    window.drawPause(pause);

                }
                else {  // main
                    window.clear();
                    int result = window.handleEventsCombat();
                    if (result == 1) {
                        gameOn = false;
                    }
                    else {

                        if (countFrame % 10 == 0)
                        {
                            pokemon1.nextAnimation();
                            pokemon2.nextAnimation();
                            countFrame = 0;
                        }
                        countFrame++;

                        //drawings
                        window.drawEntity(background);
                        window.drawEntity(pokemon1);
                        window.drawEntity(pokemon2);
                    }
                    if (result == 2) {
                        pause.setPosition(window._view.getCenter());
                    }
                }
                window.display();
            }
        }
    }
    return 0;
}