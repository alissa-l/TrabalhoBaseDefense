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
    static std::random_device rd;
    static std::mt19937 gen(rd());
    gen.seed(std::random_device()());
    std::uniform_int_distribution<> dis(0, 2);

    int random = dis(gen);

    // Retorna um dropavel aleatorio
    Dropavel dropavel;
    switch (random) {
        case 0: {
            DropavelVidaHeroi drop0;
            dropavel = drop0.get();
            break;
        }
        case 1: {
            DropavelVidaBase drop1;
            dropavel = drop1.get();
            break;
        }
        case 2: {
            DropavelMunicao drop2;
            dropavel = drop2.get();
            break;
        }
    }
    return dropavel;
}
