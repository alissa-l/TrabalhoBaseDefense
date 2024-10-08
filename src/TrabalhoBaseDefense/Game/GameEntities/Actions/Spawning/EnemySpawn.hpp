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

    /**
     * Retorna um inimigo aleatório baseado na chance de spawn
     * @param inimigosSpawn
     * @return
     */
    static Inimigo getRandomEnemy(std::vector<Inimigo> &inimigosSpawn);

    /**
     * Spawnar um inimigo
     * @param inimigos
     * @param inimigosSpawn
     * @param lastSpawn
     * @param frame_count
     * @param herois
     */
    static void
    spawnEnemy(std::vector<Inimigo> &inimigos, std::vector<Inimigo> &inimigosSpawn, int &lastSpawn, int &frame_count,
               std::vector<Heroi> &herois, std::map<std::string, double> &properties);

};


#endif //SRC_TRABALHOBASEDEFENSE_ENEMYSPAWN_HPP
