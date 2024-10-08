#include "Dropavel.h"
#include "SFML/Graphics/Text.hpp"
#include "../../Variables/WindowConstants.h"
#include "../../../Util/FileUtils.h"

Dropavel::Dropavel() {

}

Dropavel::Dropavel(sf::RectangleShape shape1, sf::Vector2f posicao1, int tempoVida1) {
    this->dropavelShape = shape1;
    this->posicao = posicao1;
    this->tempoVida = tempoVida1;
}


void Dropavel::draw(sf::RenderWindow &window) {
    sf::Text text;
    dropavelShape.setPosition(posicao);
    window.draw(dropavelShape);
}

void Dropavel::update() {
    dropavelShape.setPosition(posicao);
    tempoVida--;
}

sf::RectangleShape Dropavel::getDropavelShape() const {
    return this->dropavelShape;
}

void Dropavel::setDropavelShape(sf::RectangleShape dropavelShape1) {
    this->dropavelShape = dropavelShape1;
}

sf::Vector2f Dropavel::getPosicao() const {
    return this->posicao;
}

void Dropavel::setPosicao(sf::Vector2f posicao1) {
    this->posicao = posicao1;
}

int Dropavel::getTempoVida() const {
    return this->tempoVida;
}

void Dropavel::setTempoVida(int tempoVida1) {
    this->tempoVida = tempoVida1;
}

void Dropavel::setStrategy(IDropavelStrategy *strategy1) {
    this->strategy = strategy1;
}

IDropavelStrategy *Dropavel::getStrategy() const {
    return this->strategy;
}

