#ifndef SRC_TRABALHOBASEDEFENSEEXE_INIMIGOCOMUM_H
#define SRC_TRABALHOBASEDEFENSEEXE_INIMIGOCOMUM_H

#include <map>
#include "../Inimigo.h"

class InimigoComum : Inimigo {
public:
    static Inimigo get(std::map<std::string, double> variables);
};

#endif //SRC_TRABALHOBASEDEFENSEEXE_INIMIGOCOMUM_H
