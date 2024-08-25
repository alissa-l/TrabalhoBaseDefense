#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include "TelaGameOver.h"
#include "SFML/Graphics/Font.hpp"
#include "../../Logger/LogLevel.h"
#include "../../Logger/Logger.hpp"
#include "../../Util/FileUtils.h"

void TelaGameOver::gameOverScreen(sf::RenderWindow &window) {

    while (true) {
        sf::Event event{};

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }
        window.clear(sf::Color::Black);

        sf::Text text;
        sf::Font font;
        font = FileUtils::getFont();
        text.setFont(font);
        text.setString("Voce perdeu");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Red);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        unsigned int sizeXInt = window.getSize().x / 2;
        auto sizeXFloat = static_cast<float>(sizeXInt);
        unsigned int sizeYInt = window.getSize().y / 2;
        auto sizeYFloat = static_cast<float>(sizeYInt);

        text.setPosition(sf::Vector2f(sizeXFloat, sizeYFloat));
        window.draw(text);


        // Display
        window.display();
    }

}
