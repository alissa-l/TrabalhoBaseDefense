#ifndef TRABALHOBASEDEFENSE_GAMEENTITY_HPP
#define TRABALHOBASEDEFENSE_GAMEENTITY_HPP


#include "SFML/Graphics/RenderWindow.hpp"

/**
 * Classe baseShape para entidades do jogo
 * Métodos virtuais para carregar, desenhar e atualizar a entidade
 */
class GameEntity {
public:
    /**
     * Método para carregar a entidade
     */
    virtual void load() {}

    /**
     * Método para desenhar a entidade
     * @param window Janela do jogo
     */
    virtual void draw(sf::RenderWindow &window) {}

    /**
     * Método para atualizar a entidade
     */
    virtual void update() {}
};


#endif //TRABALHOBASEDEFENSE_GAMEENTITY_HPP
