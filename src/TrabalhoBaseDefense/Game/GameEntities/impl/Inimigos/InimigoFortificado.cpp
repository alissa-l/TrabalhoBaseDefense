#include "InimigoFortificado.h"

/**
 * Constroi um inimigo fortificado usando variaveis baseShape
 * @return inimigo fortificado
 */
Inimigo InimigoFortificado::get(std::map<std::string, double> properties) {
    // Lendo variáveis do inimigo
    double chanceSpawn = properties["baseSpawnRate"];

    // Tamanho da caixa de colisão
    sf::Vector2f collisionBoxSize = sf::Vector2f(50, 50);

    // Tamanho da caixa de colisão
    int vida = static_cast<int>(properties["inimigoBaseLife"]) * 2;
    float velocidade = static_cast<float>(properties["inimigoSpeedBase"] * 0.5f);
    int dano = static_cast<int>(properties["inimigoBaseDamage"] * 2);
    std::string nome = "Fortificado";
    std::string path = "resources/sprites/Slime_roxo1.png";

    return {vida, velocidade, dano, collisionBoxSize, nome, chanceSpawn, path};
}
