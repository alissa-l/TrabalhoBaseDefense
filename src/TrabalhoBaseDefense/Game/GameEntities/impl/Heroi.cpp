#include "Heroi.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Mouse.hpp"
#include "math.h"
#include "../../Variables/Variables.h"
#include "../../../Util/VectorUtils.hpp"
#include "../../../Logger/Logger.hpp"
#include "../../Variables/HeroVariables.h"
#include "../../Variables/WindowConstants.h"


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



    municao = HeroVariables().heroiMunicao;
    vida = HeroVariables().heroiVida;

    Logger logger = Logger(Variables().logFile, Variables().logLevel);

    sprite = sf::RectangleShape(sf::Vector2f(50, 50));
    sprite.setFillColor(sf::Color::Green);
    sprite.setPosition(WindowConstants().tamX / 2.0f,
                       WindowConstants().tamY / 2.0f);

    colisionBox = sf::RectangleShape(sf::Vector2f(50, 50));
    colisionBox.setPosition(sprite.getPosition());


}

void Heroi::update(sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

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
        sprite.setPosition(sprite.getPosition() + direcao * HeroVariables().heroiSpeed);
        colisionBox.setPosition(sprite.getPosition());
    }
}

void Heroi::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Heroi::shoot() {

}

Heroi::Heroi() {

}

sf::RectangleShape Heroi::getColisionBox() const {
    return colisionBox;
}

void Heroi::setColisionBox(sf::RectangleShape colisionBox1) {
    this->colisionBox = colisionBox1;
}


