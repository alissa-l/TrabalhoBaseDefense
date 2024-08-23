#ifndef SRC_TRABALHOBASEDEFENSE_GAME_H
#define SRC_TRABALHOBASEDEFENSE_GAME_H


#include "SFML/Graphics/RenderWindow.hpp"
#include "../Logger/Logger.hpp"
#include "GameEntities/impl/Inimigo.h"

class Game {
private:

    /**
     * Setup inicial do jogo
     */
    void setup();

    /**
     * Metodo principal de update do jogo
     * @param window
     */
    void update(sf::RenderWindow &window);

    /**
     * Metodo principal de desenho do jogo
     * @param window
     */
    void draw(sf::RenderWindow &window);

    /**
     * Desenha os textos do jogo
     * @param window
     */
    void drawText(sf::RenderWindow &window);

    /**
     * Tela de game over
     * @param window
     */
    void gameOverScreen(sf::RenderWindow &window);

    /**
     * Carrega as variaveis que precisar nos mapas correspondentes
     */
    void loadVars();

    /**
     * Aumenta a dificuldade do jogo
     */
    void increaseDifficulty();

    /**
     * Carrega os inimigos
     */
    void loadEnemies();

    /**
     * Update dos herois
     */
    static void updateHeroi(sf::RenderWindow &window);

    /**
     * Update dos inimigos
     */
    static void updateInimigos();

    /**
     * Update dos projeteis
     */
    static void updateProjetil();

    /**
     * Update round
     */
    void updateRounds();

public:
    void run();

    void calculateColisions();
};


#endif //SRC_TRABALHOBASEDEFENSE_GAME_H
