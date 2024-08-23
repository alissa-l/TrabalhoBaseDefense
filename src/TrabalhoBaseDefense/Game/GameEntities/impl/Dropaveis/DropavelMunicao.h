#ifndef SRC_TRABALHOBASEDEFENSEEXE_DROPAVELMUNICAO_H
#define SRC_TRABALHOBASEDEFENSEEXE_DROPAVELMUNICAO_H

#include "../Dropavel.h"
#include "DropavelMunicaoStrategy.h"

class DropavelMunicao : public Dropavel {
public:
    static Dropavel get();
};

#endif //SRC_TRABALHOBASEDEFENSEEXE_DROPAVELMUNICAO_H