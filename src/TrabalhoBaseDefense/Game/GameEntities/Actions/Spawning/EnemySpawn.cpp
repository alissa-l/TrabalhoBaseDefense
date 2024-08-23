#include "EnemySpawn.hpp"
#include "../../../../Util/VectorUtils.hpp"
#include "../../impl/Heroi.hpp"
#include "../../../Variables/Variables.h"
#include "../../../Variables/EnemyVariables.hpp"

/**
 * Retorna um inimigo aleatório baseado na chance de spawn<br>
 * Primeiro escolhe um inimigo baseado na chance de spawn e depois seta a posição aleatória na borda da tela
 * @param inimigosSpawn
 * @return
 */
Inimigo EnemySpawn::getRandomEnemy(std::vector<Inimigo> &inimigosSpawn) {
    Inimigo inimigoEscolhido;
    bool inimigoEscolhidoSetado = false;
    while (!inimigoEscolhidoSetado) {
        for (auto &i: inimigosSpawn) {
            double chance = i.getChanceSpawn();
            if (chance >= rand() % 100) {
                inimigoEscolhido = i;
                inimigoEscolhidoSetado = true;
                break;
            }
        }
    }

    inimigoEscolhido.setPosicao(VectorUtils::randomPositionScreenBorder());
    inimigoEscolhido.update();

    return inimigoEscolhido;
}

void EnemySpawn::spawnEnemy(std::vector<Inimigo> &inimigos, std::vector<Inimigo> &inimigosSpawn,
                            int &lastSpawn, int &frame_count, std::vector<Heroi> &herois,
                            std::map<std::string, double> &properties) {
    int frequency = static_cast<int>(properties["inimigoFrequency"]);
    if (lastSpawn == 0 || frame_count - lastSpawn == frequency) {
        lastSpawn = frame_count;
        inimigos.push_back(EnemySpawn::getRandomEnemy(inimigosSpawn));
    }
}
