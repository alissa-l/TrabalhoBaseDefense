#include "DropavelMunicao.h"

Dropavel DropavelMunicao::get() {
    sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(10, 10));
    shape.setFillColor(sf::Color::Green);
    Dropavel dropavel = {shape, sf::Vector2f(0, 0), 0};
    dropavel.setStrategy(new DropavelMunicaoStrategy());
    return dropavel;
}
