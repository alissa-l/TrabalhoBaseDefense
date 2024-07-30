#ifndef TRABALHOBASEDEFENSE_HEROI_HPP
#define TRABALHOBASEDEFENSE_HEROI_HPP


#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "GameEntity.hpp"

class Heroi : public GameEntity {

private:
    int vida;
    int municao;
    bool move;
    sf::Vector2f heroMousePos;
    sf::RenderWindow &window;
public:
    sf::RectangleShape sprite;

    Heroi(sf::RenderWindow &mwindow) : window(mwindow) {};
    sf::RenderWindow& getWindow() {
        return window;
    }

    int getVida() const;
    void setVida(int vida);
    int getMunicao() const;
    void setMunicao(int municao);


    void load() override;
    void update() override;
    void draw() override;
    void shoot();
};


#endif //TRABALHOBASEDEFENSE_HEROI_HPP
