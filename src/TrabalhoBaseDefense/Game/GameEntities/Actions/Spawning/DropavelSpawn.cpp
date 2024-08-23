#include <random>
#include "DropavelSpawn.h"
#include "../../impl/Dropaveis/DropavelVidaHeroi.h"
#include "../../impl/Dropaveis/DropavelVidaBase.h"
#include "../../impl/Dropaveis/DropavelMunicao.h"

/**
 * Retorna um dropavel aleatorio
 * @return
 */
Dropavel DropavelSpawn::spawnRandomDropavel() {

    // Numero aleatorio entre 0 e 2
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);

    int random = dis(gen);

    // Retorna um dropavel aleatorio
    Dropavel dropavel = Dropavel();
    switch (random) {
        case 0: {
            DropavelVidaHeroi drop0 = DropavelVidaHeroi();
            dropavel = drop0.get();
            break;
        }
        case 1: {
            DropavelVidaBase drop1 = DropavelVidaBase();
            dropavel = drop1.get();
            break;
        }
        case 2: {
            DropavelMunicao drop2 = DropavelMunicao();
            dropavel = drop2.get();
            break;
        }
    }
    return dropavel;
}
