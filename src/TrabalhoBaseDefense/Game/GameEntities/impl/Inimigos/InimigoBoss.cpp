#include "InimigoBoss.h"

/**
 * Retorna um inimigo boss
 * @return inimigo boss
 */
Inimigo InimigoBoss::get(std::map<std::string, double> properties) {
    double chanceSpawn = 0;

    // Tamanho da caixa de colisão
    sf::Vector2f collisionBoxSize = sf::Vector2f(100, 100);

    // Atributos do inimigo
    int vida = static_cast<int>(properties["inimigoBaseLife"] * 5);
    float velocidade = static_cast<float>(properties["inimigoSpeedBase"] * 0.2f);
    int dano = static_cast<int>(properties["inimigoBaseDamage"] * 10);
    std::string nome = "BOSS";
    std::string path = "resources/sprites/BOSS_OLHO1.png";

    return {vida, velocidade, dano, collisionBoxSize, nome, chanceSpawn, path};
}
