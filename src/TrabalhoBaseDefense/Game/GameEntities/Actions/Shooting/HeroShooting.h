#ifndef SRC_TRABALHOBASEDEFENSE_HEROSHOOTING_H
#define SRC_TRABALHOBASEDEFENSE_HEROSHOOTING_H

#include <vector>
#include "../../impl/Heroi.hpp"
#include "../../impl/Projetil.h"

class HeroShooting {
public:
    static void shoot(bool &shoot, Heroi &heroi, std::vector<Projetil> &projeteis, sf::Vector2f &direcao);
};


#endif //SRC_TRABALHOBASEDEFENSE_HEROSHOOTING_H
