#include "Heroi.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Mouse.hpp"
#include "math.h"
#include "../../Variables/Variables.h"
#include "../../../Util/VectorUtils.hpp"
#include "../../../Logger/Logger.hpp"
#include "../../Variables/HeroVariables.h"
#include "../../Variables/WindowConstants.h"

Heroi::Heroi() {

}

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

    municao = HeroVariables().heroiMunicao;
    vida = HeroVariables().heroiVida;

    posicao = sf::Vector2f(WindowConstants().tamX / 2.0f, WindowConstants().tamY / 2.0f);
    colisionBox = sf::RectangleShape(sf::Vector2f(60, 100));

}

void Heroi::update(sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        move = true;
        heroMousePos = sf::Vector2f(sf::Mouse::getPosition(window));

    }

    if(!this->texture1.loadFromFile(HeroVariables().heroiTexture1,sf::IntRect(0, 0, 60, 100))) {
        throw std::runtime_error("Erro ao carregar textura do herói");
    }

    sprite1.setTexture(texture1);

    auto destino = sf::Vector2f(heroMousePos);
    sf::Vector2f direcao = VectorUtils::calcularDirecao(posicao, destino);

    // Calcula a distância entre o herói e o destino - Sem isso ele fica bugado
    float distance = sqrt(
            pow(destino.x - posicao.x, 2) + pow(destino.y - posicao.y, 2));

    if (distance < 3.0f) {
        move = false;
    }

    if (move) {
        posicao = posicao + direcao * HeroVariables().heroiSpeed;
        colisionBox.setPosition(posicao);
    }

    colisionBox.setPosition(posicao);
    sprite1.setPosition(posicao);


}

void Heroi::draw(sf::RenderWindow &window) {
    window.draw(sprite1);
}

sf::RectangleShape Heroi::getColisionBox() const {
    return colisionBox;
}

void Heroi::setColisionBox(sf::RectangleShape colisionBox1) {
    this->colisionBox = colisionBox1;
}

sf::Vector2f Heroi::getPosicao() const {
    return posicao;
}

void Heroi::setPosicao(sf::Vector2f posicao1) {
    this->posicao = posicao1;
}


