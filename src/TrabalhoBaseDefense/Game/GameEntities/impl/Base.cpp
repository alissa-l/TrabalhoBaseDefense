//
// Created by alissa on 25/07/24.
//

#include <iostream>
#include "Base.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../Variables/Variables.h"
#include "../../Variables/WindowConstants.h"


Base::Base(int vida, sf::RectangleShape base) {

}

const sf::RectangleShape &Base::getBase() const {
    return baseShape;
}

void Base::setBase(const sf::RectangleShape &base) {
    Base::baseShape = base;
}

int Base::getVida() const {
    return vida;
}

void Base::setVida(int vida) {
    Base::vida = vida;
}

void Base::load() {
    vida = Variables().baseLife;

    baseShape = sf::RectangleShape(sf::Vector2f(Variables().baseTamX, Variables().baseTamY));
    baseShape.setFillColor(sf::Color::Transparent);
    baseShape.setOutlineThickness(5);
    baseShape.setOutlineColor(sf::Color::Black);

    sf::Vector2u windowSize = sf::Vector2u(WindowConstants().tamX, WindowConstants().tamY);

    // Calculate the center position
    sf::Vector2f centerPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

    // Set the position to the center minus half of the rectangle size
    baseShape.setPosition(centerPosition.x - baseShape.getSize().x / 2.0f, centerPosition.y - baseShape.getSize().y / 2.0f);

}

void Base::draw(sf::RenderWindow &window) {
    window.draw(baseShape);
}

void Base::update() {
}

Base::Base() {
}
