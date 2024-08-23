#ifndef SRC_TRABALHOBASEDEFENSEEXE_ENEMYVARIABLES_HPP
#define SRC_TRABALHOBASEDEFENSEEXE_ENEMYVARIABLES_HPP

#include <fstream>
#include <map>
#include <filesystem>

/**
 * classe que lê e altera as variáveis dos inimigos <br>
 * inimigoFrequency <br>
 * inimigoSpeedBase <br>
 * inimigoBaseDamage <br>
 * inimigoBaseLife <br>
 * baseSpawnRate <br>
 */
class EnemyVariables {
public:
    double inimigoFrequency = 120;
    double inimigoSpeedBase = 1;
    double inimigoBaseDamage = 10;
    double inimigoBaseLife = 100;
    double baseSpawnRate = 1;
    double shootingFrequency = 10;
};


#endif //SRC_TRABALHOBASEDEFENSEEXE_ENEMYVARIABLES_HPP
