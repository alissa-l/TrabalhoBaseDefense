#ifndef TRABALHOBASEDEFENSE_INIMIGO_HPP
#define TRABALHOBASEDEFENSE_INIMIGO_HPP


#include "SFML/Graphics/RectangleShape.hpp"
#include "GameEntity.hpp"

class Inimigo : public GameEntity {
private:
    sf::RectangleShape inimigoShape;
    int vida;
public:
    int getVida() const;

    void setVida(int vida);

    int getVelocidade() const;

    void setVelocidade(int velocidade);

    int getDano() const;

    void setDano(int dano);

private:
    int velocidade;
    int dano;
public:
    Inimigo(sf::RectangleShape shape, int vida, int velocidade, int dano);



    void load();
    void draw(sf::RenderWindow &window);
    void update();
};


#endif //TRABALHOBASEDEFENSE_INIMIGO_HPP
