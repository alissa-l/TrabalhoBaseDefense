#ifndef SRC_TRABALHOBASEDEFENSEEXE_GAMEENEMYUTILS_H
#define SRC_TRABALHOBASEDEFENSEEXE_GAMEENEMYUTILS_H

#include <vector>
#include "../GameEntities/impl/Inimigo.h"
#include "../GameEntities/impl/Projetil.h"
#include "../GameEntities/impl/Dropavel.h"
#include "../GameEntities/impl/Base.hpp"

/**
 * Classe guarda os comportamentos especificos da etapa de update e colisões dos inimigos
 */
class GameEnemyUtils {
public:

    /**
     * Atualiza a direção dos inimigos
     * Também chama inimigo.update()
     */
    static void updateDirecaoInimigos(std::vector<Inimigo> &inimigos, std::vector<Heroi> &herois);

    /**
     * Dropa um item aleatorio no lugar do inimigo morto
     * @param inimigo
     * @param dropaveis
     */
    static void droparItem(const Inimigo &inimigo, std::vector<Dropavel> &dropaveis);

    /**
     * Remove os inimigos mortos da lista de inimigos <br>
     * Spawna um dropavel aleatorio no lugar do inimigo morto
     * @param inimigos
     * @param dropaveis
     * @param totalInimigosMortos
     * @param totalInimigosMortosCalculo
     */
    static void
    limparInimigos(std::vector<Inimigo> &inimigos, std::vector<Dropavel> &dropaveis, int &totalInimigosMortos,
                   int &totalInimigosMortosCalculo);

    /**
     * Atira na baseShape
     * @param inimigos
     * @param projeteis
     * @param clock
     * @param shootingFrequency
     * @param base
     */
    static void tiroInimigos(std::vector<Inimigo> &inimigos, std::vector<Projetil> &projeteis, sf::Clock &clock,
                             double shootingFrequency, Base &base);


};


#endif //SRC_TRABALHOBASEDEFENSEEXE_GAMEENEMYUTILS_H
