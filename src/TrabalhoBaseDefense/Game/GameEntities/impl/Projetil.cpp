#include "Projetil.h"
#include "../../Variables/Variables.h"

#include <utility>
#include <iostream>

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
    sprite.setPosition(posicao);
    collisionBox.setPosition(posicao);
}

void Projetil::draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
    window.draw(this->collisionBox);
}

void Projetil::update() {

    this->collisionBox.setOutlineThickness(1);
    this->collisionBox.setOutlineColor(sf::Color::Red);
    if (!this->texture.loadFromFile(this->spritePath)) {
        std::cout << "Erro ao carregar textura do projetil" << std::endl;
    }
    this->sprite.setTexture(this->texture);

    sf::Vector2f newPos = sprite.getPosition() + this->direcao * Variables().projectileSpeed;
    this->sprite.setPosition(newPos);
    collisionBox.setPosition(newPos);

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
