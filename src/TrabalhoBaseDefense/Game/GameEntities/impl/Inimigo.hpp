#ifndef TRABALHOBASEDEFENSE_INIMIGO_HPP
#define TRABALHOBASEDEFENSE_INIMIGO_HPP


#include "SFML/Graphics/RectangleShape.hpp"
#include "../GameEntity.h"

class Inimigo : public GameEntity {
private:
    sf::RectangleShape inimigoShape;
    int vida;
    float velocidade;
    int dano;

public:
    Inimigo(sf::RectangleShape shape, int vida, int velocidade, int dano);


    const sf::RectangleShape &getInimigoShape() const;

    void setInimigoShape(const sf::RectangleShape &inimigoShape);

    int getVida() const;

    void setVida(int vida);

    float getVelocidade() const;

    void setVelocidade(float velocidade);

    int getDano() const;

    void setDano(int dano);




    void load();
    void draw(sf::RenderWindow &window);
    void update();
};


#endif //TRABALHOBASEDEFENSE_INIMIGO_HPP
