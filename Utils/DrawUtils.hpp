//
// Created by alissa on 20/07/24.
//

#ifndef TRABALHOBASEDEFENSE_DRAWUTILS_HPP
#define TRABALHOBASEDEFENSE_DRAWUTILS_HPP


#include <string>
#include "SFML/Graphics/RectangleShape.hpp"
#include "../Classes/Heroi.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class DrawUtils {
public:
    static void createText(const std::string &texto, int posX, int posY, sf::RenderWindow &window);

};
#endif //TRABALHOBASEDEFENSE_DRAWUTILS_HPP
