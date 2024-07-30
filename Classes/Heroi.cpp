#include <iostream>
#include "Heroi.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Mouse.hpp"
#include "../Utils/VectorUtils.hpp"
#include "math.h"
#include "Variables.hpp"


void Heroi::setVida(int v) {
    this->vida = v;
}

void Heroi::setMunicao(int m) {
    this->municao = m;
}

int Heroi::getVida() const {
    return this->vida;
}

int Heroi::getMunicao() const {
    return this->municao;
}

void Heroi::load() {
    sf::Sprite lSprite = sf::Sprite();
    sf::Texture heroiTexture;

    sprite = sf::RectangleShape(sf::Vector2f(50, 50));
    sprite.setFillColor(sf::Color::Green);
    sprite.setPosition(Variables().tamX / 2.0f,
                       Variables().tamY / 2.0f);
}

void Heroi::update() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

        move = true;
        heroMousePos = sf::Vector2f(sf::Mouse::getPosition(this->getWindow()));

    }

    sf::Vector2f destino = sf::Vector2f(heroMousePos);
    sf::Vector2f direcao = VectorUtils::calcularDirecao(sprite.getPosition(), destino);

    // Calcula a distância entre o herói e o destino - Sem isso ele fica bugado
    float distance = sqrt(
            pow(destino.x - sprite.getPosition().x, 2) + pow(destino.y - sprite.getPosition().y, 2));

    if (distance < 3.0f) {
        move = false;
    }

    if (move) {
        sprite.setPosition(sprite.getPosition() + direcao * 5.0f);
    }
}

void Heroi::draw() {
    this->getWindow().draw(sprite);
}

void Heroi::shoot() {

}


