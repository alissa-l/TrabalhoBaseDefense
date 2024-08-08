#ifndef TRABALHOBASEDEFENSE_VECTORUTILS_HPP
#define TRABALHOBASEDEFENSE_VECTORUTILS_HPP
#include "SFML/Graphics.hpp"

class VectorUtils {
public:
    static sf::Vector2f Normalizar(sf::Vector2f vector);
    static sf::Vector2f calcularDirecao(sf::Vector2f origem, sf::Vector2f destino);
    static sf::Vector2f calcularDistancia(sf::Vector2f origem, sf::Vector2f destino);
};


#endif //TRABALHOBASEDEFENSE_VECTORUTILS_HPP
