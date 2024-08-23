#include "InimigoComum.h"

Inimigo InimigoComum::get(std::map<std::string, double> variables) {
    // Chance de spawn
    double chanceSpawn = variables["baseSpawnRate"];

    // Shape do inimigo
    sf::RectangleShape inimigoComumShape = sf::RectangleShape(sf::Vector2f(50, 50));
    inimigoComumShape.setFillColor(sf::Color::Red);
    // Tamanho da caixa de colisão
    sf::Vector2f collisionBoxSize = inimigoComumShape.getSize();

    // Atributos do inimigo
    int vida = static_cast<int>(variables["inimigoBaseLife"]);
    float velocidade = static_cast<float>(variables["inimigoSpeedBase"]);
    int dano = static_cast<int>(variables["inimigoBaseDamage"]);
    std::string nome = "Comum";

    return {inimigoComumShape, vida, velocidade, dano, collisionBoxSize, nome, chanceSpawn};
}
