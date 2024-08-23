#include "InimigoRapido.h"

Inimigo InimigoRapido::get(std::map<std::string, double> properties) {
    // Chance de spawn
    double chanceSpawn = properties["baseSpawnRate"];

    // Shape do inimigo
    sf::RectangleShape inimigoRapidoShape = sf::RectangleShape(sf::Vector2f(50, 50));
    inimigoRapidoShape.setFillColor(sf::Color::Green);
    // Tamanho da caixa de colisão
    sf::Vector2f collisionBoxSize = inimigoRapidoShape.getSize();

    // Atributos do inimigo
    int vida = static_cast<int>(properties["inimigoBaseLife"]);
    float velocidade = static_cast<float>(properties["inimigoSpeedBase"] * 3);
    int dano = static_cast<int>(properties["inimigoBaseDamage"]);
    std::string nome = "Rapido";

    return {inimigoRapidoShape, vida, velocidade, dano, collisionBoxSize, nome, chanceSpawn};
}
