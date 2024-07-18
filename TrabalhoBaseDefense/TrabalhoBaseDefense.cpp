#include "SFML/Graphics.hpp"
#include "iostream"
#include "../Classes/Heroi.hpp"

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


    // Game loop
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    heroi.setMunicao(heroi.getMunicao() - 1);
                }
            }

        }

        sf::Font font;
        font.loadFromFile("resources/font/arial.ttf");

        std::string vida = "Vida: " + std::to_string(heroi.getVida());
        sf::Text textVida;
        textVida.setFont(font);
        textVida.setPosition(1100, 20);
        textVida.setString(vida);
        textVida.setCharacterSize(24);
        textVida.setFillColor(sf::Color::Black);
        textVida.setStyle(sf::Text::Bold);


        std::string municao = "Municao: " + std::to_string(heroi.getMunicao());
        sf::Text textMunicao;
        textMunicao.setFont(font);
        textMunicao.setPosition(1100, 50);
        textMunicao.setString(municao);
        textMunicao.setCharacterSize(24);
        textMunicao.setFillColor(sf::Color::Black);
        textMunicao.setStyle(sf::Text::Bold);

        window.clear(sf::Color::White);

        window.draw(textMunicao);
        window.draw(textVida);

        window.display();

    }

    return 0;
}