//
// Created by alissa on 21/07/24.
//

#include "Projetil.hpp"
#include "../../Variables/Variables.h"

#include <utility>
#include <iostream>

Projetil::Projetil() {
}

sf::RectangleShape Projetil::getProjetil() {
    return this->projetil;
}

void Projetil::setProjetil(sf::RectangleShape proj) {
    this->projetil = proj;
}

sf::Vector2f Projetil::getDirecao() {
    return this->direcao;
}

void Projetil::setDirecao(sf::Vector2f dir) {
    this->direcao = dir;
}

void Projetil::load() {

}

void Projetil::draw(sf::RenderWindow &window) {
    window.draw(this->projetil);
}

void Projetil::update() {

    sf::RectangleShape newProj = projetil;
    newProj = move(newProj);


    projetil.setPosition(newProj.getPosition());

}

sf::RectangleShape Projetil::move(sf::RectangleShape &proj) {

    proj.setPosition(proj.getPosition() + this->direcao * Variables().projectileSpeed);

    return proj;
}
