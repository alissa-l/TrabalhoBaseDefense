#include "DropavelVidaBase.h"

Dropavel DropavelVidaBase::get() {
    sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(20, 30));
    shape.setFillColor(sf::Color::Black);
    Dropavel dropavel = {shape, sf::Vector2f(0, 0), 0};
    dropavel.setStrategy(new DropavelVidaBaseStrategy());
    return dropavel;
}
