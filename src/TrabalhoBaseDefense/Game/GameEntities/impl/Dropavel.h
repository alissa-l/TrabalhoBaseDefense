#ifndef SRC_TRABALHOBASEDEFENSEEXE_DROPAVEL_H
#define SRC_TRABALHOBASEDEFENSEEXE_DROPAVEL_H


#include "../GameEntity.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "Dropaveis/IDropavelStrategy.h"

class Dropavel : GameEntity {
private:

    sf::RectangleShape dropavelShape;
    sf::Vector2f posicao;
    int tempoVida{};

    IDropavelStrategy *strategy;

public:
    Dropavel();
    Dropavel(sf::RectangleShape shape1, sf::Vector2f posicao1, int tempoVida1);


    void draw(sf::RenderWindow &window) override;

    void update() override;

    template<typename T>
    void effect(T &t) {
        strategy->effectImpl(static_cast<void*>(&t));
    }

    sf::RectangleShape getDropavelShape() const;

    void setDropavelShape(sf::RectangleShape dropavelShape);

    sf::Vector2f getPosicao() const;

    void setPosicao(sf::Vector2f posicao);

    int getTempoVida() const;

    void setTempoVida(int tempoVida);

    void setStrategy(IDropavelStrategy *strategy);
};


#endif //SRC_TRABALHOBASEDEFENSEEXE_DROPAVEL_H
