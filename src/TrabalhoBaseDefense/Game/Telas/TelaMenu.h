#ifndef SRC_TRABALHOBASEDEFENSEEXE_TELAMENU_H
#define SRC_TRABALHOBASEDEFENSEEXE_TELAMENU_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "../../Logger/Logger.hpp"

/**
 * Classe que representa a tela do menu
 */
class TelaMenu {
public:
    /**
     * Tela do menu
     * @param window
     * @param logger
     * @param dificuldade
     */
    static void menuScreen(sf::RenderWindow &window, Logger &logger, int &dificuldade);

    /**
     * Seleciona a dificuldade
     * @param window
     * @param logger
     * @param dificuldade
     */
    static void selectDificuldade(sf::RenderWindow &window, Logger &logger, int &dificuldade);
};


#endif //SRC_TRABALHOBASEDEFENSEEXE_TELAMENU_H
