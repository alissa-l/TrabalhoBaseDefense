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

        }

        sf::Font font = sf::Font::get;

        std::string vida = "Vida: " + std::to_string(heroi.getVida());
        sf::Text textVida;
        textVida.setFont(sf::Font::);
        textVida.setPosition(250, 200);
        textVida.setString(vida);
        textVida.setCharacterSize(50);
        textVida.setFillColor(sf::Color::Black);
        textVida.setStyle(sf::Text::Bold);

        std::string municao = "Municao: " + std::to_string(heroi.getMunicao());
        sf::Text textMunicao;
        textMunicao.setPosition(100, 150);
        textMunicao.setString(municao);
        textMunicao.setCharacterSize(24);
        textMunicao.setFillColor(sf::Color::Black);
        textVida.setStyle(sf::Text::Bold);


        window.draw(textVida);
        window.draw(textMunicao);

        window.clear(sf::Color::White);
        window.display();

    }

    return 0;
}