#ifndef SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDAHEROISTRATEGY_H
#define SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDAHEROISTRATEGY_H


#include "../Heroi.hpp"
#include "IDropavelStrategy.h"

class DropavelVidaHeroiStrategy : public IDropavelStrategy {
public:
    void effectImpl(void* t) override {
        auto* obj = static_cast<Heroi*>(t);
        obj->setVida(obj->getVida() + 10);
    }
};


#endif //SRC_TRABALHOBASEDEFENSEEXE_DROPAVELVIDAHEROISTRATEGY_H
