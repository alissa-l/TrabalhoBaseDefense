//
// Created by alissa on 20/07/24.
//

#include "VectorUtils.hpp"
#include "math.h"
#include "../Game/Variables/Variables.h"
#include "../Game/Variables/WindowConstants.h"

/**
 * Normaliza um vetor <br>
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
 * Calcula a direção de um vetor <br>
 * direcao = Normalizar(destino - origem) <br>
 * @param origem
 * @param destino
 * @return Vetor da direção
 */
sf::Vector2f VectorUtils::calcularDirecao(sf::Vector2f origem, sf::Vector2f destino) {
    sf::Vector2f direcao = destino - origem;
    return Normalizar(direcao);
}

/**
 * Calcula a distância entre dois vetores <br>
 * distancia = destino - origem <br>
 * @param origem
 * @param destino
 * @return Vetor da distância
 */
sf::Vector2f VectorUtils::calcularDistancia(sf::Vector2f origem, sf::Vector2f destino) {
    return destino - origem;
}

/**
 *
 * @param window
 * @return
 */
sf::Vector2f VectorUtils::randomPositionScreenBorder() {
    int x;
    int y;

    // Selecao aleatoria do lado de spawn
    if (rand() % 2 == 0) {
        x = 0;
        y = rand() % (WindowConstants().tamY - 1) + 1;
    } else {
        y = 0;
        x = rand() % (WindowConstants().tamX - 1) + 1;
    }

    return sf::Vector2f(x, y);
}

void VectorUtils::sortVectorByDistance(sf::Vector2f origem, std::vector<sf::Vector2f> &vetor) {
    std::sort(vetor.begin(), vetor.end(), [origem](sf::Vector2f a, sf::Vector2f b) {
        return VectorUtils::calcularDistancia(origem, a).x < VectorUtils::calcularDistancia(origem, b).x;
    });
}
