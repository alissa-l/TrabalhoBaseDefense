#ifndef SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDAHEROISTRATEGY_HPP
#define SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDAHEROISTRATEGY_HPP


#include "../Heroi.hpp"
#include "IDropavelStrategy.h"
#include "../Base.hpp"

class DropavelVidaHeroiStrategy : public IDropavelStrategy {
public:
    void effectImpl(Base &base, Heroi &heroi) override {
        heroi.setVida(heroi.getVida() + 5);
    }
};


#endif //SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDAHEROISTRATEGY_HPP
