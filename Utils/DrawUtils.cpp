//
// Created by alissa on 20/07/24.
//

#include <iostream>
#include "DrawUtils.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

sf::RectangleShape DrawUtils::desenharHeroi(Heroi &heroi) {
    sf::RectangleShape rect(sf::Vector2f(50, 50));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(heroi.getPosX(), heroi.getPosY());
    return rect;
}

void DrawUtils::createText(const std::string &texto, int posX, int posY, sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("resources/font/arial.ttf");

    if (!font.loadFromFile("resources/font/arial.ttf")) {
        std::cout << "Erro ao carregar fonte" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setPosition(posX, posY);
    text.setString(texto);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    window.draw(text);
}
