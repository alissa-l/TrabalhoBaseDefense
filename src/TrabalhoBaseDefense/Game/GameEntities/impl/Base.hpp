#ifndef TRABALHOBASEDEFENSE_BASE_HPP
#define TRABALHOBASEDEFENSE_BASE_HPP


#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../GameEntity.h"

class Base : public GameEntity {
private:
    sf::RectangleShape baseShape;

    int vida{};
public:
    Base();
    const sf::RectangleShape &getBase() const;

    void setBase(const sf::RectangleShape &base);

    int getVida() const;

    void setVida(int vida);

    Base(int vida, sf::RectangleShape base);

    void load() override;
    void draw(sf::RenderWindow &window) override;
    void update() override;
};


#endif //TRABALHOBASEDEFENSE_BASE_HPP
