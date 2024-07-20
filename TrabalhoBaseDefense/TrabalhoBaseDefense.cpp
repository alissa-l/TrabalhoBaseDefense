#include "SFML/Graphics.hpp"
#include "iostream"
#include "../Classes/Heroi.hpp"
#include "math.h"

void createText(const std::string& texto, int posX, int posY, sf::RenderWindow &window);


sf::RectangleShape desenharHeroi(Heroi &heroi);

sf::Vector2f Normalizar(sf::Vector2f &v) {
    float mag = std::sqrt(v.x * v.x + v.y * v.y);

    sf::Vector2f vNormalizado;

    if (mag != 0) {
        vNormalizado.x = v.x / mag;
        vNormalizado.y = v.y / mag;
    }

    return vNormalizado;
}

int main()
{
    // Janela
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Base Defense");

    window.setFramerateLimit(60);

    // Relógio
    sf::Clock clock;

    // Heroi
    Heroi heroi;

    //Variáveis
    sf::RectangleShape heroiShape = desenharHeroi(heroi);

    // Game loop
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    heroi.setMunicao(heroi.getMunicao() - 1);
                }
            }


        }
        window.clear(sf::Color::White);

        sf::RectangleShape bala;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::RectangleShape bala(sf::Vector2f(10, 10));
            bala.setFillColor(sf::Color::Red);
            bala.setPosition(heroiShape.getPosition());

            sf::Vector2 mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f aa = window.mapPixelToCoords(mousePos);
            sf::Vector2f direcao = aa - heroiShape.getPosition();
            direcao = Normalizar(direcao);
            bala.setPosition(bala.getPosition() + direcao);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            sf::Vector2 mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f aa = window.mapPixelToCoords(mousePos);
            sf::Vector2f direcao = aa - heroiShape.getPosition();
            sf::Vector2f posicao = heroiShape.getPosition();
            direcao = Normalizar(direcao);
            heroiShape.setPosition(posicao + direcao);
        }


        window.draw(heroiShape);
        window.draw(bala);

        std::string vida = "Vida: " + std::to_string(heroi.getVida());
        createText(vida, 1100, 20, window);

        std::string municao = "Municao: " + std::to_string(heroi.getMunicao());
        createText(municao, 1100, 50, window);

        window.display();

    }

    return 0;
}

sf::RectangleShape desenharHeroi(Heroi &heroi) {
    sf::RectangleShape rect(sf::Vector2f(50, 50));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(heroi.getPosX(), heroi.getPosY());
    return rect;
}

void createText(const std::string& texto, int posX, int posY, sf::RenderWindow &window) {
    sf::Font font;
    font.loadFromFile("resources/font/arial.ttf");

    sf::Text text;
    text.setFont(font);
    text.setPosition(posX, posY);
    text.setString(texto);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);

    window.draw(text);

}