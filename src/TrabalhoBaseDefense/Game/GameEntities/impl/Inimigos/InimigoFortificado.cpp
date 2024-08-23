#include "InimigoFortificado.h"

/**
 * Constroi um inimigo fortificado usando variaveis base
 * @return inimigo fortificado
 */
Inimigo InimigoFortificado::get(std::map<std::string, double> properties) {
    // Lendo variáveis do inimigo
    double chanceSpawn = properties["baseSpawnRate"];

    // Shape do inimigo
    sf::RectangleShape inimigoFortificadoShape = sf::RectangleShape(sf::Vector2f(70, 70));
    inimigoFortificadoShape.setFillColor(sf::Color::Blue);
    // Tamanho da caixa de colisão
    sf::Vector2f collisionBoxSize = inimigoFortificadoShape.getSize();

    // Tamanho da caixa de colisão
    int vida = static_cast<int>(properties["inimigoBaseLife"]) * 2;
    float velocidade = static_cast<float>(properties["inimigoSpeedBase"] * 0.5f);
    int dano = static_cast<int>(properties["inimigoBaseDamage"] * 2);
    std::string nome = "Fortificado";

    return {inimigoFortificadoShape, vida, velocidade, dano, collisionBoxSize, nome, chanceSpawn};
}
