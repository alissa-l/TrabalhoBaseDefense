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
Inimigo EnemySpawn::getRandomEnemy(std::map<double, Inimigo> &inimigosSpawn) {
    Inimigo inimigoEscolhido;
    bool inimigoEscolhidoSetado = false;
    while (!inimigoEscolhidoSetado) {
        for (auto &pair: inimigosSpawn) {
            double chance = pair.first;
            Inimigo inimigo = pair.second;
            if (chance >= rand() % 100) {
                inimigoEscolhido = inimigo;
                inimigoEscolhidoSetado = true;
                break;
            }
        }
    }

    inimigoEscolhido.setPosicao(VectorUtils::randomPositionScreenBorder());
    inimigoEscolhido.update();

    return inimigoEscolhido;
}

void EnemySpawn::spawnEnemy(std::vector<Inimigo> &inimigos, std::map<double, Inimigo> &inimigosSpawn,
                            int &lastSpawn, int &frame_count, std::vector<Heroi> &herois) {

    if (lastSpawn == 0 || frame_count - lastSpawn == EnemyVariables().inimigoFrequency) {
        lastSpawn = frame_count;
        inimigos.push_back(EnemySpawn::getRandomEnemy(inimigosSpawn));
    }

}
