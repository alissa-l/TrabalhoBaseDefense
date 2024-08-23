#ifndef SRC_TRABALHOBASEDEFENSEEXE_INIMIGORAPIDO_H
#define SRC_TRABALHOBASEDEFENSEEXE_INIMIGORAPIDO_H

#include <map>
#include "../Inimigo.h"

class InimigoRapido {
public:
    static Inimigo get(std::map<std::string, double> properties);
};


#endif //SRC_TRABALHOBASEDEFENSEEXE_INIMIGORAPIDO_H
