#include "Heroi.hpp"

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

void Heroi::move(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
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

