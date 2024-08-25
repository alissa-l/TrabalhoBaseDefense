#ifndef TRABALHOBASEDEFENSE_PROJETIL_HPP
#define TRABALHOBASEDEFENSE_PROJETIL_HPP


#include <SFML/Graphics/Sprite.hpp>
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../GameEntity.h"
#include "SFML/Graphics/Texture.hpp"

class Projetil : public GameEntity {
private:
    sf::Vector2f posicao;
    sf::Vector2f direcao;
    float rotacao;
    bool friendly;
    bool jaColidiu = false;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::RectangleShape collisionBox;
    std::string spritePath;
public:
    Projetil();

    sf::Vector2f getPosicao();
    void setPosicao(sf::Vector2f posicao);

    sf::Vector2f getDirecao();
    void setDirecao(sf::Vector2f dir);

    float getRotacao();
    void setRotacao(float rotacao1);

    bool getFriendly();
    void setFriendly(bool friendly1);

    bool getJaColidiu();
    void setJaColidiu(bool jaColidiu);

    sf::Sprite getSprite() const;
    void setSprite(sf::Sprite sprite);

    sf::Texture getTexture() const;
    void setTexture(sf::Texture texture);

    sf::RectangleShape getCollisionBox() const;
    void setCollisionBox(sf::RectangleShape collisionBox);

    std::string getSpritePath() const;
    void setSpritePath(std::string spritePath);

    void load() override;
    void draw(sf::RenderWindow &window) override;
    void update() override;

    sf::RectangleShape move(sf::RectangleShape &proj);
};


#endif //TRABALHOBASEDEFENSE_PROJETIL_HPP
