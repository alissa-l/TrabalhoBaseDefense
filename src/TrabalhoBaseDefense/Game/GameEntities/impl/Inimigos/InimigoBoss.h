#ifndef SRC_TRABALHOBASEDEFENSEEXE_INIMIGOBOSS_H
#define SRC_TRABALHOBASEDEFENSEEXE_INIMIGOBOSS_H

#include <map>
#include "../Inimigo.h"

/**
 * Classe que representa um inimigo boss
 */
class InimigoBoss {
public:
    /**
     * Retorna um inimigo boss
     * @return
     */
    static Inimigo get(std::map<std::string, double> properties);

};


#endif //SRC_TRABALHOBASEDEFENSEEXE_INIMIGOBOSS_H
