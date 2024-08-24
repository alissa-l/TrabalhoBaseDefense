#include "EnemyShooting.h"
#include "../../../../Util/VectorUtils.hpp"

void EnemyShooting::shoot(Inimigo &inimigo, std::vector<Projetil> &projeteis, sf::Vector2f &direcao) {
    Projetil proj = Projetil();

    proj.setFriendly(false);

    proj.setDirecao(direcao);

    std::string path = "resources/sprites/Laser1.png";
    proj.setSpritePath(path);

    sf::Vector2f collisionBoxSize = sf::Vector2f(10, 10);
    proj.setCollisionBox(sf::RectangleShape(collisionBoxSize));
    proj.setPosicao(inimigo.getPosicao());

    proj.load();
    projeteis.push_back(proj);
}
