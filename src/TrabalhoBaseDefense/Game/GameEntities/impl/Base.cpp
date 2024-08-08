//
// Created by alissa on 25/07/24.
//

#include <iostream>
#include "Base.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../Variables/Variables.h"


Base::Base(int vida, sf::RectangleShape base) {

}

const sf::RectangleShape &Base::getBase() const {
    return base;
}

void Base::setBase(const sf::RectangleShape &base) {
    Base::base = base;
}

int Base::getVida() const {
    return vida;
}

void Base::setVida(int vida) {
    Base::vida = vida;
}

void Base::load() {
    vida = Variables().baseLife;

    base = sf::RectangleShape(sf::Vector2f(Variables().baseTamX, Variables().baseTamY));
    base.setFillColor(sf::Color::Transparent);
    base.setOutlineThickness(5);
    base.setOutlineColor(sf::Color::Black);

    base.setPosition(Variables().basePosX, Variables().basePosY);
}

void Base::draw(sf::RenderWindow &window) {
    window.draw(base);
}

void Base::update() {
}

Base::Base() {
}
