#include <iostream>
#include "Heroi.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Mouse.hpp"
#include "../Utils/VectorUtils.hpp"
#include "math.h"
#include "Variables.hpp"


Heroi::Heroi() {
    this->vida = 100;
    this->municao = 20;
    this->posY = 720 - 100;
    this->posX = 1280 / 2;
}

void Heroi::setVida(int vida) {
    this->vida = vida;
}

void Heroi::setMunicao(int municao) {
    this->municao = municao;
}

int Heroi::getVida() const {
    return this->vida;
}

int Heroi::getMunicao() const {
    return this->municao;
}

int Heroi::getPosX() const {
    return this->posX;
}

int Heroi::getPosY() const {
    return this->posY;
}

void Heroi::setPosX(int posX) {
    this->posX = posX;
}

void Heroi::setPosY(int posY) {
    this->posY = posY;
}

void Heroi::load() {
    sf::Sprite lSprite = sf::Sprite();
    sf::Texture heroiTexture;

    if(heroiTexture.loadFromFile("resources/Heroi/handgun/meleeattack/survivor-meleeattack_handgun_0.png")) {
        std::cout << "Textura do heroi carregada com sucesso" << std::endl;
        lSprite.setTexture(heroiTexture);
        lSprite.setPosition(Variables().tamX / 2.0f, Variables().tamY / 2.0f);

    } else {
        std::cout << "Erro ao carregar textura do heroi" << std::endl;
    }

    sprite = sf::RectangleShape(sf::Vector2f(50, 50));
    sprite.setFillColor(sf::Color::Green);
    sprite.setPosition(Variables().tamX / 2.0f, Variables().tamY / 2.0f);
}

void Heroi::update(sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {

        move = true;
        heroMousePos = sf::Vector2f(sf::Mouse::getPosition(window));

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

void Heroi::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

