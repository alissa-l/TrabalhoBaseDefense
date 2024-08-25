#ifndef TRABALHOBASEDEFENSE_VECTORUTILS_HPP
#define TRABALHOBASEDEFENSE_VECTORUTILS_HPP
#include "SFML/Graphics.hpp"

class VectorUtils {
public:
    /**
     * Normaliza um vetor
     * @param vector
     * @return
     */
    static sf::Vector2f Normalizar(sf::Vector2f vector);

    /**
     * Calcula a direção entre dois pontos
     * @param origem
     * @param destino
     * @return
     */
    static sf::Vector2f calcularDirecao(sf::Vector2f origem, sf::Vector2f destino);

    /**
     * Calcula a distância entre dois pontos
     * @param origem
     * @param destino
     * @return
     */
    static sf::Vector2f calcularDistancia(sf::Vector2f origem, sf::Vector2f destino);

    /**
     * Calcula a distância entre dois pontos
     * @param origem
     * @param destino
     * @return
     */
    static sf::Vector2f randomPositionScreenBorder();

    /**
     * Ordena um vetor de vetores baseado na distancia de um ponto origem
     * @param origem
     * @param vetor
     * @return
     */
    static void sortVectorByDistance(sf::Vector2f origem, std::vector<sf::Vector2f> &vetor);

};


#endif //TRABALHOBASEDEFENSE_VECTORUTILS_HPP
