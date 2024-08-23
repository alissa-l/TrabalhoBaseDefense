#include "Projetil.hpp"
#include "../../Variables/Variables.h"

#include <utility>
#include <iostream>

Projetil::Projetil() {
    friendly = false;
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

bool Projetil::getFriendly() {
    return this->friendly;
}

void Projetil::setFriendly(bool friendly1) {
    this->friendly = friendly1;
}

bool Projetil::getJaColidiu() {
    return jaColidiu;
}

void Projetil::setJaColidiu(bool jaColidiu1) {
    jaColidiu = jaColidiu1;
}
