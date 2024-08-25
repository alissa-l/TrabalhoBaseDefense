#include "InimigoRapido.h"

Inimigo InimigoRapido::get(std::map<std::string, double> properties) {
    // Chance de spawn
    double chanceSpawn = properties["baseSpawnRate"];

    // Atributos do inimigo
    int vida = static_cast<int>(properties["inimigoBaseLife"]);
    float velocidade = static_cast<float>(properties["inimigoSpeedBase"] * 3);
    int dano = static_cast<int>(properties["inimigoBaseDamage"]);
    std::string nome = "Rapido";
    std::string path = "resources/sprites/bolinha_roxa_1.png";
    sf::Vector2f colisionBoxSize = sf::Vector2f(50, 50);

    return {vida, velocidade, dano, colisionBoxSize, nome, chanceSpawn, path};
}
