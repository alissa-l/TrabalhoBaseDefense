//
// Created by alissa on 22/07/24.
//

#include "Inimigo.hpp"

Inimigo::Inimigo(sf::RectangleShape shape, int v) {
    this->inimigoShape = shape;
    this->vida = v;
}

sf::RectangleShape Inimigo::getInimigoShape() {
    return this->inimigoShape;
}

void Inimigo::setInimigoShape(sf::RectangleShape shape) {
    this->inimigoShape = shape;
}

int Inimigo::getVida() {
    return this->vida;
}

void Inimigo::setVida(int vida) {
    this->vida = vida;
}


