#include <iostream>
#include "Inimigo.h"
#include "../../../Util/VectorUtils.hpp"

Inimigo::Inimigo() {

}

/**
 * Construtor do inimigo
 * @param shape1
 * @param vida1
 * @param velocidade1
 * @param dano1
 * @param colisionBoxSize
 */
Inimigo::Inimigo(sf::RectangleShape shape1, int vida1, float velocidade1, int dano1, sf::Vector2f colisionBoxSize,
                 std::string nome1) {
    inimigoShape = shape1;
    Inimigo::vida = vida1;
    Inimigo::velocidade = velocidade1;
    Inimigo::dano = dano1;
    Inimigo::nome = nome1;
    colisionBox = sf::RectangleShape(colisionBoxSize);
    colisionBox.setPosition(inimigoShape.getPosition());
}

/**
 * Carrega o inimigo
 */
void Inimigo::load() {

}

/**
 * Desenha o inimigo
 * @param window
 */
void Inimigo::draw(sf::RenderWindow &window) {
    window.draw(inimigoShape);
}

/**
 * Update do inimigo <br>
 * Atualiza a posicao do inimigo
 */
void Inimigo::update() {

    sf::Vector2f newPos = posicao + direcao * velocidade;

    setPosicao(newPos);

    inimigoShape.setPosition(posicao);
    colisionBox.setPosition(posicao);

}

/**
 * Atualiza a direção do inimigo com base no heroi mais proximo
 * @param herois
 */
void Inimigo::updateDirecao(std::vector<Heroi> &herois) {
    std::vector<sf::Vector2f> posHerois;
    for (auto &heroi: herois) {
        posHerois.push_back(heroi.sprite.getPosition());
    }
    VectorUtils::sortVectorByDistance(posicao, posHerois);

    direcao = VectorUtils::calcularDirecao(posicao, posHerois[0]);
}

int Inimigo::getVida() const {
    return vida;
}

void Inimigo::setVida(int vid) {
    Inimigo::vida = vid;
}

float Inimigo::getVelocidade() const {
    return velocidade;
}

void Inimigo::setVelocidade(float vel) {
    Inimigo::velocidade = vel;
}

int Inimigo::getDano() const {
    return dano;
}

void Inimigo::setDano(int dam) {
    Inimigo::dano = dam;
}

const sf::Vector2f &Inimigo::getPosicao() const {
    return posicao;
}

void Inimigo::setPosicao(const sf::Vector2f &posicao1) {
    Inimigo::posicao = posicao1;
}

const sf::Vector2f &Inimigo::getDirecao() const {
    return direcao;
}

void Inimigo::setDirecao(const sf::Vector2f &direcao) {
    Inimigo::direcao = direcao;
}

sf::RectangleShape Inimigo::getColisionBox() const {
    return colisionBox;
}

void Inimigo::setColisionBox(const sf::RectangleShape &colisionBox1) {
    this->colisionBox = colisionBox1;
}

std::string &Inimigo::getNome() {
    return this->nome;
}

void Inimigo::setNome(const std::string &nome1) {
    this->nome = nome1;
}
