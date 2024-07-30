#include "Inimigo.hpp"

Inimigo::Inimigo(sf::RectangleShape shape, int vida, int velocidade, int dano) {
    inimigoShape = shape;
    Inimigo::vida = vida;
    Inimigo::velocidade = velocidade;
    Inimigo::dano = dano;
}

const sf::RectangleShape &Inimigo::getInimigoShape() const {
    return inimigoShape;
}

void Inimigo::setInimigoShape(const sf::RectangleShape &inimigoSha) {
    Inimigo::inimigoShape = inimigoSha;
}


int Inimigo::getVida() const {
    return vida;
}

void Inimigo::setVida(int vid) {
    Inimigo::vida = vid;
}

int Inimigo::getVelocidade() const {
    return velocidade;
}

void Inimigo::setVelocidade(int vel) {
    Inimigo::velocidade = vel;
}

int Inimigo::getDano() const {
    return dano;
}

void Inimigo::setDano(int dam) {
    Inimigo::dano = dam;
}

void Inimigo::load() {

}

void Inimigo::draw(sf::RenderWindow &window) {

}

void Inimigo::update() {

}