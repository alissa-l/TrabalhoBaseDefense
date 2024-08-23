#include "TelaGameOver.h"
#include "SFML/Graphics/Font.hpp"

void TelaGameOver::gameOverScreen(sf::RenderWindow &window) {

//    while (true) {
//        sf::Event event{};
//
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//                logger.log(LogLevel::INFO, "Jogo encerrado - menu");
//            }
//
//            if (event.type == sf::Event::KeyPressed) {
//                logger.log(LogLevel::INFO, "Jogo iniciado - menu");
//                return;
//            }
//
//        }
//        window.clear(sf::Color::White);
//
//
//        sf::Font font;
//        if (!font.loadFromFile("resources/font/arial.ttf")) {
//            throw std::runtime_error("Erro ao carregar fonte");
//        }
//
//        //
//        // Textos do menu
//        //
//        std::vector<sf::Text> textos(2);
//
//        // Titulo
//        textos[0].setString("Base Defense");
//        textos[0].setCharacterSize(30);
//
//        // Instruções
//        textos[1].setString("Pressione qualquer tecla para iniciar o jogo");
//        textos[1].setCharacterSize(20);
//
//        // Para cada texto, setar as propriedades
//        for (auto &texto : textos) {
//            texto.setFillColor(sf::Color::Black);
//            texto.setStyle(sf::Text::Bold);
//            texto.setFont(font);
//
//            // Centrailizar textto
//            sf::FloatRect textRect = texto.getLocalBounds();
//            texto.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
//            unsigned int sizeXInt = window.getSize().x / 2;
//            auto sizeXFloat = static_cast<float>(sizeXInt);
//            unsigned int sizeYInt = window.getSize().y / 2;
//            auto sizeYFloat = static_cast<float>(sizeYInt);
//
//            texto.setPosition(sf::Vector2f(sizeXFloat, sizeYFloat));
//        }
//
//        // Ajustar a posição do titulo por um offset de Y
//        textos[1].move(0, 50);
//
//        // Desenhar os textos
//        for (const auto& texto : textos) {
//            window.draw(texto);
//        }
//
//        // Display
//        window.display();
//    }

}
