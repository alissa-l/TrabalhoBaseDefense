#ifndef SRC_TRABALHOBASEDEFENSEEXE_INIMIGOFORTIFICADO_H
#define SRC_TRABALHOBASEDEFENSEEXE_INIMIGOFORTIFICADO_H

#include "../../../Variables/EnemyVariables.hpp"
#include "../Inimigo.h"

/**
 * Classe que representa um inimigo fortificado
 */
class InimigoFortificado {
public:
    /**
     * Retorna um inimigo fortificado
     * @return inimigo fortificado
     */
    static Inimigo get(std::map<std::string, double> properties);
};


#endif //SRC_TRABALHOBASEDEFENSEEXE_INIMIGOFORTIFICADO_H
