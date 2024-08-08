//
// Created by alissa on 20/07/24.
//

#include "VectorUtils.hpp"
#include "math.h"

/**
 * Normaliza um vetor
 * @param vector vetor a ser normalizado
 * @return vetor normalizado
 */
sf::Vector2f VectorUtils::Normalizar(sf::Vector2f vector) {
    float mag = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f vNormalizado;

    if (mag != 0) {
        vNormalizado.x = vector.x / mag;
        vNormalizado.y = vector.y / mag;
    }

    return vNormalizado;
}

/**
 * Calcula a direção de um vetor
 * @param origem
 * @param destino
 * @return Vetor da direção
 */
sf::Vector2f VectorUtils::calcularDirecao(sf::Vector2f origem, sf::Vector2f destino) {
    sf::Vector2f direcao = destino - origem;
    return Normalizar(direcao);
}

/**
 * Calcula a distância entre dois vetores
 * @param origem
 * @param destino
 * @return Vetor da distância
 */
sf::Vector2f VectorUtils::calcularDistancia(sf::Vector2f origem, sf::Vector2f destino) {
    return destino - origem;
}
