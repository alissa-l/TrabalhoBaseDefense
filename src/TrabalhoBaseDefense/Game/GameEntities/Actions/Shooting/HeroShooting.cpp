#include <valarray>
#include <iostream>
#include "HeroShooting.h"
#include "../../../../Util/VectorUtils.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

/**
 * Tiro do heroi
 * Cria um projetil e adiciona na lista de projeteis
 * @param shoot
 * @param heroi
 * @param projeteis
 * @param direcao
 */
void HeroShooting::shoot(bool &shoot, Heroi &heroi, std::vector<Projetil> &projeteis, sf::Vector2f &direcao) {

    if(heroi.getMunicao() <= 0) {
        return;
    }

    Projetil proj = Projetil();

    proj.setFriendly(true);
    sf::Vector2f origemReal = sf::Vector2f (heroi.getPosicao().x, heroi.getPosicao().y + 50);
    sf::Vector2f direcaoReal = VectorUtils::calcularDirecao(heroi.getPosicao(), direcao);

    proj.setPosicao(origemReal);
    proj.setDirecao(direcaoReal);

    heroi.setMunicao(heroi.getMunicao() - 1);

    std::string path = "resources/sprites/FLECHA1.png";
    proj.setSpritePath(path);

    sf::Vector2f collisionBoxSize = sf::Vector2f(20, 20);
    proj.setCollisionBox(sf::RectangleShape(collisionBoxSize));
    float angulo = std::atan2(direcao.y - heroi.getPosicao().y, direcao.x - heroi.getPosicao().x) * 180 / M_PI;
    proj.setRotacao(angulo + 90);

    proj.load();

    projeteis.push_back(proj);
    shoot = false;

}
