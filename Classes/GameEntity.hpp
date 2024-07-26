#ifndef TRABALHOBASEDEFENSE_GAMEENTITY_HPP
#define TRABALHOBASEDEFENSE_GAMEENTITY_HPP


#include "SFML/Graphics/RenderWindow.hpp"

class GameEntity {
    virtual void load() {}
    virtual void draw(sf::RenderWindow &window) {}
    virtual void update() {}
};


#endif //TRABALHOBASEDEFENSE_GAMEENTITY_HPP
