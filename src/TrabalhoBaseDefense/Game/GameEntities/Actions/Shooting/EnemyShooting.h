#ifndef SRC_TRABALHOBASEDEFENSEEXE_ENEMYSHOOTING_H
#define SRC_TRABALHOBASEDEFENSEEXE_ENEMYSHOOTING_H


#include <vector>
#include "../../impl/Inimigo.h"
#include "../../impl/Projetil.hpp"

/**
 * Classe que representa a ação de atirar do heroi<br>
 */
class EnemyShooting {
public:
    /**
     * cria um projetil e adiciona no vetor de projeteis
     * @param shoot
     * @param inimigo
     * @param projeteis
     * @param direcao
     */
    static void shoot(Inimigo &inimigo, std::vector<Projetil> &projeteis, sf::Vector2f &direcao);
};


#endif //SRC_TRABALHOBASEDEFENSEEXE_ENEMYSHOOTING_H
