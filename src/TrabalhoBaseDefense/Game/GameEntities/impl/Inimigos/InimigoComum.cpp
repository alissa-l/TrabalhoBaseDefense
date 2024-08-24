#include "InimigoComum.h"

Inimigo InimigoComum::get(std::map<std::string, double> variables) {
    // Chance de spawn
    double chanceSpawn = variables["baseSpawnRate"];

    // Tamanho da caixa de colisão
    sf::Vector2f collisionBoxSize = sf::Vector2f(60, 60);

    // Atributos do inimigo
    int vida = static_cast<int>(variables["inimigoBaseLife"]);
    float velocidade = static_cast<float>(variables["inimigoSpeedBase"]);
    int dano = static_cast<int>(variables["inimigoBaseDamage"]);
    std::string nome = "Comum";
    std::string path = "resources/sprites/slime1.png";


    return {vida, velocidade, dano, collisionBoxSize, nome, chanceSpawn, path};
}
