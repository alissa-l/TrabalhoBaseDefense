#ifndef SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDABASESTRATEGY_H
#define SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDABASESTRATEGY_H

#include "IDropavelStrategy.h"
#include "../Base.hpp"

class DropavelVidaBaseStrategy : public IDropavelStrategy {
public:
    void effectImpl(Base &base, Heroi &heroi) override {
        base.setVida(base.getVida() + 30);
    }

};

#endif //SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDABASESTRATEGY_H
