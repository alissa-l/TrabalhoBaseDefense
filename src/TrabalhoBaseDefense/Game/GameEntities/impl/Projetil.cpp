#include "Projetil.h"
#include "../../Variables/Variables.h"

#include <utility>
#include <iostream>
#include <cmath>
#include <valarray>

Projetil::Projetil() {
    friendly = false;
}

sf::Vector2f Projetil::getDirecao() {
    return this->direcao;
}

void Projetil::setDirecao(sf::Vector2f dir) {
    this->direcao = dir;
}

void Projetil::load() {
    if (!this->texture.loadFromFile(this->spritePath)) {
        std::cout << "Erro ao carregar textura do projetil" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setScale(1.4f, 1.4f);
    sprite.setPosition(posicao);
    collisionBox.setPosition(posicao);
}

void Projetil::draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
}

void Projetil::update() {

    if (!this->texture.loadFromFile(this->spritePath)) {
        std::cout << "Erro ao carregar textura do projetil" << std::endl;
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(1.4f, 1.4f);
    this->sprite.setRotation(this->rotacao);

    this->posicao = posicao + this->direcao * Variables().projectileSpeed;
    collisionBox.setPosition(posicao);

    this->sprite.setRotation(rotacao);


    sprite.setPosition(posicao);



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

sf::Sprite Projetil::getSprite() const {
    return this->sprite;
}

void Projetil::setSprite(sf::Sprite sprite1) {
    this->sprite = sprite1;
}

sf::Texture Projetil::getTexture() const {
    return this->texture;
}

void Projetil::setTexture(sf::Texture texture1) {
    this->texture = texture1;
}

sf::RectangleShape Projetil::getCollisionBox() const {
    return this->collisionBox;
}

void Projetil::setCollisionBox(sf::RectangleShape collisionBox1) {
    this->collisionBox = collisionBox1;
}

std::string Projetil::getSpritePath() const {
    return this->spritePath;
}

void Projetil::setSpritePath(std::string spritePath1) {
    this->spritePath = spritePath1;
}

sf::Vector2f Projetil::getPosicao() {
    return this->posicao;
}

void Projetil::setPosicao(sf::Vector2f posicao) {
    this->posicao = posicao;
}

float Projetil::getRotacao() {
    return this->rotacao;
}

void Projetil::setRotacao(float rotacao1) {
    this->rotacao = rotacao1;
}
