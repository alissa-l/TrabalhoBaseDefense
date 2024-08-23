#include "InimigoBoss.h"

/**
 * Retorna um inimigo boss
 * @return inimigo boss
 */
Inimigo InimigoBoss::get(std::map<std::string, double> properties) {
    double chanceSpawn = 0;
    // Shape do inimigo
    sf::RectangleShape inimigoBossShape = sf::RectangleShape(sf::Vector2f(100, 100));
    inimigoBossShape.setFillColor(sf::Color::Yellow);
    // Tamanho da caixa de colisão
    sf::Vector2f collisionBoxSize = inimigoBossShape.getSize();

    // Atributos do inimigo
    int vida = static_cast<int>(properties["inimigoBaseLife"] * 5);
    float velocidade = static_cast<float>(properties["inimigoSpeedBase"] * 0.2f);
    int dano = static_cast<int>(properties["inimigoBaseDamage"] * 10);
    std::string nome = "BOSS";

    return {inimigoBossShape, vida, velocidade, dano, collisionBoxSize, nome, chanceSpawn};
}
