#ifndef SRC_TRABALHOBASEDEFENSEEXE_COLISOES_H
#define SRC_TRABALHOBASEDEFENSEEXE_COLISOES_H


#include "SFML/Graphics/RectangleShape.hpp"
#include "../GameEntities/impl/Heroi.hpp"
#include "../GameEntities/impl/Inimigo.h"
#include "../GameEntities/impl/Projetil.h"
#include "../GameEntities/impl/Base.hpp"
#include "../GameEntities/impl/Dropavel.h"

class Colisoes {
public:
    /**
     * Verifica se houve colisão entre o heroi e o inimigo
     * @param heroi
     * @param inimigo
     * @return
     */
    static bool colide(Heroi &heroi, Inimigo &inimigo);

    /**
     * Verifica se houve colisão entre o inimigo e o projetil
     * @param inimigo
     * @param projetil
     * @return
     */
    static bool colide(Inimigo &inimigo, std::vector<Projetil> &projeteis);

    /**
     * Verifica se houve colisão entre o heroi e o projetil
     * @param heroi
     * @param projeteis
     * @return
     */
    static bool colide(Heroi &heroi, std::vector<Projetil> &projeteis);

    /**
     * Verifica se houve colisão entre o inimigo e a baseShape
     * @param inimigo
     * @param base
     * @return
     */
    static bool colide(Inimigo &inimigo, Base &base);

    /**
     * Verifica se houve colisão entre o projetil e a baseShape
     * @param projetil
     * @param base
     * @return
     */
    static bool colide(Projetil &projetil, Base &base);

    /**
     * Verifica se um projeto colidiu com outro projetil
     */
    static bool colide(Projetil &projetil, Projetil &projetil2);

    /**
     * Verifica se houve colisão entre um projetil e um dropavel
     */
    static bool colide(Heroi &heroi, Dropavel &dropavel);
};


#endif //SRC_TRABALHOBASEDEFENSEEXE_COLISOES_H
