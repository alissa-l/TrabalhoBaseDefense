#ifndef TRABALHOBASEDEFENSE_HEROI_HPP
#define TRABALHOBASEDEFENSE_HEROI_HPP


#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class Heroi {

private:
    int vida;
    int municao;
    int posX;
    int posY;
    bool move;
    sf::Vector2f heroMousePos;
public:
    sf::RectangleShape sprite;

    Heroi();
    int getVida() const;
    void setVida(int vida);
    int getMunicao() const;
    void setMunicao(int municao);
    int getPosX() const;
    void setPosX(int posX);
    int getPosY() const;
    void setPosY(int posY);
    void load();
    void update(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
};


#endif //TRABALHOBASEDEFENSE_HEROI_HPP
