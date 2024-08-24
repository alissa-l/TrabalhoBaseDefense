// DropavelMunicaoStrategy.h
#ifndef SRC_TRABALHOBASEDEFENSEEXE_DROPAVELMUNICAOSTRATEGY_H
#define SRC_TRABALHOBASEDEFENSEEXE_DROPAVELMUNICAOSTRATEGY_H

#include "IDropavelStrategy.h"
#include "../Heroi.hpp"
#include "../Base.hpp"

class DropavelMunicaoStrategy : public IDropavelStrategy {
public:
    void effectImpl(Base &base, Heroi &heroi) override {
        heroi.setMunicao(heroi.getMunicao() + 2);
    }
};

#endif //SRC_TRABALHOBASEDEFENSEEXE_DROPAVELMUNICAOSTRATEGY_H