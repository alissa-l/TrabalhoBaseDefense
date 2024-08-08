#include "Mapa.hpp"

Mapa::Mapa(std::vector<sf::RectangleShape> elem, std::vector<sf::Text> text) {
    this->elementos = elem;
    this->textos = text;
}

void Mapa::load() {

}

void Mapa::draw(sf::RenderWindow &window) {

    for (int i = 0; i < elementos.size(); i++) {
        window.draw(elementos[i]);
    }

    for (int i = 0; i < textos.size(); i++) {
        window.draw(textos[i]);
    }

}

void Mapa::update() {

}


