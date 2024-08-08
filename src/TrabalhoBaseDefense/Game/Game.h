#ifndef SRC_TRABALHOBASEDEFENSE_GAME_H
#define SRC_TRABALHOBASEDEFENSE_GAME_H


#include "SFML/Graphics/RenderWindow.hpp"
#include "../Logger/Logger.hpp"

class Game {
private:

    void update(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    void setup();
    void drawText(sf::RenderWindow &window);
    void spawnInimigo();
public:
    void run();

    void calculateColisions();
};


#endif //SRC_TRABALHOBASEDEFENSE_GAME_H
