#include "DropavelVidaHeroi.h"

Dropavel DropavelVidaHeroi::get() {
    sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(10, 10));
    shape.setFillColor(sf::Color::Red);
    Dropavel dropavel = {shape, sf::Vector2f(0, 0), 0};
    dropavel.setStrategy(new DropavelVidaHeroiStrategy());
    return dropavel;
}
