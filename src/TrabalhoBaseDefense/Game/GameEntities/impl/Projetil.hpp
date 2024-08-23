#ifndef TRABALHOBASEDEFENSE_PROJETIL_HPP
#define TRABALHOBASEDEFENSE_PROJETIL_HPP


#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../GameEntity.h"

class Projetil : public GameEntity {
private:
    sf::Vector2f direcao;
    sf::RectangleShape projetil;
    bool friendly;
    bool jaColidiu = false;
public:
    Projetil();

    sf::RectangleShape getProjetil();
    void setProjetil(sf::RectangleShape proj);
    sf::Vector2f getDirecao();
    void setDirecao(sf::Vector2f dir);
    bool getFriendly();
    void setFriendly(bool friendly1);
    bool getJaColidiu();
    void setJaColidiu(bool jaColidiu);
    void load() override;
    void draw(sf::RenderWindow &window) override;
    void update() override;

    sf::RectangleShape move(sf::RectangleShape &proj);
};


#endif //TRABALHOBASEDEFENSE_PROJETIL_HPP
