#ifndef TRABALHOBASEDEFENSE_HEROI_HPP
#define TRABALHOBASEDEFENSE_HEROI_HPP


#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../GameEntity.h"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Audio/Sound.hpp"

class Heroi : public GameEntity {

private:
    int vida;
    int municao;
    bool move = false;
    sf::Vector2f heroMousePos;
    sf::RectangleShape colisionBox;
public:
    sf::RectangleShape sprite;

    Heroi();


    int getVida() const;
    void setVida(int vida);
    int getMunicao() const;
    void setMunicao(int municao);
    sf::RectangleShape getColisionBox() const;
    void setColisionBox(sf::RectangleShape colisionBox);


    void load() override;
    void update(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window) override;
    void shoot();
};


#endif //TRABALHOBASEDEFENSE_HEROI_HPP
