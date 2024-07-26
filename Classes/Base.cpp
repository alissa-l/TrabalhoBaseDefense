//
// Created by alissa on 25/07/24.
//

#include "Base.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

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
    this->vida = 100;
}

void Base::draw(sf::RenderWindow &window) {
    window.draw(base);
}

void Base::update() {
}
