#include <iostream>
#include "TextoJogo.h"
#include "../GameEntities/impl/Heroi.hpp"
#include "../GameEntities/impl/Base.hpp"

void TextoJogo::update(Heroi &heroi, int round, const Base& base) {

//    sf::Font font;
//    if(!font.loadFromFile("resources/font/arial.ttf")) {
//        throw std::runtime_error("Erro ao carregar fonte");
//    }
//    texto.setFont(font);

    std::string text = "Vida: " + std::to_string(heroi.getVida()) + "\nMunicao: " + std::to_string(heroi.getMunicao()) +
                       "\nRound: " + std::to_string(round) + "\nVida da Base: " + std::to_string(base.getVida());

    texto.setString(text);
    texto.setCharacterSize(24);

    texto.setStyle(sf::Text::Bold);

    texto.setFillColor(sf::Color::Black);
    texto.setPosition(200, 200);

}

TextoJogo::TextoJogo() {

}


