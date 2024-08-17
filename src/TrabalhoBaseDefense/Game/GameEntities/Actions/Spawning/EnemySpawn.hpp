#ifndef SRC_TRABALHOBASEDEFENSE_ENEMYSPAWN_HPP
#define SRC_TRABALHOBASEDEFENSE_ENEMYSPAWN_HPP


#include <map>
#include "../../impl/Inimigo.h"
#include "../../impl/Heroi.hpp"

/**
 * Guarda a lógica relacionada a spawnar inimigos
 */
class EnemySpawn {
public:
    static void spawnEnemy(std::vector<Inimigo> &inimigos, std::map<double, Inimigo> &inimigosSpawn, int &lastSpawn,
                           int &frame_count, std::vector<Heroi> &herois);

    /**
     * Retorna um inimigo aleatório baseado na chance de spawn
     * @param inimigosSpawn
     * @return
     */
    static Inimigo getRandomEnemy(std::map<double, Inimigo> &inimigosSpawn);
};


#endif //SRC_TRABALHOBASEDEFENSE_ENEMYSPAWN_HPP
