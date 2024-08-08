#ifndef TRABALHOBASEDEFENSE_MAPA_HPP
#define TRABALHOBASEDEFENSE_MAPA_HPP


#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Mapa {
public:
    std::vector<sf::RectangleShape> elementos;
    std::vector<sf::Text> textos;
    Mapa(std::vector<sf::RectangleShape> elem, std::vector<sf::Text> text);
    void load();
    void draw(sf::RenderWindow &window);
    void update();

};


#endif //TRABALHOBASEDEFENSE_MAPA_HPP
