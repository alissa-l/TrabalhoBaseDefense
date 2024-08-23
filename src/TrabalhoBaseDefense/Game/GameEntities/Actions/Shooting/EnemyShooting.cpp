#include "EnemyShooting.h"
#include "../../../../Util/VectorUtils.hpp"

void EnemyShooting::shoot(Inimigo &inimigo, std::vector<Projetil> &projeteis, sf::Vector2f &direcao) {
    Projetil proj = Projetil();

    proj.setFriendly(false);

    proj.setDirecao(direcao);


    sf::RectangleShape projShape = sf::RectangleShape(sf::Vector2f(10, 10));
    projShape.setFillColor(sf::Color::Red);
    projShape.setPosition(inimigo.getPosicao());

    proj.setProjetil(projShape);

    projeteis.push_back(proj);
}
