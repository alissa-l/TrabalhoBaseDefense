#include <SFML/Window/Event.hpp>
#include "TelaMenu.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "../../Logger/Logger.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../../Util/FileUtils.h"

void TelaMenu::menuScreen(sf::RenderWindow &window, Logger &logger, int &dificuldade) {
    while (true) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                logger.log(LogLevel::INFO, "Jogo encerrado - menu");
            }

            if (event.type == sf::Event::KeyPressed) {
                logger.log(LogLevel::INFO, "Escolher dificuldade - menu");
                selectDificuldade(window, logger, dificuldade);
                return;
            }

        }
        window.clear(sf::Color::White);


        sf::Font font;
        if (!font.loadFromFile("resources/font/arial.ttf")) {
            throw std::runtime_error("Erro ao carregar fonte");
        }

        //
        // Textos do menu
        //
        std::vector<sf::Text> textos(2);

        // Titulo
        textos[0].setString("Base Defense");
        textos[0].setCharacterSize(30);

        // Instruções
        textos[1].setString("Pressione qualquer tecla para iniciar o jogo");
        textos[1].setCharacterSize(20);

        // Para cada texto, setar as propriedades
        for (auto &texto: textos) {
            texto.setFillColor(sf::Color::Black);
            texto.setStyle(sf::Text::Bold);
            texto.setFont(font);

            // Centrailizar texto
            sf::FloatRect textRect = texto.getLocalBounds();
            texto.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            unsigned int sizeXInt = window.getSize().x / 2;
            auto sizeXFloat = static_cast<float>(sizeXInt);
            unsigned int sizeYInt = window.getSize().y / 2;
            auto sizeYFloat = static_cast<float>(sizeYInt);

            texto.setPosition(sf::Vector2f(sizeXFloat, sizeYFloat));
        }

        // Ajustar a posição do titulo por um offset de Y
        textos[1].move(0, 50);

        // Desenhar os textos
        for (const auto &texto: textos) {
            window.draw(texto);
        }

        // Display
        window.display();
    }
}

void TelaMenu::selectDificuldade(sf::RenderWindow &window, Logger &logger, int &dificuldade) {

    while (true) {
        sf::Event event{};

        // Tamanho da janela
        sf::Vector2u windowSize = window.getSize();
        auto windowWidth = static_cast<float>(windowSize.x);
        auto windowHeight = static_cast<float>(windowSize.y);

        // Dimensões dos retângulos
        float rectWidth = 150.0f;
        float rectHeight = 100.0f;
        float spacing = 75.0f;

        // Largura total de todos os retângulos
        float totalWidth = 3 * rectWidth + 2 * spacing;

        // Posição inicial do primeiro retângulo
        float startX = (windowWidth - totalWidth) / 2.0f;
        float yPos = windowHeight / 2.0f;

        // Retângulos
        sf::RectangleShape dificuldadeFacil(sf::Vector2f(rectWidth, rectHeight));
        dificuldadeFacil.setFillColor(sf::Color::Green);
        dificuldadeFacil.setPosition(startX, yPos); // Set position

        sf::RectangleShape dificuldadeMediana(sf::Vector2f(rectWidth, rectHeight));
        dificuldadeMediana.setFillColor(sf::Color::Yellow);
        dificuldadeMediana.setPosition(startX + rectWidth + spacing, yPos); // Set position

        sf::RectangleShape dificuldadeDificil(sf::Vector2f(rectWidth, rectHeight));
        dificuldadeDificil.setFillColor(sf::Color::Red);
        dificuldadeDificil.setPosition(startX + 2 * (rectWidth + spacing), yPos); // Set position




        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                logger.log(LogLevel::INFO, "Jogo encerrado - menu");
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if(dificuldadeFacil.getGlobalBounds().contains(mousePos)){
                    dificuldade = 0;
                    return;
                } else if (dificuldadeMediana.getGlobalBounds().contains(mousePos)){
                    dificuldade = 1;
                    return;
                } else if (dificuldadeDificil.getGlobalBounds().contains(mousePos)){
                    dificuldade = 2;
                    return;
                }

                std::string si = std::to_string(dificuldade);
                logger.log(LogLevel::INFO, "Dificuldade escolhida: " + si + " - menu");
                return;
            }

        }
        window.clear(sf::Color::White);


        sf::Font font = FileUtils::getFont();

        //
        // Textos da tela
        //
        sf::Text texto;

        // Titulo
        texto.setString("Selecione a dificuldade");
        texto.setCharacterSize(30);

        // Para cada texto, setar as propriedades
        texto.setFillColor(sf::Color::Black);
        texto.setStyle(sf::Text::Bold);
        texto.setFont(font);

        // Centrailizar texto
        sf::FloatRect textRect = texto.getLocalBounds();
        texto.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        unsigned int sizeXInt = window.getSize().x / 2;
        auto sizeXFloat = static_cast<float>(sizeXInt);
        unsigned int sizeYInt = window.getSize().y / 2;
        auto sizeYFloat = static_cast<float>(sizeYInt);

        texto.setPosition(sf::Vector2f(sizeXFloat, sizeYFloat));

        // Ajustar a posição do titulo por um offset de Y
        texto.move(0, -125);

        // Vetor de textos das dificuldades
        std::vector<sf::Text> textos(3);
        textos[0].setString("Facil");
        textos[1].setString("Medio");
        textos[2].setString("Dificil");

        for (int i = 0; i < textos.size(); ++i) {
            textos[i].setCharacterSize(20);
            textos[i].setFillColor(sf::Color::Black);
            textos[i].setStyle(sf::Text::Bold);
            textos[i].setFont(font);

            // Centralizar texto dentro do retângulo
            sf::FloatRect textRect = textos[i].getLocalBounds();
            textos[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
            textos[i].setPosition(
                    startX + i * (rectWidth + spacing) + rectWidth / 2.0f,
                    yPos + rectHeight / 2.0f
            );
        }

        // Desenhar os botões
        window.draw(dificuldadeFacil);
        window.draw(dificuldadeMediana);
        window.draw(dificuldadeDificil);

        // Desenhar os textos
        window.draw(texto);

        for (const auto &texto: textos) {
            window.draw(texto);
        }

        // Display
        window.display();
    }

}
