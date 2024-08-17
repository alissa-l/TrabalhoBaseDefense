#include "HeroShooting.h"
#include "../../../../Util/VectorUtils.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Audio/Sound.hpp"
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
    sf::Vector2f direcaoReal = VectorUtils::calcularDirecao(heroi.sprite.getPosition(), direcao);

    proj.setDirecao(direcaoReal);

    heroi.setMunicao(heroi.getMunicao() - 1);

    sf::RectangleShape projShape = sf::RectangleShape(sf::Vector2f(10, 10));
    projShape.setFillColor(sf::Color::Black);
    projShape.setPosition(heroi.sprite.getPosition());

    proj.setProjetil(projShape);

    projeteis.push_back(proj);
    shoot = false;

}
