//
// Created by alissa on 21/07/24.
//

#include "Projetil.hpp"

#include <utility>

Projetil::Projetil(sf::Vector2f dir, sf::RectangleShape proj) {
    this->direcao = dir;
    this->projetil = proj;
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

}
