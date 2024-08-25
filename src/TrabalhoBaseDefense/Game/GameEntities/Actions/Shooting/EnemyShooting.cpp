#include <cmath>
#include "EnemyShooting.h"
#include "../../../../Util/VectorUtils.hpp"

void EnemyShooting::shoot(Inimigo &inimigo, std::vector<Projetil> &projeteis, sf::Vector2f &direcao) {
    Projetil proj = Projetil();

    proj.setFriendly(false);

    proj.setDirecao(direcao);

    std::string path = "resources/sprites/Laser1.png";
    proj.setSpritePath(path);



    sf::Vector2f collisionBoxSize = sf::Vector2f(20, 20);
    proj.setCollisionBox(sf::RectangleShape(collisionBoxSize));

    sf::Vector2f origemReal = sf::Vector2f (inimigo.getPosicao().x, inimigo.getPosicao().y + 50);

    proj.setPosicao(origemReal);
    float angulo = std::atan2(direcao.y - inimigo.getPosicao().y, direcao.x - inimigo.getPosicao().x) * 180 / M_PI;
    proj.setRotacao(angulo);

    proj.load();
    projeteis.push_back(proj);
}
