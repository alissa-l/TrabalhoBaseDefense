#ifndef TRABALHOBASEDEFENSE_INIMIGO_HPP
#define TRABALHOBASEDEFENSE_INIMIGO_HPP


#include "SFML/Graphics/RectangleShape.hpp"
#include "../GameEntity.h"
#include "Heroi.hpp"

class Inimigo : public GameEntity {
private:
    sf::RectangleShape inimigoShape;
    sf::RectangleShape colisionBox;
    int vida;
    float velocidade;
    int dano;
    std::string nome;
    sf::Vector2f posicao;
    sf::Vector2f direcao;
    double chanceSpawn;
    bool stopMovingX;
    bool stopMovingY;
    int lastShot = 0;
public:

    /*
     * Construtor padrão
     */
    Inimigo();

    /*
     * Construtor com parametros
     * @param shape
     * @param vida
     * @param velocidade
     * @param dano
     * @param colisionBoxSize
     */
    Inimigo(sf::RectangleShape shape, int vida, float velocidade, int dano, sf::Vector2f colisionBoxSize, std::string nome, double chanceSpawn1);

    /**
     * Carrega o inimigo
     */
    void load();

    /**
     * Desenha o inimigo
     * @param window
     */
    void draw(sf::RenderWindow &window);

    /**
     * Atualiza o inimigo
     */
    void update();

    /**
     * Atualiza a direção do inimigo
     */
    void updateDirecao(std::vector<Heroi> &herois);

    /**
     * Getters e Setters
     */
    ///@{
    sf::RectangleShape getColisionBox() const;
    void setColisionBox(const sf::RectangleShape &colisionBox1);

    int getVida() const;
    void setVida(int vida);

    float getVelocidade() const;
    void setVelocidade(float velocidade);

    int getDano() const;
    void setDano(int dano);

    std::string &getNome();
    void setNome(const std::string &nome);

    const sf::Vector2f &getPosicao() const;
    void setPosicao(const sf::Vector2f &posicao);

    const sf::Vector2f &getDirecao() const;
    void setDirecao(const sf::Vector2f &direcao);

    double getChanceSpawn() const;

    bool isStopMovingX() const;
    void setStopMovingX(bool stopMoving);

    bool isStopMovingY() const;
    void setStopMovingY(bool stopMoving);

    int getLastShot() const;
    void setLastShot(int lastShot1);
    ///@}
};


#endif //TRABALHOBASEDEFENSE_INIMIGO_HPP
