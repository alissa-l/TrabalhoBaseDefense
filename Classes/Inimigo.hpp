//
// Created by alissa on 22/07/24.
//

#ifndef TRABALHOBASEDEFENSE_INIMIGO_HPP
#define TRABALHOBASEDEFENSE_INIMIGO_HPP


#include "SFML/Graphics/RectangleShape.hpp"

class Inimigo {
private:
    sf::RectangleShape inimigoShape;
    int vida;
public:
    Inimigo(sf::RectangleShape shape, int v);
    sf::RectangleShape getInimigoShape();

    void setInimigoShape(sf::RectangleShape inimigo);
    int getVida();
    void setVida(int vida);
};


#endif //TRABALHOBASEDEFENSE_INIMIGO_HPP
