//
// Created by alissa on 21/07/24.
//

#ifndef TRABALHOBASEDEFENSE_PROJETIL_HPP
#define TRABALHOBASEDEFENSE_PROJETIL_HPP


#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class Projetil {
private:
    sf::Vector2f direcao;
    sf::RectangleShape projetil;
public:
    Projetil(sf::Vector2f direcao, sf::RectangleShape projetil);
    sf::RectangleShape getProjetil();
    void setProjetil(sf::RectangleShape proj);
    sf::Vector2f getDirecao();
    void setDirecao(sf::Vector2f dir);
};


#endif //TRABALHOBASEDEFENSE_PROJETIL_HPP
